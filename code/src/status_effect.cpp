#include "status_effect.h"
#include "interaction_manager.h"

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

    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::STRING, "id"), "set_id", "get_id");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "duration", PROPERTY_HINT_RANGE, "0.0, 60, 0.01"), "set_duration", "get_duration");

    ADD_GROUP("Health", "");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "max_health_multiplier", PROPERTY_HINT_RANGE, "-1, 10, 0.01"), "set_max_health_multiplier", "get_max_health_multiplier");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "max_health_offset", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_max_health_offset", "get_max_health_offset");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "health_change", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_health_change", "get_health_change");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "health_change_interval", PROPERTY_HINT_RANGE, "0.0, 60, 0.01"), "set_health_change_interval", "get_health_change_interval");

    ADD_GROUP("Mobility", "");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "max_speed_multiplier", PROPERTY_HINT_RANGE, "-1, 10, 0.01"), "set_max_speed_multiplier", "get_max_speed_multiplier");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "max_speed_offset", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_max_speed_offset", "get_max_speed_offset");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "velocity_multiplier", PROPERTY_HINT_RANGE, "-1, 10, 0.01"), "set_velocity_multiplier", "get_velocity_multiplier");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "velocity_offset", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_velocity_offset", "get_velocity_offset");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "acceleration_multiplier", PROPERTY_HINT_RANGE, "-1, 10, 0.01"), "set_acceleration_multiplier", "get_acceleration_multiplier");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "acceleration_offset", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_acceleration_offset", "get_acceleration_offset");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "ground_friction_multiplier", PROPERTY_HINT_RANGE, "-1, 10, 0.01"), "set_ground_friction_multiplier", "get_ground_friction_multiplier");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "ground_friction_offset", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_ground_friction_offset", "get_ground_friction_offset");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "air_friction_multiplier", PROPERTY_HINT_RANGE, "-1, 10, 0.01"), "set_air_friction_multiplier", "get_air_friction_multiplier");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "air_friction_offset", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_air_friction_offset", "get_air_friction_offset");

    ADD_GROUP("Combat", "");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "damage_multiplier", PROPERTY_HINT_RANGE, "-1, 10, 0.01"), "set_damage_multiplier", "get_damage_multiplier");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "damage_offset", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_damage_offset", "get_damage_offset");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "percent_defense", PROPERTY_HINT_RANGE, "0, 1, 0.01"), "set_defense_multiplier", "get_defense_multiplier");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "flat_defense", PROPERTY_HINT_RANGE, "-10, 10, 0.01"), "set_defense_offset", "get_defense_offset");

    ADD_GROUP("Transition to Effect", "");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::STRING, "transition_effect_id"), "set_transition_effect", "get_transition_effect");
    ClassDB::add_property(StatusEffect::get_class_static(), godot::PropertyInfo(godot::Variant::FLOAT, "transition_interval", PROPERTY_HINT_RANGE, "0.0, 60, 0.01"), "set_transition_interval", "get_transition_interval");
}

StatusEffect::StatusEffect() {
    entity_parent = nullptr;
    interaction_manager = nullptr;
    id = "";
    max_health.multiplier = 0.0;
    max_health.offset = 0.0;
    max_speed.multiplier = 0.0;
    max_speed.offset = 0.0;
    velocity.multiplier = 0.0;
    velocity.offset = Vector2(0.0, 0.0);
    acceleration.multiplier = 0.0;
    acceleration.offset = 0.0;
    damage.multiplier = 0.0;
    damage.offset = 0.0;
    defense.multiplier = 0.0;
    defense.offset = 0.0;
    friction.ground.multiplier = 0.0;
    friction.ground.offset = 0.0;
    friction.air.multiplier = 0.0;
    friction.air.offset = 0.0;
    health_change.amount = 0.0;
    health_change.interval.seconds = 0.0;
    health_change.interval.ticks = 0;
    duration.seconds = 0.0;
    duration.ticks = 0;
    transition.effect = "";
    transition.interval.seconds = 0.0;
    transition.interval.ticks = 0;
    transition.interval.current_wait_time = 0;
}

StatusEffect::~StatusEffect() {
    // Add your cleanup here.
}

void StatusEffect::_ready() {
    Node* parent = get_parent();
    entity_parent = Object::cast_to<Entity>(parent);
    if (entity_parent != nullptr) {
        interaction_manager = InteractionManager::get_singleton();
        entity_parent->max_health.multiplier += max_health.multiplier;
        entity_parent->max_health.offset += max_health.offset;
        entity_parent->max_speed.multiplier += max_speed.multiplier;
        entity_parent->max_speed.offset += max_speed.offset;
        entity_parent->velocity.multiplier += velocity.multiplier;
        entity_parent->velocity.offset += velocity.offset;
        entity_parent->acceleration.multiplier += acceleration.multiplier;
        entity_parent->acceleration.offset += acceleration.offset;
        entity_parent->damage.multiplier += damage.multiplier;
        entity_parent->damage.offset += damage.offset;
        entity_parent->defense.multiplier += defense.multiplier;
        entity_parent->defense.offset += defense.offset;
        entity_parent->friction.ground.multiplier += friction.ground.multiplier;
        entity_parent->friction.ground.offset += friction.ground.offset;
        entity_parent->friction.air.multiplier += friction.air.multiplier;
        entity_parent->friction.air.offset += friction.air.offset;
        entity_parent->update_values();

        health_change.interval.ticks = (int)(round(health_change.interval.seconds * Engine::get_singleton()->get_physics_ticks_per_second()));
        health_change.interval.current_wait_time = health_change.interval.ticks;
        transition.interval.ticks = (int)(round(transition.interval.seconds * Engine::get_singleton()->get_physics_ticks_per_second()));
        transition.interval.current_wait_time = transition.interval.ticks;
        duration.ticks = (int)(round(duration.seconds * Engine::get_singleton()->get_physics_ticks_per_second()));
        duration.current_wait_time = duration.ticks;
    }
    else {
        queue_free();
    }
    return;
}

void StatusEffect::_physics_process(double delta) {
    print_line("Process!");
    if (entity_parent != nullptr) {
        attempt_health_change();
        attempt_transition();
        duration.current_wait_time -= 1;
        if (duration.current_wait_time <= 0 && duration.ticks > 0) {
            queue_free();
        }
    }
    return;
}

void StatusEffect::attempt_health_change() {
    health_change.interval.current_wait_time -= 1;
    if (health_change.interval.current_wait_time <= 0) {
        if (health_change.amount > 0) {
            entity_parent->emit_signal("heal", health_change.amount);
            print_line("Heal Sent!");
        }
        else if (health_change.amount < 0) {
            entity_parent->emit_signal("damage", -health_change.amount, Vector2(0, 0));
            print_line("Damage Sent!");
        }
        health_change.interval.current_wait_time += health_change.interval.ticks;
    }
    return;
}

void StatusEffect::attempt_transition() {
    if (transition.effect != "") {
        transition.interval.current_wait_time -= 1;
        if (transition.interval.current_wait_time <= 0) {
            interaction_manager->add_status_effect(entity_parent, transition.effect);
            queue_free();
        }
    }
    return;
}

void StatusEffect::_exit_tree() {
    if (entity_parent != nullptr && !entity_parent->is_queued_for_deletion()) {
        entity_parent->max_health.multiplier -= max_health.multiplier;
        entity_parent->max_health.offset -= max_health.offset;
        entity_parent->max_speed.multiplier -= max_speed.multiplier;
        entity_parent->max_speed.offset -= max_speed.offset;
        entity_parent->velocity.multiplier -= velocity.multiplier;
        entity_parent->velocity.offset -= velocity.offset;
        entity_parent->acceleration.multiplier -= acceleration.multiplier;
        entity_parent->acceleration.offset -= acceleration.offset;
        entity_parent->damage.multiplier -= damage.multiplier;
        entity_parent->damage.offset -= damage.offset;
        entity_parent->defense.multiplier -= defense.multiplier;
        entity_parent->defense.offset -= defense.offset;
        entity_parent->friction.ground.multiplier -= friction.ground.multiplier;
        entity_parent->friction.ground.offset -= friction.ground.offset;
        entity_parent->friction.air.multiplier -= friction.air.multiplier;
        entity_parent->friction.air.offset -= friction.air.offset;
        entity_parent->update_values();
    }
    return;
}

String StatusEffect::get_id() const {
    return id;
}
void StatusEffect::set_id(String value) {
    id = value;
}

double StatusEffect::get_max_health_multiplier() const {
    return max_health.multiplier;
}
void StatusEffect::set_max_health_multiplier(double value) {
    max_health.multiplier = value;
}
double StatusEffect::get_max_health_offset() const {
    return max_health.offset;
}
void StatusEffect::set_max_health_offset(double value) {
    max_health.offset = value;
}

double StatusEffect::get_max_speed_multiplier() const {
    return max_speed.multiplier;
}
void StatusEffect::set_max_speed_multiplier(double value) {
    max_speed.multiplier = value;
}
double StatusEffect::get_max_speed_offset() const {
    return max_speed.offset;
}
void StatusEffect::set_max_speed_offset(double value) {
    max_speed.offset = value;
}

double StatusEffect::get_velocity_multiplier() const {
    return velocity.multiplier;
}
void StatusEffect::set_velocity_multiplier(double value) {
    velocity.multiplier = value;
}
Vector2 StatusEffect::get_velocity_offset() const {
    return velocity.offset;
}
void StatusEffect::set_velocity_offset(Vector2 value) {
    velocity.offset = value;
}

double StatusEffect::get_acceleration_multiplier() const {
    return acceleration.multiplier;
}
void StatusEffect::set_acceleration_multiplier(double value) {
    acceleration.multiplier = value;
}
double StatusEffect::get_acceleration_offset() const {
    return acceleration.offset;
}
void StatusEffect::set_acceleration_offset(double value) {
    acceleration.offset = value;
}

double StatusEffect::get_damage_multiplier() const {
    return damage.multiplier;
}
void StatusEffect::set_damage_multiplier(double value) {
    damage.multiplier = value;
}
double StatusEffect::get_damage_offset() const {
    return damage.offset;
}
void StatusEffect::set_damage_offset(double value) {
    damage.offset = value;
}

double StatusEffect::get_defense_multiplier() const {
    return defense.multiplier;
}
void StatusEffect::set_defense_multiplier(double value) {
    defense.multiplier = value;
}
double StatusEffect::get_defense_offset() const {
    return defense.offset;
}
void StatusEffect::set_defense_offset(double value) {
    defense.offset = value;
}

double StatusEffect::get_ground_friction_multiplier() const {
    return friction.ground.multiplier;
}
void StatusEffect::set_ground_friction_multiplier(double value) {
    friction.ground.multiplier = value;
}
double StatusEffect::get_ground_friction_offset() const {
    return friction.ground.offset;
}
void StatusEffect::set_ground_friction_offset(double value) {
    friction.ground.offset = value;
}

double StatusEffect::get_air_friction_multiplier() const {
    return friction.air.multiplier;
}
void StatusEffect::set_air_friction_multiplier(double value) {
    friction.air.multiplier = value;
}
double StatusEffect::get_air_friction_offset() const {
    return friction.air.offset;
}
void StatusEffect::set_air_friction_offset(double value) {
    friction.air.offset = value;
}

double StatusEffect::get_health_change() const {
    return health_change.amount;
}
void StatusEffect::set_health_change(double value) {
    health_change.amount = value;
}

double StatusEffect::get_health_change_interval() const {
    return health_change.interval.seconds;
}
void StatusEffect::set_health_change_interval(double value) {
    health_change.interval.seconds = value;
}

double StatusEffect::get_duration() const {
    return duration.seconds;
}
void StatusEffect::set_duration(double value) {
    duration.seconds = value;
}

String StatusEffect::get_transition_effect() const {
    return transition.effect;
}
void StatusEffect::set_transition_effect(String value) {
    transition.effect = value;
}

double StatusEffect::get_transition_interval() const {
    return transition.interval.seconds;
}
void StatusEffect::set_transition_interval(double value) {
    transition.interval.seconds = value;
}