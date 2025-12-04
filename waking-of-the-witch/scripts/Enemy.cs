using Godot;
using System;

public partial class Enemy : CharacterBody2D
{
	// target variables
	public CharacterController Player;

    // behavior tree variable
    private BTNode _behaviorTreeRoot;

	// health variables
    [Export] public float MaxHealth = 100f;
    public float CurrentHealth;
    public float HealthRatio;
	public bool IsDead => CurrentHealth <= 0;

	// attack variables
    private Area2D attackArea;
    private double _attackCooldown = 0;
    public bool CanAttack;

    // detection variables
    private Area2D detectionArea;

	public float Speed;

	public override void _Ready()
    {   
        // set beginning health to max
        CurrentHealth = MaxHealth;

        // _anim = GetNode<AnimatedSprite2D>("AnimatedSprite2D");
        // _anim.Play("idle");

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
		Vector2 velocity = Velocity;

		// Apply gravity first
		if (!IsOnFloor())
			velocity += GetGravity() * (float)delta;

		Velocity = velocity;

		// Behavior tree updates Velocity.X
		if (_behaviorTreeRoot != null)
			_behaviorTreeRoot.Tick(this, delta);

		// Attack cooldown
		if (_attackCooldown > 0)
			_attackCooldown -= delta;

		// Update health
		HealthRatio = CurrentHealth / MaxHealth;

		// Only move ONCE
		MoveAndSlide();
	}


    // when the detection area is entered, set player 
    private void OnDetectionAreaEntered(Node2D body)
    {
        GD.Print("DETECTED: ", body);
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
        // if the body entering is a player
        if (body is CharacterController p && _attackCooldown <= 0)
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

	public void TakeDamage(float amount)
	{
		CurrentHealth -= amount;
        GD.Print($"Enemy took {amount}. HP = {CurrentHealth}");

        // if (CurrentHealth >= 20)
		// {
		// 	damageTaken.Play();
		// }

		if (CurrentHealth <= 0)
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
        return CurrentHealth;
    }
}
