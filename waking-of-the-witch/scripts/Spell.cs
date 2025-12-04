using Godot;
using System;

public partial class Spell : RigidBody2D
{
	[Export]
	public String AppliedStatusEffect;
	[Export]
	public float FiringForce;
	[Export]
	public float DamageAmount;
	
	private GodotObject _interactionManager = null;
	
	override public void _Ready() {
		_interactionManager = Engine.GetSingleton("InteractionManager");
		GD.Print("DamageAmount = ", DamageAmount);
		GetNode<HitBox>("HitBox").DamageAmount = DamageAmount;
		GD.Print("DamageAmount for HitBox = ", GetNode<HitBox>("HitBox").DamageAmount);
	}
	
	private void OnHit(Node2D enemy) {
		_interactionManager.Call("add_status_effect", enemy, AppliedStatusEffect);
		QueueFree();
	}
}
