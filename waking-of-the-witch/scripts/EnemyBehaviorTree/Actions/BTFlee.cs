using Godot;

public partial class BTFlee : BTNode
{
    public override BTState Tick(Enemy enemy, double delta)
    {
        // Health check
        if (enemy.HealthRatio > 0.3f)
            return BTState.Failure;

        if (enemy.Player == null || !GodotObject.IsInstanceValid(enemy.Player))
            return BTState.Failure;

        // Horizontal flee direction only
        float dirX = Mathf.Sign(enemy.GlobalPosition.X - enemy.Player.GlobalPosition.X);

        Vector2 vel = enemy.Velocity;
        vel.X = dirX * enemy.Speed;
        enemy.Velocity = vel;

        return BTState.Running;
    }
}

