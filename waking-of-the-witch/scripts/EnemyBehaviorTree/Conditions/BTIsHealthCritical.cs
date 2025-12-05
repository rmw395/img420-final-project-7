using Godot;

public partial class BTIsHealthCritical : BTNode
{
	public override BTState Tick(Enemy enemy, double delta)
	{
		if ((float)enemy.Call("get_health") / enemy.MaxHealth <= 0.3f) // adjust threshold
			return BTState.Success;
		return BTState.Failure;
	}
}
