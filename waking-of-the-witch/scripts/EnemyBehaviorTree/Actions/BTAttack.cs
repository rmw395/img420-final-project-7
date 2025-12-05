using Godot;

public partial class BTAttack : BTNode
{
	public override BTState Tick(Enemy enemy, double delta)
	{
		// Check attack conditions
		if (!enemy.CanAttack || enemy.Player == null || !GodotObject.IsInstanceValid(enemy.Player))
			return BTState.Failure;

		// Stop enemy movement during attack
		enemy.Velocity = new Vector2(0, enemy.Velocity.Y);

		// Compute direction to player (NORMALIZED)
		Vector2 direction = (enemy.Player.GlobalPosition - enemy.GlobalPosition).Normalized();

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
