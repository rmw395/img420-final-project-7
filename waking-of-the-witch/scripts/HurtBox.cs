using Godot;
using System;

public partial class HurtBox : Area2D
{
	[Signal]
	private delegate void DamageEventHandler(float damage, Vector2 knockback, bool bypass);
	
	private void OnDamage(float damage, Vector2 knockback, bool bypass) {
		GD.Print("DamageAmount for HurtBox = ", damage);
		GetParent().EmitSignal("damage", damage, knockback, bypass);
	}
}
