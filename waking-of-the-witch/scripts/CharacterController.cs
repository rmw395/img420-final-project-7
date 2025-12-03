using Godot;
using System;

public partial class CharacterController : CharacterBody2D
{
	[Signal]
	public delegate void SetRespawnEventHandler(Vector2 position);
	[Signal]
	public delegate void RespawnEventHandler();
	
	[Export]
	public float DashSpeed;
	[Export]
	public float AirAccelerationMult;
	[Export]
	public float JumpSpeed;
	[Export]
	public float BurstJumpSpeed;
	[Export]
	public float Gravity;
	[Export]
	public float SlowFallMult;
	
	public double TimePassed;
	public AnimatedSprite2D PlayerSprite;
	
	private Vector2 _bufferSpeed;
	private bool _slowFalling;
	private bool _wasOnFloor;
	private bool _jumping;
	private bool _dashing;
	private bool _isAttacking = false;
	private ShaderMaterial _shaderMat;
	private Timer _invulnerabilityTimer;
	private Timer _dashTimer;
	private Timer _dashCooldown;
	private Timer _jumpTimer;
	private Timer _coyoteTimer;
	private Timer _flashTimer;
	private Timer _attackTimer;
	private Vector2 _respawnPoint;
	
	public override void _Ready() 
	{
		try 
		{
			// CRITICAL FIX 1: Force C++ to calculate stats (final = base * mult) 
			// before we try to read them. Fixes race condition.
			Call("update_values");

			// CRITICAL FIX 2: Safe casting. 
			// Call returns Variant. We cast to double first (native type), then float.
			float currentHealth = (float)Call("get_health").As<double>();
			
			if (currentHealth <= 0)
			{
				float maxHealth = (float)Call("get_max_health").As<double>();
				Call("set_health", maxHealth);
			}

			_bufferSpeed = Vector2.Zero;
			_slowFalling = false;
			_dashing = false; 
			
			// Safety check for nodes
			PlayerSprite = GetNodeOrNull<AnimatedSprite2D>("PlayerSprite");
			if (PlayerSprite == null) 
			{
				GD.PrintErr("CharacterController: 'PlayerSprite' node not found!");
				return;
			}

			_shaderMat = (ShaderMaterial)PlayerSprite.Material;
			if (_shaderMat != null)
				_shaderMat.SetShaderParameter("flash_color", new Vector4(1.0f, 0.3f, 0.2f, 1.0f));
			
			_invulnerabilityTimer = GetNode<Timer>("InvulnerabilityTimer");
			_dashTimer = GetNode<Timer>("DashTimer");
			_dashCooldown = GetNode<Timer>("DashCooldown");
			_jumpTimer = GetNode<Timer>("JumpTimer");
			_coyoteTimer = GetNode<Timer>("CoyoteTimer");
			_flashTimer = GetNode<Timer>("FlashTimer");
			_attackTimer = GetNode<Timer>("AttackCooldown");
			_respawnPoint = GlobalPosition;
			
		}
		catch (Exception e)
		{
			GD.PrintErr($"CRASH IN _READY: {e.Message}\n{e.StackTrace}");
		}
	}
	
	public override void _PhysicsProcess(double delta) 
	{
		if (PlayerSprite == null) return;

		TimePassed += delta;
		if (_shaderMat != null)
			_shaderMat.SetShaderParameter("opacity", _flashTimer.TimeLeft / _flashTimer.WaitTime);
		
		UpdateVelocity(delta);
		UpdateSprite();
		
		if (Input.IsActionJustPressed("attack") && _attackTimer.IsStopped())
		{
			Attack();
		}
		
		Call("move", Velocity);
	}
	
	private void UpdateVelocity(double delta) 
	{
		if (Input.IsActionPressed("dash") && _dashTimer.IsStopped() && _dashCooldown.IsStopped())
		{
			_dashing = true;
			int direction = 0;
			if (Input.IsActionPressed("left")) direction -= 1;
			if (Input.IsActionPressed("right")) direction += 1;
			
			if (direction == 0)
			{
				direction = PlayerSprite.FlipH ? -1 : 1;
			}
			Vector2 newVelocity = new Vector2(DashSpeed * direction, 0);
			Velocity = newVelocity;
			_dashTimer.Start();
		}
		
		if (_dashing)
		{
			if (!IsOnFloor())
			{
				Vector2 newVelocity = Velocity;
				newVelocity.Y += Gravity / 2 * (float)delta;
				Velocity = newVelocity;
				if (_wasOnFloor)
				{
					_coyoteTimer.Start();
					_wasOnFloor = false;
				}
			}
			else
			{
				_wasOnFloor = true;
				Vector2 newVelocity = Velocity;
				newVelocity.Y = 0;
				Velocity = newVelocity;
			}
		}
		else
		{
			Velocity = WalkingVelocity(delta);
		}
	}
	
	private Vector2 WalkingVelocity(double delta)
	{
		Vector2 newVelocity;
		newVelocity.X = HorizontalMovement(delta);
		newVelocity.Y = VerticalMovement(delta);
		return newVelocity;
	}
	
	private float HorizontalMovement(double delta)
	{
		float newVelocity = Velocity.X;
		int direction = 0;
		if (Input.IsActionPressed("left")) direction -= 1;
		if (Input.IsActionPressed("right")) direction += 1;
		
		float groundFriction = (float)Call("get_ground_friction").As<double>();
		float airFriction = (float)Call("get_air_friction").As<double>();
		float acceleration = (float)Call("get_acceleration").As<double>();
		float maxSpeed = (float)Call("get_max_speed").As<double>();
		
		float currentFriction = IsOnFloor() ? groundFriction : airFriction;
		float currentAcceleration = acceleration;
		
		float effectiveFriction = currentFriction * Math.Abs(newVelocity) / maxSpeed;
		
		if (Math.Abs(newVelocity) > maxSpeed)
		{
			currentAcceleration = 0;
		}
		
		if (!IsOnFloor())
		{
			currentAcceleration *= AirAccelerationMult;
			_wasOnFloor = false;
		}
		else
		{
			_coyoteTimer.Start();
			_wasOnFloor = true;
		}
		
		newVelocity = Mathf.Lerp(newVelocity, newVelocity + (direction * currentAcceleration - effectiveFriction * Math.Sign(Velocity.X)) * (float)delta, 0.55f);
		
		int currentMovingDirection = Math.Sign(newVelocity);
		newVelocity = Mathf.Lerp(newVelocity, newVelocity - currentMovingDirection * effectiveFriction * (float)delta, 0.55f);
		
		int newMovingDirection = Math.Sign(newVelocity);
		if (currentMovingDirection != newMovingDirection)
		{
			newVelocity = 0;
		}
		return newVelocity;
	}
	
	private float VerticalMovement(double delta)
	{
		float newVelocity = Velocity.Y;
		float currentGravity = Gravity;
		if ((IsOnFloor() || (!_coyoteTimer.IsStopped())) && Input.IsActionJustPressed("jump") && !_jumping)
		{
			_slowFalling = true;
			_jumping = true;
			_wasOnFloor = false;
			_jumpTimer.Start();
			newVelocity = -BurstJumpSpeed;
		}
		if (_slowFalling && (!(Input.IsActionPressed("jump")) || IsOnFloor()))
		{
			_slowFalling = false;
		}
		if (_slowFalling)
		{
			if (!float.IsNaN(currentGravity))
				currentGravity *= SlowFallMult;
		}
		if (_jumping)
		{
			_coyoteTimer.Stop();
			if (!(Input.IsActionPressed("jump")) || _jumpTimer.IsStopped())
			{
				_jumping = false;
				if (!(_jumpTimer.IsStopped()))
				{
					newVelocity /= 4;
				}
				_jumpTimer.Stop();
			}
			else
			{
				newVelocity = Mathf.Lerp(newVelocity, -JumpSpeed, (float)0.15);
			}
		}
		else if (!IsOnFloor())
		{
			newVelocity += currentGravity * (float)delta;
		}
		else
		{
			newVelocity = 0;
		}
		return newVelocity;
	}
	
	private void OnDashTimeout()
	{
		_dashing = false;
		_dashCooldown.Start();
	}
	
	private void UpdateSprite() 
	{
		if (PlayerSprite == null) return;
		
		if (Velocity.X < 0) 
		{
			PlayerSprite.FlipH = true;
		}
		if (Velocity.X > 0) 
		{
			PlayerSprite.FlipH = false;
		}
	}
	
	private void Attack()
	{
		return;
	}
	
	private void OnDamage(double damage, Vector2 knockback)
	{
		if (_invulnerabilityTimer.IsStopped())
		{
			GD.Print("hello?");
			_flashTimer.Start();
			
			double currentHealth = (double)Call("get_health");
			GD.Print($"Health: {currentHealth}");
			
			_invulnerabilityTimer.Start();
			if (_dashing)
			{
				_dashing = false;
				_dashTimer.Stop();
				_dashCooldown.Start();
			}
			else
			{
				if (_dashCooldown.TimeLeft < 0.2)
				{
					_dashCooldown.Start(0.2);
				}
			}
			GD.Print(knockback);
			Velocity = knockback;
			CheckHealth();
		}
	}
	
	private void CheckHealth()
	{
		float currentHealth = (float)Call("get_health").As<double>();
		if (currentHealth <= 0)
		{
			//GetParent<World>().EmitSignal("Death");
		}
	}
	
	private void OnSetRespawn(Vector2 position)
	{
		_respawnPoint = position;
	}
	
	private void OnRespawn()
	{
		GlobalPosition = _respawnPoint;
		float maxHealth = (float)Call("get_max_health").As<double>();
		Call("set_health", maxHealth);
	}
}
