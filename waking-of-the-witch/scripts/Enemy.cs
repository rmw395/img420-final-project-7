using Godot;
using System;

public partial class Enemy : CharacterBody2D
{
	// target variables
	public CharacterController Player;

	public AnimatedSprite2D EnemySprite;

	// behavior tree variable
	private BTNode _behaviorTreeRoot;

	// health variables
	[Export] public float MaxHealth = 100f;
	public float HealthRatio;
	public bool IsDead => (float)Call("get_health") <= 0;

	// attack variables
	[Export]
	public PackedScene Spell;
	public Area2D attackArea;
	public double attackCooldown = 0;
	public bool CanAttack;
	public bool isAttacking;

	// detection variables
	private Area2D detectionArea;
	
	private ShaderMaterial _shaderMat;
	private Timer _flashTimer;


	public float Speed;

	public override void _Ready()
	{   
		MaxHealth = (float)Call("get_max_health");

		EnemySprite = GetNode<AnimatedSprite2D>("EnemySprite");
		EnemySprite.Play("idle");

		_shaderMat = (ShaderMaterial)GetNode<AnimatedSprite2D>("EnemySprite").Material;
		_flashTimer = GetNode<Timer>("FlashTimer");
			if (_shaderMat != null)
				_shaderMat.SetShaderParameter("flash_color", new Vector4(1.0f, 0.3f, 0.2f, 1.0f));

		// Get Nodes
			// behavior tree
		_behaviorTreeRoot = GetNode<BTNode>("BehaviorTree");
		GD.Print("Enemy Behavior Tree Initialized");

			// detection area for chasing
		detectionArea = GetNode<Area2D>("DetectionArea");
		detectionArea.Monitorable = true;
			// when it is entered, call function
		detectionArea.BodyEntered += OnDetectionAreaEntered;
			// when it is exited, stop function
		detectionArea.BodyExited += OnDetectionAreaExited;
			// detection area for attacking
		attackArea = GetNode<Area2D>("AttackArea");
			// when it is entered, call function
		attackArea.BodyEntered += OnAttackAreaBodyEntered;
			// when it is exited, stop function
		attackArea.BodyExited += OnAttackAreaBodyExited;

		Speed = (float)Call("get_max_speed").As<double>();

	}

	// function that happens every second
   public override void _PhysicsProcess(double delta)
	{
		
		if (_shaderMat != null)
			_shaderMat.SetShaderParameter("opacity", _flashTimer.TimeLeft / _flashTimer.WaitTime);
			
		Vector2 velocity = Velocity;

		// Apply gravity first
		if (!IsOnFloor())
			velocity += GetGravity() * (float)delta;

		Velocity = velocity;
		UpdateSprite();

		// Behavior tree updates Velocity.X
		if (_behaviorTreeRoot != null)
			_behaviorTreeRoot.Tick(this, delta);

		// Attack cooldown
		if (attackCooldown > 0)
			attackCooldown -= delta;

		// Update health
		HealthRatio = (float)Call("get_health") / MaxHealth;

		// Only move ONCE
		MoveAndSlide();
	}


	// when the detection area is entered, set player 
	private void OnDetectionAreaEntered(Node2D body)
	{
		GD.Print("DETECTION AREA DETECTED: ", body);
		if (body is CharacterController p && GodotObject.IsInstanceValid(p))
		{
			Player = p;
		}
	}
	private void OnDetectionAreaExited(Node2D body)
	{
		if (body == Player)
		{
			Player = null;
		}
	}

	// when attack area is entered,
	private void OnAttackAreaBodyEntered(Node2D body)
	{   
		GD.Print("ATTACK AREA DETECTED: ", body);
		// if the body entering is a player
		if (body is CharacterController p)
		{
			 CanAttack = true;
		}
		else
		{
			CanAttack = false;
		}
	}
	private void OnAttackAreaBodyExited(Node2D body)
	{
		if(body is CharacterController p)
		{
			CanAttack = false;
		}
	}

	private void UpdateSprite() 
	{
		if (EnemySprite == null) return;
		
		else if (Velocity.X != 0)
		{
			EnemySprite.Play("walk");
		}
		else
		{
			EnemySprite.Play("idle");
		}
		if (Velocity.X < 0) 
		{
			EnemySprite.FlipH = true;
		}
		if (Velocity.X > 0) 
		{
			EnemySprite.FlipH = false;
		}
	}
	public void DoDamageEffects(bool bypass)
	{
		// if (CurrentHealth >= 20)
		// {
		// 	damageTaken.Play();
		// }
		_flashTimer.Start();
		if ((float)Call("get_health") <= 0)
		{
			Die();
		}
	}

	private void Die()
	{
		// _anim.Play("die");
		// killed.Play();
		GD.Print("Enemy died!");

		GetTree().CreateTimer(2f).Timeout += () => QueueFree();
	}

	// used to update health bar (USED IN HealthBar.cs)
	public float GetMaxHealth()
	{
		return MaxHealth;
	}
	public float GetCurrentHealth()
	{
		return (float)Call("get_health");
	}
}
