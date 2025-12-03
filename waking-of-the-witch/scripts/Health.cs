using Godot;
using System;

public partial class Health : Label
{
	Node2D parent;
	CharacterBody2D entity;
	
	override public void _Ready() {
		parent = GetParent<Node2D>();
		entity = parent.GetNode<CharacterBody2D>("Player");
	}
	
	override public void _PhysicsProcess(double delta) {
		Text = (String)entity.Call("get_health");
	}
}
