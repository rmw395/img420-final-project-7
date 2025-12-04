using Godot;

public partial class BTIsPlayerInRange : BTNode
{
    public override BTState Tick(Enemy enemy, double delta)
    {
		// when detection area is entered, player is assigned
        if (enemy.Player == null || !GodotObject.IsInstanceValid(enemy.Player))
            return BTState.Failure;

        return BTState.Success;
    }
}
