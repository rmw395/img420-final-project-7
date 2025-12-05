using Godot;

public partial class BTChasePlayer : BTNode
{
    public override BTState Tick(Enemy enemy, double delta)
	{
		// player is assigned when detected by detection area
		if (enemy.Player == null || !GodotObject.IsInstanceValid(enemy.Player))
        {
			// if player is no longer detected, leave
			GD.Print("Chasing is cancelled");
            return BTState.Failure;
        }

		float dirX = Mathf.Sign(enemy.Player.GlobalPosition.X - enemy.GlobalPosition.X);

		Vector2 vel = enemy.Velocity;
		vel.X = dirX * enemy.Speed;
		enemy.Velocity = vel;

		//GD.Print($"Enemy chases at speed: {enemy.Speed}, velX: {enemy.Velocity.X}");

		return BTState.Success;
	}

}

