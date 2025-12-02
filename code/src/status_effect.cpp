#include "status_effect.h"

using namespace godot;

void StatusEffect::_bind_methods() {

	ClassDB::bind_method(godot::D_METHOD("get_id"), &StatusEffect::get_id);
	ClassDB::bind_method(godot::D_METHOD("set_id", "value"), &StatusEffect::set_id);

	ClassDB::bind_method(godot::D_METHOD("get_max_health_multiplier"), &StatusEffect::get_max_health_multiplier);
	ClassDB::bind_method(godot::D_METHOD("set_max_health_multiplier", "value"), &StatusEffect::set_max_health_multiplier);

	ClassDB::bind_method(godot::D_METHOD("get_max_health_offset"), &StatusEffect::get_max_health_offset);
	ClassDB::bind_method(godot::D_METHOD("set_max_health_offset", "value"), &StatusEffect::set_max_health_offset);

	ClassDB::bind_method(godot::D_METHOD("get_max_speed_multiplier"), &StatusEffect::get_max_speed_multiplier);
	ClassDB::bind_method(godot::D_METHOD("set_max_speed_multiplier", "value"), &StatusEffect::set_max_speed_multiplier);

	ClassDB::bind_method(godot::D_METHOD("get_max_speed_offset"), &StatusEffect::get_max_speed_offset);
	ClassDB::bind_method(godot::D_METHOD("set_max_speed_offset", "value"), &StatusEffect::set_max_speed_offset);

	ClassDB::bind_method(godot::D_METHOD("get_velocity_multiplier"), &StatusEffect::get_velocity_multiplier);
	ClassDB::bind_method(godot::D_METHOD("set_velocity_multiplier", "value"), &StatusEffect::set_velocity_multiplier);

	ClassDB::bind_method(godot::D_METHOD("get_velocity_offset"), &StatusEffect::get_velocity_offset);
	ClassDB::bind_method(godot::D_METHOD("set_velocity_offset", "value"), &StatusEffect::set_velocity_offset);

	ClassDB::bind_method(godot::D_METHOD("get_acceleration_multiplier"), &StatusEffect::get_acceleration_multiplier);
	ClassDB::bind_method(godot::D_METHOD("set_acceleration_multiplier", "value"), &StatusEffect::set_acceleration_multiplier);

	ClassDB::bind_method(godot::D_METHOD("get_acceleration_offset"), &StatusEffect::get_acceleration_offset);
	ClassDB::bind_method(godot::D_METHOD("set_acceleration_offset", "value"), &StatusEffect::set_acceleration_offset);

	ClassDB::bind_method(godot::D_METHOD("get_damage_multiplier"), &StatusEffect::get_damage_multiplier);
	ClassDB::bind_method(godot::D_METHOD("set_damage_multiplier", "value"), &StatusEffect::set_damage_multiplier);

	ClassDB::bind_method(godot::D_METHOD("get_damage_offset"), &StatusEffect::get_damage_offset);
	ClassDB::bind_method(godot::D_METHOD("set_damage_offset", "value"), &StatusEffect::set_damage_offset);

	ClassDB::bind_method(godot::D_METHOD("get_defense_multiplier"), &StatusEffect::get_defense_multiplier);
	ClassDB::bind_method(godot::D_METHOD("set_defense_multiplier", "value"), &StatusEffect::set_defense_multiplier);

	ClassDB::bind_method(godot::D_METHOD("get_defense_offset"), &StatusEffect::get_defense_offset);
	ClassDB::bind_method(godot::D_METHOD("set_defense_offset", "value"), &StatusEffect::set_defense_offset);

	ClassDB::bind_method(godot::D_METHOD("get_ground_friction_multiplier"), &StatusEffect::get_ground_friction_multiplier);
	ClassDB::bind_method(godot::D_METHOD("set_ground_friction_multiplier", "value"), &StatusEffect::set_ground_friction_multiplier);

	ClassDB::bind_method(godot::D_METHOD("get_ground_friction_offset"), &StatusEffect::get_ground_friction_offset);
	ClassDB::bind_method(godot::D_METHOD("set_ground_friction_offset", "value"), &StatusEffect::set_ground_friction_offset);

	ClassDB::bind_method(godot::D_METHOD("get_air_friction_multiplier"), &StatusEffect::get_air_friction_multiplier);
	ClassDB::bind_method(godot::D_METHOD("set_air_friction_multiplier", "value"), &StatusEffect::set_air_friction_multiplier);

	ClassDB::bind_method(godot::D_METHOD("get_air_friction_offset"), &StatusEffect::get_air_friction_offset);
	ClassDB::bind_method(godot::D_METHOD("set_air_friction_offset", "value"), &StatusEffect::set_air_friction_offset);

	ClassDB::bind_method(godot::D_METHOD("get_health_change"), &StatusEffect::get_health_change);
	ClassDB::bind_method(godot::D_METHOD("set_health_change", "value"), &StatusEffect::set_health_change);

	ClassDB::bind_method(godot::D_METHOD("get_health_change_interval"), &StatusEffect::get_health_change_interval);
	ClassDB::bind_method(godot::D_METHOD("set_health_change_interval", "value"), &StatusEffect::set_health_change_interval);

	ClassDB::bind_method(godot::D_METHOD("get_duration"), &StatusEffect::get_duration);
	ClassDB::bind_method(godot::D_METHOD("set_duration", "value"), &StatusEffect::set_duration);

	ClassDB::bind_method(godot::D_METHOD("get_transition_effect"), &StatusEffect::get_transition_effect);
	ClassDB::bind_method(godot::D_METHOD("set_transition_effect", "value"), &StatusEffect::set_transition_effect);

	ClassDB::bind_method(godot::D_METHOD("get_transition_interval"), &StatusEffect::get_transition_interval);
	ClassDB::bind_method(godot::D_METHOD("set_transition_interval", "value"), &StatusEffect::set_transition_interval);

	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::STRING, "id"), "set_id", "get_id");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "duration", PROPERTY_HINT_RANGE, "0.0, 60, 0.01"), "set_duration", "get_duration");

	ADD_GROUP("Health", "");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "max_health_multiplier", PROPERTY_HINT_RANGE, "-1, 10, 0.01"), "set_max_health_multiplier", "get_max_health_multiplier");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "max_health_offset", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_max_health_offset", "get_max_health_offset");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "health_change", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_health_change", "get_health_change");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "health_change_interval", PROPERTY_HINT_RANGE, "0.0, 60, 0.01"), "set_health_change_interval", "get_health_change_interval");

	ADD_GROUP("Mobility", "");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "max_speed_multiplier", PROPERTY_HINT_RANGE, "-1, 10, 0.01"), "set_max_speed_multiplier", "get_max_speed_multiplier");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "max_speed_offset", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_max_speed_offset", "get_max_speed_offset");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "velocity_multiplier", PROPERTY_HINT_RANGE, "-1, 10, 0.01"), "set_velocity_multiplier", "get_velocity_multiplier");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "velocity_offset", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_velocity_offset", "get_velocity_offset");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "acceleration_multiplier", PROPERTY_HINT_RANGE, "-1, 10, 0.01"), "set_acceleration_multiplier", "get_acceleration_multiplier");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "acceleration_offset", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_acceleration_offset", "get_acceleration_offset");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "ground_friction_multiplier", PROPERTY_HINT_RANGE, "-1, 10, 0.01"), "set_ground_friction_multiplier", "get_ground_friction_multiplier");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "ground_friction_offset", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_ground_friction_offset", "get_ground_friction_offset");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "air_friction_multiplier", PROPERTY_HINT_RANGE, "-1, 10, 0.01"), "set_air_friction_multiplier", "get_air_friction_multiplier");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "air_friction_offset", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_air_friction_offset", "get_air_friction_offset");

	ADD_GROUP("Combat", "");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "damage_multiplier", PROPERTY_HINT_RANGE, "-1, 10, 0.01"), "set_damage_multiplier", "get_damage_multiplier");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "damage_offset", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_damage_offset", "get_damage_offset");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "percent_defense", PROPERTY_HINT_RANGE, "0, 1, 0.01"), "set_defense_multiplier", "get_defense_multiplier");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "flat_defense", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_defense_offset", "get_defense_offset");
	
	ADD_GROUP("Transition to Effect", "");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::STRING, "transition_effect_id"), "set_transition_effect", "get_transition_effect");
	ClassDB::add_property("StatusEffect", godot::PropertyInfo(godot::Variant::FLOAT, "transition_interval", PROPERTY_HINT_RANGE, "0.0, 60, 0.01"), "set_transition_interval", "get_transition_interval");
}

StatusEffect::StatusEffect() {
	Id = "";
	MaxHealth.Multiplier = 0.0;
	MaxHealth.Offset = 0.0;
	MaxSpeed.Multiplier = 0.0;
	MaxSpeed.Offset = 0.0;
	Velocity.Multiplier = 0.0;
	Velocity.Offset = 0.0;
	Acceleration.Multiplier = 0.0;
	Acceleration.Offset = 0.0;
	Damage.Multiplier = 0.0;
	Damage.Offset = 0.0;
	Defense.Multiplier = 0.0;
	Defense.Offset = 0.0;
	Friction.Ground.Multiplier = 0.0;
	Friction.Ground.Offset = 0.0;
	Friction.Air.Multiplier = 0.0;
	Friction.Air.Offset = 0.0;
	HealthChange.Amount = 0.0;
	HealthChange.Interval.Seconds = 0.0;
	HealthChange.Interval.Ticks = 0;
	Duration.Seconds = 0.0;
	Duration.Ticks = 0;
	Transition.Effect = "";
	Transition.Interval.Seconds = 0.0;
	Transition.Interval.Ticks = 0;
	Transition.Interval.currentWaitTime = 0;
}

StatusEffect::~StatusEffect() {
	// Add your cleanup here.
}

void StatusEffect::_ready() {
	Node* parent = get_parent();
	EntityParent = Object::cast_to<Entity>(parent);
	if (EntityParent != nullptr) {
		Manager = InteractionManager::get_singleton();
		EntityParent->MaxHealth.Multiplier += MaxHealth.Multiplier;
		EntityParent->MaxHealth.Offset += MaxHealth.Offset;
		EntityParent->MaxSpeed.Multiplier += MaxSpeed.Multiplier;
		EntityParent->MaxSpeed.Offset += MaxSpeed.Offset;
		EntityParent->Velocity.Multiplier += Velocity.Multiplier;
		EntityParent->Velocity.Offset += Velocity.Offset;
		EntityParent->Acceleration.Multiplier += Acceleration.Multiplier;
		EntityParent->Acceleration.Offset += Acceleration.Offset;
		EntityParent->Damage.Multiplier += Damage.Multiplier;
		EntityParent->Damage.Offset += Damage.Offset;
		EntityParent->Defense.Multiplier += Defense.Multiplier;
		EntityParent->Defense.Offset += Defense.Offset;
		EntityParent->Friction.Ground.Multiplier += Friction.Ground.Multiplier;
		EntityParent->Friction.Ground.Offset += Friction.Ground.Offset;
		EntityParent->Friction.Air.Multiplier += Friction.Air.Multiplier;
		EntityParent->Friction.Air.Offset += Friction.Air.Offset;

		HealthChange.Interval.Ticks = (int)(round(HealthChange.Interval.Seconds * Engine::get_singleton()->get_physics_ticks_per_second()));
		HealthChange.Interval.currentWaitTime = HealthChange.Interval.Ticks;
		Transition.Interval.Ticks = (int)(round(Transition.Interval.Seconds * Engine::get_singleton()->get_physics_ticks_per_second()));
		Transition.Interval.currentWaitTime = Transition.Interval.Ticks;
		Duration.Ticks = (int)(round(Duration.Seconds * Engine::get_singleton()->get_physics_ticks_per_second()));
		Duration.currentWaitTime = Duration.Ticks;
	}
	else {
		queue_free();
	}
	return;
}

void StatusEffect::_physics_process(double delta) {
	if (EntityParent != nullptr) {
		attempt_health_change();
		attempt_transition();
	}
	return;
}

void StatusEffect::attempt_health_change() {
	HealthChange.Interval.currentWaitTime -= 1;
	if (HealthChange.Interval.currentWaitTime <= 0) {
		if (HealthChange.Amount > 0) {
			EntityParent->emit_signal("Heal", HealthChange);
		}
		else if (HealthChange.Amount < 0) {
			EntityParent->emit_signal("Damage", HealthChange);
		}
	}
	return;
}

void StatusEffect::attempt_transition() {
	if (Transition.Effect != "") {
		Transition.Interval.currentWaitTime -= 1;
		if (Transition.Interval.currentWaitTime <= 0) {
			Manager->add_status_effect(EntityParent, Transition.Effect);
			queue_free();
		}
	}
	return;
}

void StatusEffect::_exit_tree() {
	if (EntityParent != nullptr) {
		EntityParent->MaxHealth.Multiplier -= MaxHealth.Multiplier;
		EntityParent->MaxHealth.Offset -= MaxHealth.Offset;
		EntityParent->MaxSpeed.Multiplier -= MaxSpeed.Multiplier;
		EntityParent->MaxSpeed.Offset -= MaxSpeed.Offset;
		EntityParent->Velocity.Multiplier -= Velocity.Multiplier;
		EntityParent->Velocity.Offset -= Velocity.Offset;
		EntityParent->Acceleration.Multiplier -= Acceleration.Multiplier;
		EntityParent->Acceleration.Offset -= Acceleration.Offset;
		EntityParent->Damage.Multiplier -= Damage.Multiplier;
		EntityParent->Damage.Offset -= Damage.Offset;
		EntityParent->Defense.Multiplier -= Defense.Multiplier;
		EntityParent->Defense.Offset -= Defense.Offset;
		EntityParent->Friction.Ground.Multiplier -= Friction.Ground.Multiplier;
		EntityParent->Friction.Ground.Offset -= Friction.Ground.Offset;
		EntityParent->Friction.Air.Multiplier -= Friction.Air.Multiplier;
		EntityParent->Friction.Air.Offset -= Friction.Air.Offset;
	}
	return;
}

String StatusEffect::get_id() const {
	return Id;
}
void StatusEffect::set_id(String value) {
	Id = value;
}

double StatusEffect::get_max_health_multiplier() const {
	return MaxHealth.Multiplier;
}
void StatusEffect::set_max_health_multiplier(double value) {
	MaxHealth.Multiplier = value;
}
double StatusEffect::get_max_health_offset() const {
	return MaxHealth.Offset;
}
void StatusEffect::set_max_health_offset(double value) {
	MaxHealth.Offset = value;
}

double StatusEffect::get_max_speed_multiplier() const {
	return MaxSpeed.Multiplier;
}
void StatusEffect::set_max_speed_multiplier(double value) {
	MaxSpeed.Multiplier = value;
}
double StatusEffect::get_max_speed_offset() const {
	return MaxSpeed.Offset;
}
void StatusEffect::set_max_speed_offset(double value) {
	MaxSpeed.Offset = value;
}

double StatusEffect::get_velocity_multiplier() const {
	return Velocity.Multiplier;
}
void StatusEffect::set_velocity_multiplier(double value) {
	Velocity.Multiplier = value;
}
double StatusEffect::get_velocity_offset() const {
	return Velocity.Offset;
}
void StatusEffect::set_velocity_offset(double value) {
	Velocity.Offset = value;
}

double StatusEffect::get_acceleration_multiplier() const {
	return Acceleration.Multiplier;
}
void StatusEffect::set_acceleration_multiplier(double value) {
	Acceleration.Multiplier = value;
}
double StatusEffect::get_acceleration_offset() const {
	return Acceleration.Offset;
}
void StatusEffect::set_acceleration_offset(double value) {
	Acceleration.Offset = value;
}

double StatusEffect::get_damage_multiplier() const {
	return Damage.Multiplier;
}
void StatusEffect::set_damage_multiplier(double value) {
	Damage.Multiplier = value;
}
double StatusEffect::get_damage_offset() const {
	return Damage.Offset;
}
void StatusEffect::set_damage_offset(double value) {
	Damage.Offset = value;
}

double StatusEffect::get_defense_multiplier() const {
	return Defense.Multiplier;
}
void StatusEffect::set_defense_multiplier(double value) {
	Defense.Multiplier = value;
}
double StatusEffect::get_defense_offset() const {
	return Defense.Offset;
}
void StatusEffect::set_defense_offset(double value) {
	Defense.Offset = value;
}

double StatusEffect::get_ground_friction_multiplier() const {
	return Friction.Ground.Multiplier;
}
void StatusEffect::set_ground_friction_multiplier(double value) {
	Friction.Ground.Multiplier = value;
}
double StatusEffect::get_ground_friction_offset() const {
	return Friction.Ground.Offset;
}
void StatusEffect::set_ground_friction_offset(double value) {
	Friction.Ground.Offset = value;
}

double StatusEffect::get_air_friction_multiplier() const {
	return Friction.Air.Multiplier;
}
void StatusEffect::set_air_friction_multiplier(double value) {
	Friction.Air.Multiplier = value;
}
double StatusEffect::get_air_friction_offset() const {
	return Friction.Air.Offset;
}
void StatusEffect::set_air_friction_offset(double value) {
	Friction.Air.Offset = value;
}

double StatusEffect::get_health_change() const {
	return HealthChange.Amount;
}
void StatusEffect::set_health_change(double value) {
	HealthChange.Amount = value;
}

double StatusEffect::get_health_change_interval() const {
	return HealthChange.Interval.Seconds;
}
void StatusEffect::set_health_change_interval(double value) {
	HealthChange.Interval.Seconds = value;
}

double StatusEffect::get_duration() const {
	return Duration.Seconds;
}
void StatusEffect::set_duration(double value) {
	Duration.Seconds = value;
}

String StatusEffect::get_transition_effect() const {
	return Transition.Effect;
}
void StatusEffect::set_transition_effect(String value) {
	Transition.Effect = value;
}

double StatusEffect::get_transition_interval() const {
	return Transition.Interval.Seconds;
}
void StatusEffect::set_transition_interval(double value) {
	Transition.Interval.Seconds = value;
}