#include "status_effect.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void StatusEffect::_bind_methods() {
	ClassDB::bind_method(
		godot::D_METHOD("get_id"),
		&StatusEffect::get_id
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_id", "value"),
		&StatusEffect::set_id
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::STRING_NAME,
			"StatusEffect ID"
		),
		"set_id",
		"get_id"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_max_health_multiplier"),
		&StatusEffect::get_max_health_multiplier
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_max_health_multiplier", "value"),
		&StatusEffect::set_max_health_multiplier
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Max Health Multiplier"
		),
		"set_max_health_multiplier",
		"get_max_health_multiplier"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_max_health_offset"),
		&StatusEffect::get_max_health_offset
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_max_health_offset", "value"),
		&StatusEffect::set_max_health_offset
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Max Health Offset"
		),
		"set_max_health_offset",
		"get_max_health_offset"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_max_speed_multiplier"),
		&StatusEffect::get_max_speed_multiplier
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_max_speed_multiplier", "value"),
		&StatusEffect::set_max_speed_multiplier
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Max Speed Multiplier"
		),
		"set_max_speed_multiplier",
		"get_max_speed_multiplier"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_max_speed_offset"),
		&StatusEffect::get_max_speed_offset
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_max_speed_offset", "value"),
		&StatusEffect::set_max_speed_offset
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Max Speed Offset"
		),
		"set_max_speed_offset",
		"get_max_speed_offset"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_velocity_multiplier"),
		&StatusEffect::get_velocity_multiplier
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_velocity_multiplier", "value"),
		&StatusEffect::set_velocity_multiplier
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Velocity Multiplier"
		),
		"set_velocity_multiplier",
		"get_velocity_multiplier"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_velocity_offset"),
		&StatusEffect::get_velocity_offset
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_velocity_offset", "value"),
		&StatusEffect::set_velocity_offset
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Velocity Offset"
		),
		"set_velocity_offset",
		"get_velocity_offset"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_acceleration_multiplier"),
		&StatusEffect::get_acceleration_multiplier
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_acceleration_multiplier", "value"),
		&StatusEffect::set_acceleration_multiplier
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Acceleration Multiplier"
		),
		"set_acceleration_multiplier",
		"get_acceleration_multiplier"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_acceleration_offset"),
		&StatusEffect::get_acceleration_offset
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_acceleration_offset", "value"),
		&StatusEffect::set_acceleration_offset
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Acceleration Offset"
		),
		"set_acceleration_offset",
		"get_acceleration_offset"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_damage_multiplier"),
		&StatusEffect::get_damage_multiplier
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_damage_multiplier", "value"),
		&StatusEffect::set_damage_multiplier
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Damage Multiplier"
		),
		"set_damage_multiplier",
		"get_damage_multiplier"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_damage_offset"),
		&StatusEffect::get_damage_offset
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_damage_offset", "value"),
		&StatusEffect::set_damage_offset
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Damage Offset"
		),
		"set_damage_offset",
		"get_damage_offset"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_defense_multiplier"),
		&StatusEffect::get_defense_multiplier
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_defense_multiplier", "value"),
		&StatusEffect::set_defense_multiplier
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Defense Multiplier"
		),
		"set_defense_multiplier",
		"get_defense_multiplier"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_defense_offset"),
		&StatusEffect::get_defense_offset
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_defense_offset", "value"),
		&StatusEffect::set_defense_offset
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Defense Offset"
		),
		"set_defense_offset",
		"get_defense_offset"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_ground_friction_multiplier"),
		&StatusEffect::get_ground_friction_multiplier
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_ground_friction_multiplier", "value"),
		&StatusEffect::set_ground_friction_multiplier
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Ground Friction Multiplier"
		),
		"set_ground_friction_multiplier",
		"get_ground_friction_multiplier"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_ground_friction_offset"),
		&StatusEffect::get_ground_friction_offset
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_ground_friction_offset", "value"),
		&StatusEffect::set_ground_friction_offset
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Ground Friction Offset"
		),
		"set_ground_friction_offset",
		"get_ground_friction_offset"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_air_friction_multiplier"),
		&StatusEffect::get_air_friction_multiplier
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_air_friction_multiplier", "value"),
		&StatusEffect::set_air_friction_multiplier
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Air Friction Multiplier"
		),
		"set_air_friction_multiplier",
		"get_air_friction_multiplier"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_air_friction_offset"),
		&StatusEffect::get_air_friction_offset
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_air_friction_offset", "value"),
		&StatusEffect::set_air_friction_offset
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Air Friction Offset"
		),
		"set_air_friction_offset",
		"get_air_friction_offset"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_damage_over_time"),
		&StatusEffect::get_damage_over_time
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_damage_over_time", "value"),
		&StatusEffect::set_damage_over_time
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Damage Over Time"
		),
		"set_damage_over_time",
		"get_damage_over_time"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_damage_interval"),
		&StatusEffect::get_damage_interval
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_damage_interval", "value"),
		&StatusEffect::set_damage_interval
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::INT,
			"Damage Interval"
		),
		"set_damage_interval",
		"get_damage_interval"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_duration"),
		&StatusEffect::get_duration
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_duration", "value"),
		&StatusEffect::set_duration
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::FLOAT,
			"Duration"
		),
		"set_duration",
		"get_duration"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_transition"),
		&StatusEffect::get_transition
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_transition", "value"),
		&StatusEffect::set_transition
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::BOOL,
			"Transition"
		),
		"set_transition",
		"get_transition"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_transition_effect"),
		&StatusEffect::get_transition_effect
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_transition_effect", "value"),
		&StatusEffect::set_transition_effect
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::STRING_NAME,
			"Transition Effect"
		),
		"set_transition_effect",
		"get_transition_effect"
	);

	ClassDB::bind_method(
		godot::D_METHOD("get_transition_wait_time"),
		&StatusEffect::get_transition_wait_time
	);
	ClassDB::bind_method(
		godot::D_METHOD("set_transition_wait_time", "value"),
		&StatusEffect::set_transition_wait_time
	);
	ClassDB::add_property(
		"StatusEffect",
		godot::PropertyInfo(
			godot::Variant::INT,
			"Transition Wait Time"
		),
		"set_transition_wait_time",
		"get_transition_wait_time"
	);
}

StatusEffect::StatusEffect() {
	ID = "";
	MaxHealthMultiplier = 0.0;
	MaxHealthOffset = 0.0;
	MaxSpeedMultiplier = 0.0;
	MaxSpeedOffset = 0.0;
	VelocityMultiplier = 0.0;
	VelocityOffset = 0.0;
	AccelerationMultiplier = 0.0;
	AccelerationOffset = 0.0;
	DamageMultiplier = 0.0;
	DamageOffset = 0.0;
	DefenseMultiplier = 0.0;
	DefenseOffset = 0.0;
	GroundFrictionMultiplier = 0.0;
	GroundFrictionOffset = 0.0;
	AirFrictionMultiplier = 0.0;
	AirFrictionOffset = 0.0;
	DamageOverTime = 0.0;
	DamageInterval = 0;
	Duration = 0.0;
	Transition = false;
	TransitionEffect = "";
	TransitionWaitTime = 0;
}

StatusEffect::~StatusEffect() {
	// Add your cleanup here.
}

StringName StatusEffect::get_id() const {
	return ID;
}
void StatusEffect::set_id(StringName value) {
	ID = value;
}

double StatusEffect::get_max_health_multiplier() const {
	return MaxHealthMultiplier;
}
void StatusEffect::set_max_health_multiplier(double value) {
	MaxHealthMultiplier = value;
}
double StatusEffect::get_max_health_offset() const {
	return MaxHealthOffset;
}
void StatusEffect::set_max_health_offset(double value) {
	MaxHealthOffset = value;
}

double StatusEffect::get_max_speed_multiplier() const {
	return MaxSpeedMultiplier;
}
void StatusEffect::set_max_speed_multiplier(double value) {
	MaxSpeedMultiplier = value;
}
double StatusEffect::get_max_speed_offset() const {
	return MaxSpeedOffset;
}
void StatusEffect::set_max_speed_offset(double value) {
	MaxSpeedOffset = value;
}

double StatusEffect::get_velocity_multiplier() const {
	return VelocityMultiplier;
}
void StatusEffect::set_velocity_multiplier(double value) {
	VelocityMultiplier = value;
}
double StatusEffect::get_velocity_offset() const {
	return VelocityOffset;
}
void StatusEffect::set_velocity_offset(double value) {
	VelocityOffset = value;
}

double StatusEffect::get_acceleration_multiplier() const {
	return AccelerationMultiplier;
}
void StatusEffect::set_acceleration_multiplier(double value) {
	AccelerationMultiplier = value;
}
double StatusEffect::get_acceleration_offset() const {
	return AccelerationOffset;
}
void StatusEffect::set_acceleration_offset(double value) {
	AccelerationOffset = value;
}

double StatusEffect::get_damage_multiplier() const {
	return DamageMultiplier;
}
void StatusEffect::set_damage_multiplier(double value) {
	DamageMultiplier = value;
}
double StatusEffect::get_damage_offset() const {
	return DamageOffset;
}
void StatusEffect::set_damage_offset(double value) {
	DamageOffset = value;
}

double StatusEffect::get_defense_multiplier() const {
	return DefenseMultiplier;
}
void StatusEffect::set_defense_multiplier(double value) {
	DefenseMultiplier = value;
}
double StatusEffect::get_defense_offset() const {
	return DefenseOffset;
}
void StatusEffect::set_defense_offset(double value) {
	DefenseOffset = value;
}

double StatusEffect::get_ground_friction_multiplier() const {
	return GroundFrictionMultiplier;
}
void StatusEffect::set_ground_friction_multiplier(double value) {
	GroundFrictionMultiplier = value;
}
double StatusEffect::get_ground_friction_offset() const {
	return GroundFrictionOffset;
}
void StatusEffect::set_ground_friction_offset(double value) {
	GroundFrictionOffset = value;
}

double StatusEffect::get_air_friction_multiplier() const {
	return AirFrictionMultiplier;
}
void StatusEffect::set_air_friction_multiplier(double value) {
	AirFrictionMultiplier = value;
}
double StatusEffect::get_air_friction_offset() const {
	return AirFrictionOffset;
}
void StatusEffect::set_air_friction_offset(double value) {
	AirFrictionOffset = value;
}

double StatusEffect::get_damage_over_time() const {
	return DamageOverTime;
}
void StatusEffect::set_damage_over_time(double value) {
	DamageOverTime = value;
}

int StatusEffect::get_damage_interval() const {
	return DamageInterval;
}
void StatusEffect::set_damage_interval(int value) {
	DamageInterval = value;
}

double StatusEffect::get_duration() const {
	return Duration;
}
void StatusEffect::set_duration(double value) {
	Duration = value;
}

bool StatusEffect::get_transition() const {
	return Transition;
}
void StatusEffect::set_transition(bool value) {
	Transition = value;
}

StringName StatusEffect::get_transition_effect() const {
	return TransitionEffect;
}
void StatusEffect::set_transition_effect(StringName value) {
	TransitionEffect = value;
}

int StatusEffect::get_transition_wait_time() const {
	return TransitionWaitTime;
}
void StatusEffect::set_transition_wait_time(int value) {
	TransitionWaitTime = value;
}