using Godot;
using System;

public partial class HitBox : Area2D
{
	[Signal]
	public delegate void HitEventHandler(Node2D enemy);
	
	[Export]
	public string EnemyGroup;
	
	public float DamageAmount;
	public float KnockbackAmount;
	
	override public void _PhysicsProcess(double delta)
	{
		foreach (Node2D area in GetOverlappingAreas()) 
		{
			if (area.IsInGroup(EnemyGroup))
			{
				Vector2 knockback = new Vector2(Mathf.Sign((area.GlobalPosition - GlobalPosition).X), -0.5f).Normalized() * KnockbackAmount;
				area.EmitSignal("Damage", DamageAmount, knockback, false);
				EmitSignal("Hit", area.GetParent());
			}
		}
	}
}
