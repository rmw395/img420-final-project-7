using Godot;

public partial class BTStandby : BTNode
{
	public override BTState Tick(Enemy enemy, double delta)
	{
		// hault movement
		Vector2 vel = enemy.Velocity;
		vel.X = 0;
		enemy.Velocity = vel;

		GD.Print("Enemy is on standby!");

		return BTState.Success;
	}

}
