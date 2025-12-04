using Godot;
using System;

public partial class Vignette : CanvasLayer
{
	private Node2D _player;
	private Camera2D _camera;
	private ShaderMaterial _shaderMat;
	
	public override void _Ready() {
		_player = GetParent<Node2D>();
		_camera = _player.GetNode<Camera2D>("Camera2D");
		_shaderMat = (ShaderMaterial)GetNode<ColorRect>("ColorRect").Material;
	}
	
	public override void _PhysicsProcess(double delta) {
		Vector2 playerPosition = _player.GlobalPosition;
		Vector2 centerScreenPosition = _camera.GetScreenCenterPosition();
		Vector2 playerScreenPosition = (playerPosition - centerScreenPosition + GetViewport().GetVisibleRect().Size / 2) / GetViewport().GetVisibleRect().Size;
		_shaderMat.SetShaderParameter("centerPosition", playerScreenPosition);
		GD.Print(playerScreenPosition);
	}
}
