using Godot;

public partial class BTAttack : BTNode
{
	public override BTState Tick(Enemy enemy, double delta)
	{
		// Check attack conditions
		if (!enemy.CanAttack || enemy.Player == null || !GodotObject.IsInstanceValid(enemy.Player))
			return BTState.Failure;

		// hault movement 
		Vector2 vel = enemy.Velocity; 
		vel.X = 0; 
		enemy.Velocity = vel;

		// Compute direction to player
		Vector2 direction = (enemy.Player.GlobalPosition - enemy.GlobalPosition).Normalized();

		// Add upward tilt
		Vector2 upwardTilt = new Vector2(0, -0.1f);
		direction = (direction + upwardTilt).Normalized();

		// Spawn projectile at enemy position + a small offset toward the player
		Spell newSpell = enemy.Spell.Instantiate<Spell>();
		newSpell.GlobalPosition = enemy.GlobalPosition + direction * 20f;

		// Add projectile to the scene
		enemy.GetParent().AddChild(newSpell);

		// Apply impulse TOWARD the player
		newSpell.ApplyCentralImpulse(direction * newSpell.FiringForce);

		// Set cooldown properly
		enemy.attackCooldown =3.0f ;

		GD.Print("Enemy attacks!");

		return BTState.Success;
	}
}
