using Godot;

public partial class BTIsHealthCritical : BTNode
{
    public override BTState Tick(Enemy enemy, double delta)
    {
        if (enemy.CurrentHealth / enemy.MaxHealth <= 0.3f) // adjust threshold
            return BTState.Success;
        return BTState.Failure;
    }
}