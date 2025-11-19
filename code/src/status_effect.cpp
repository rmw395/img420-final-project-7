#include "status_effect.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void StatusEffect::_bind_methods() {
	ClassDB::bind_method(
		godot::D_METHOD("get_variable"),
		&StatusEffect::get_variable
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_variable", "value"),
		&StatusEffect::set_variable
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::INT,
			"StatusEffect Variable"
		),
		"set_variable",
		"get_variable"
	);
}

StatusEffect::StatusEffect() {
	variable = 0;
}

StatusEffect::~StatusEffect() {
	// Add your cleanup here.
}

int StatusEffect::get_variable() const {
	return variable;
}

void StatusEffect::set_variable(int value) {
	variable = value;
}