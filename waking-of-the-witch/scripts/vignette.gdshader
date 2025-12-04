shader_type canvas_item;

uniform vec2 centerPosition = vec2(0.5, 0.5);

void fragment() {
	float dist = distance(vec2(UV.x, UV.y), centerPosition);
	if (dist > 0.3) {
		COLOR.a = (dist - 0.3);
	}
	else {
		COLOR.a = 0.0;
	}
}
