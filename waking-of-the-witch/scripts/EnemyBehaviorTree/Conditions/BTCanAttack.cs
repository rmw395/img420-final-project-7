using Godot;

public partial class BTCanAttack : BTNode
{
    public override BTState Tick(Enemy enemy, double delta)
	{
		// double checks player is in range
		if (enemy.Player == null || !GodotObject.IsInstanceValid(enemy.Player))
			return BTState.Failure;

		// checks attack cooldown
		return enemy.CanAttack ? BTState.Success : BTState.Failure;
	}

}
