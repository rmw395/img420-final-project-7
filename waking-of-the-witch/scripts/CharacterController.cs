using Godot;
using System;
using System.Collections.Generic;

public partial class CharacterController : CharacterBody2D
{
	[Signal]
	public delegate void SetRespawnEventHandler(Vector2 position);
	[Signal]
	public delegate void RespawnEventHandler();
	[Signal]
	public delegate void EquipWeaponEventHandler(PackedScene WeaponScene);
	
	[Export]
	public int MaxHealth;
	[Export]
	public float Speed;
	[Export]
	public float DashSpeed;
	[Export]
	public float Acceleration;
	[Export]
	public float AirAccelerationMult;
	[Export]
	public float Friction;
	[Export]
	public float AirFrictionMult;
	[Export]
	public float JumpSpeed;
	[Export]
	public float BurstJumpSpeed;
	[Export]
	public float Gravity;
	[Export]
	public float SlowFallMult;
	
	public double TimePassed;
	public int Health;
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
		Health = MaxHealth;
		_bufferSpeed = Vector2.Zero;
		_slowFalling = false;
		_dashing = false; 
		PlayerSprite = GetNode<AnimatedSprite2D>("PlayerSprite");
		_shaderMat = (ShaderMaterial)PlayerSprite.Material;
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
	
	public override void _PhysicsProcess(double delta) 
	{
		TimePassed += delta;
		_shaderMat.SetShaderParameter("opacity", _flashTimer.TimeLeft / _flashTimer.WaitTime);
		UpdateVelocity(delta);
		UpdateSprite();
		if (Input.IsActionJustPressed("attack") && _attackTimer.IsStopped())
		{
			Attack();
		}
		MoveAndSlide();
	}
	
	private void UpdateVelocity(double delta) 
	{
		if (Input.IsActionPressed("dash") && _dashTimer.IsStopped() && _dashCooldown.IsStopped())
		{
			_dashing = true;
			int direction = 0;
			if (Input.IsActionPressed("left")) 
			{
				direction -= 1;
			}
			if (Input.IsActionPressed("right")) 
			{
				direction += 1;
			}
			if (direction == 0)
			{
				if (PlayerSprite.FlipH)
				{
					direction = -1;
				}
				else
				{
					direction = 1;
				}
			}
			Vector2 newVelocity = new Vector2(DashSpeed * direction, 0);
			Velocity = newVelocity;
			_dashTimer.Start();
			
			// GpuParticles2D dashTrail = DashTrailScene.Instantiate<GpuParticles2D>();
			// dashTrail.Emitting = true;
			// dashTrail.Position = PlayerSprite.Offset;
			// dashTrail.ZIndex = PlayerSprite.ZIndex - 1;
			// AddChild(dashTrail);
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
		if (Input.IsActionPressed("left"))
		{
			direction -= 1;
		}
		if (Input.IsActionPressed("right"))
		{
			direction += 1;
		}
		float currentFriction = Friction * Math.Abs(newVelocity) / Speed;
		float currentAcceleration = Acceleration;

		if (Math.Abs(newVelocity) > Speed)
		{
			currentAcceleration = 0;
		}

		if (!IsOnFloor())
		{
			currentAcceleration *= AirAccelerationMult;
			currentFriction *= AirFrictionMult;
			_wasOnFloor = false;
		}
		else
		{
			_coyoteTimer.Start();
			_wasOnFloor = true;
		}
		newVelocity = Mathf.Lerp(newVelocity, newVelocity + (direction * currentAcceleration - currentFriction * Math.Sign(Velocity.X)) * (float)delta, 0.55f);
		int currentMovingDirection = Math.Sign(newVelocity);
		newVelocity = Mathf.Lerp(newVelocity, newVelocity - currentMovingDirection * currentFriction * (float)delta, 0.55f);
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
		// if (_bufferSpeed != Vector2.Zero)
		// {
		// 	Vector2 newVelocity = Velocity;
		// 	newVelocity += _bufferSpeed;
		// 	Velocity = newVelocity;
		// 	_bufferSpeed = Vector2.Zero;
		// }
	}
	
	private void UpdateSprite() 
	{
		// Vector2 newOffset;
		// newOffset.X = 0;
		// newOffset.Y = (float)(4 * Math.Sin(TimePassed * 2.5) - 4);
		// PlayerSprite.Offset = newOffset;
		
		// if (_dashing)
		// {
		// 	PlayerSprite.SetFrame(PlayerSprite.GetSpriteFrames().GetFrameCount(PlayerSprite.Animation) - 1);
		// }
		// else
		// {
		// 	PlayerSprite.Stop();
		// 	int numFrames = PlayerSprite.GetSpriteFrames().GetFrameCount(PlayerSprite.Animation) - 1;
		// 	int newFrame = (int)Math.Floor(numFrames * (Math.Abs(Velocity.X) / Speed));
		// 	if (newFrame >= numFrames) 
		// 	{
		// 		newFrame = numFrames - 1;
		// 	}
		// 	PlayerSprite.SetFrame(newFrame);
		// }
		if (Velocity.X < 0) 
		{
			PlayerSprite.FlipH = true;
			// PlayerSprite.Animation = "walk_left";
		}
		if (Velocity.X > 0) 
		{
			PlayerSprite.FlipH = false;
			// PlayerSprite.Animation = "walk_right";
		}
	}

	private void Attack()
	{
		return;
	}
	
	private void OnDamage(float damage, Vector2 knockback)
	{
		if (_invulnerabilityTimer.IsStopped())
		{
			Health -= (int)damage;
			_flashTimer.Start();
			GD.Print(Health);
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
		if (Health <= 0)
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
	}
	
	override public void _ExitTree()
	{
		if (Health == 0)
		{
			Health = MaxHealth;
		}
	}
}
