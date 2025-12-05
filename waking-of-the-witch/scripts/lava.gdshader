shader_type canvas_item;

void fragment() {
	vec2 uv = UV;
	uv.x += 0.1 * sin(TIME + uv.y * 10.0);
	if (uv.x < 0.1 || uv.x > 0.9)
	{
		discard;
	}
	COLOR.a = COLOR.a * abs(uv.x + 0.5);
}
