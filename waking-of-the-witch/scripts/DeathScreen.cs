using Godot;
using System;

public partial class DeathScreen : CanvasLayer
{
	override public void _Ready()
	{
	}
	
	override public void _Process(double delta)
	{
	}
	
	public void Dead()
	{
		GetTree().Paused = true;
		Show();
	}
	
	private void OnRestart()
	{
		GetTree().Paused = false;
		Hide();
		GetTree().ChangeSceneToFile("uid://cteom6ym18p1c");
	}
	
	private void OnQuit()
	{
		GetTree().Paused = false;
		GetTree().Quit();
	}
}
