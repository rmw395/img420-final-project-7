using Godot;

public partial class BTAttack : BTNode
{
    [Export] public float AttackRange = 40f; // set in inspector

	public override BTState Tick(Enemy enemy, double delta)
	{
		// if the enemy can attack and the player is still in the detection zone,
		if (!enemy.CanAttack || enemy.Player == null || !GodotObject.IsInstanceValid(enemy.Player))
        {
			GD.Print("Attack is canceled");
            return BTState.Failure;
        }
		
		// hault movement
		Vector2 vel = enemy.Velocity;
		vel.X = 0;
		enemy.Velocity = vel;

		GD.Print("Enemy attacks!");

		return BTState.Success;
	}

}
