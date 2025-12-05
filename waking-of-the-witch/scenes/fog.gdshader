shader_type canvas_item;

void fragment() {
	COLOR = vec4(COLOR.rgb, COLOR.a * pow(UV.y - 0.1, 2));
}
