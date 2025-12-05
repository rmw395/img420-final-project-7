using Godot;
using System;
using System.Collections.Generic;

public partial class World : Node2D
{
	[Signal]
	public delegate void DeathEventHandler();
	//[Signal]
	//public delegate void RemoveEnemyEventHandler(Enemy givenEnemy);
	
	public float TimePassed;
	//private PauseScreen _pauseScreen;
	//private DeathScreen _deathScreen;
	//private VictoryScreen _victoryScreen;
	//private List<Enemy> _requiredEnemies = [];
	private CollisionShape2D _cameraBounds;
	private bool _hasCameraBounds = false;
	private float _leftEdge;
	private float _rightEdge;
	private float _topEdge;
	private float _bottomEdge;
	private CharacterController _player;
	private Camera2D _playerCamera;
	private Vector2 _defaultCameraOffset;
	
	private bool _waterApplied = false;
	private GodotObject _interactionManager = null;
	
	override public void _Ready()
	{
		TimePassed = 0.0f;
		//_pauseScreen = GetNode<PauseScreen>("PauseScreen");
		//_deathScreen = GetNode<DeathScreen>("DeathScreen");
		//_victoryScreen = GetNode<VictoryScreen>("VictoryScreen");
		
		_player = GetNode<CharacterController>("Player");
		if (HasNode("CameraBounds"))
		{
			_hasCameraBounds = true;
			_cameraBounds = GetNode<CollisionShape2D>("CameraBounds/CollisionShape2D");
			Rect2 cameraRect = _cameraBounds.Shape.GetRect();
			_playerCamera = GetNode<Camera2D>("Player/PlayerCamera");
			_playerCamera.LimitLeft = (int)(_cameraBounds.GlobalPosition.X - cameraRect.Size.X / 2);
			_playerCamera.LimitRight = (int)(_cameraBounds.GlobalPosition.X + cameraRect.Size.X / 2);
			_playerCamera.LimitTop = (int)(_cameraBounds.GlobalPosition.Y - cameraRect.Size.Y / 2);
			_playerCamera.LimitBottom = (int)(_cameraBounds.GlobalPosition.Y + cameraRect.Size.Y / 2);
		}
		_interactionManager = Engine.GetSingleton("InteractionManager");
		if (_interactionManager != null && HasNode("Player"))
		{
			//_interactionManager.Call("add_status_effect", GetNode("Player"), "fire");
			//GD.Print("Fire!");
		}
	}
	
	override public void _PhysicsProcess(double delta)
	{
		TimePassed += (float)delta;
		//if (TimePassed > 1f)
		//{
			//TimePassed -= 1f;
			//GD.Print(Engine.GetFramesPerSecond());
		//}
		if (TimePassed > 1f && !_waterApplied)
		{
			_waterApplied = true;
			if (_interactionManager != null)
			{
				//GD.Print("Gas!");
				//_interactionManager.Call("add_status_effect", GetNode("Player"), "gasoline");
			}
		}
		
		//if (Input.IsActionJustPressed("pause"))
		//{
			//_pauseScreen.Pause();
		//}
		//bool win = false;
		//if (_requiredEnemies.Count == 0)
		//{
			//win = true;
		//}
		//if (win)
		//{
			//_victoryScreen.Win();
		//}
	}
	
	private void OnDeath()
	{
		GD.Print("GameOver");
		//_deathScreen.Dead();
	}
	
	//private void OnRemoveEnemy(Enemy givenEnemy)
	//{
		//if (_requiredEnemies.Contains(givenEnemy))
		//{
			//_requiredEnemies.Remove(givenEnemy);
		//}
	//}
}
