#include "entity.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

Entity::Entity() {}
Entity::~Entity() {}

void Entity::_bind_methods() {

    // base stats
    ClassDB::bind_method(D_METHOD("set_base_max_health", "value"), &Entity::set_base_max_health);
    ClassDB::bind_method(D_METHOD("get_base_max_health"), &Entity::get_base_max_health);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "base_max_health"), "set_base_max_health", "get_base_max_health");

    ClassDB::bind_method(D_METHOD("set_base_max_speed", "value"), &Entity::set_base_max_speed);
    ClassDB::bind_method(D_METHOD("get_base_max_speed"), &Entity::get_base_max_speed);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "base_max_speed"), "set_base_max_speed", "get_base_max_speed");

    ClassDB::bind_method(D_METHOD("set_base_acceleration", "value"), &Entity::set_base_acceleration);
    ClassDB::bind_method(D_METHOD("get_base_acceleration"), &Entity::get_base_acceleration);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "base_acceleration"), "set_base_acceleration", "get_base_acceleration");

    ClassDB::bind_method(D_METHOD("set_base_damage", "value"), &Entity::set_base_damage);
    ClassDB::bind_method(D_METHOD("get_base_damage"), &Entity::get_base_damage);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "base_damage"), "set_base_damage", "get_base_damage");

    ClassDB::bind_method(D_METHOD("set_base_flat_defense", "value"), &Entity::set_base_flat_defense);
    ClassDB::bind_method(D_METHOD("get_base_flat_defense"), &Entity::get_base_flat_defense);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "base_flat_defense"), "set_base_flat_defense", "get_base_flat_defense");

    ClassDB::bind_method(D_METHOD("set_base_percent_defense", "value"), &Entity::set_base_percent_defense);
    ClassDB::bind_method(D_METHOD("get_base_percent_defense"), &Entity::get_base_percent_defense);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "base_percent_defense"), "set_base_percent_defense", "get_base_percent_defense");

    ClassDB::bind_method(D_METHOD("set_base_min_received_damage", "value"), &Entity::set_base_min_received_damage);
    ClassDB::bind_method(D_METHOD("get_base_min_received_damage"), &Entity::get_base_min_received_damage);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "base_min_received_damage"), "set_base_min_received_damage", "get_base_min_received_damage");

    ClassDB::bind_method(D_METHOD("set_base_ground_friction", "value"), &Entity::set_base_ground_friction);
    ClassDB::bind_method(D_METHOD("get_base_ground_friction"), &Entity::get_base_ground_friction);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "base_ground_friction"), "set_base_ground_friction", "get_base_ground_friction");

    ClassDB::bind_method(D_METHOD("set_base_air_friction", "value"), &Entity::set_base_air_friction);
    ClassDB::bind_method(D_METHOD("get_base_air_friction"), &Entity::get_base_air_friction);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "base_air_friction"), "set_base_air_friction", "get_base_air_friction");

    // multipliers
    ClassDB::bind_method(D_METHOD("set_max_health_multiplier", "value"), &Entity::set_max_health_multiplier);
    ClassDB::bind_method(D_METHOD("get_max_health_multiplier"), &Entity::get_max_health_multiplier);

    ClassDB::bind_method(D_METHOD("set_max_speed_multiplier", "value"), &Entity::set_max_speed_multiplier);
    ClassDB::bind_method(D_METHOD("get_max_speed_multiplier"), &Entity::get_max_speed_multiplier);

    ClassDB::bind_method(D_METHOD("set_acceleration_multiplier", "value"), &Entity::set_acceleration_multiplier);
    ClassDB::bind_method(D_METHOD("get_acceleration_multiplier"), &Entity::get_acceleration_multiplier);

    ClassDB::bind_method(D_METHOD("set_damage_multiplier", "value"), &Entity::set_damage_multiplier);
    ClassDB::bind_method(D_METHOD("get_damage_multiplier"), &Entity::get_damage_multiplier);

    ClassDB::bind_method(D_METHOD("set_defense_multiplier", "value"), &Entity::set_defense_multiplier);
    ClassDB::bind_method(D_METHOD("get_defense_multiplier"), &Entity::get_defense_multiplier);

    ClassDB::bind_method(D_METHOD("set_ground_friction_multiplier", "value"), &Entity::set_ground_friction_multiplier);
    ClassDB::bind_method(D_METHOD("get_ground_friction_multiplier"), &Entity::get_ground_friction_multiplier);

    ClassDB::bind_method(D_METHOD("set_air_friction_multiplier", "value"), &Entity::set_air_friction_multiplier);
    ClassDB::bind_method(D_METHOD("get_air_friction_multiplier"), &Entity::get_air_friction_multiplier);

    // offsets
    ClassDB::bind_method(D_METHOD("set_max_health_offset", "value"), &Entity::set_max_health_offset);
    ClassDB::bind_method(D_METHOD("get_max_health_offset"), &Entity::get_max_health_offset);

    ClassDB::bind_method(D_METHOD("set_max_speed_offset", "value"), &Entity::set_max_speed_offset);
    ClassDB::bind_method(D_METHOD("get_max_speed_offset"), &Entity::get_max_speed_offset);

    ClassDB::bind_method(D_METHOD("set_acceleration_offset", "value"), &Entity::set_acceleration_offset);
    ClassDB::bind_method(D_METHOD("get_acceleration_offset"), &Entity::get_acceleration_offset);

    ClassDB::bind_method(D_METHOD("set_damage_offset", "value"), &Entity::set_damage_offset);
    ClassDB::bind_method(D_METHOD("get_damage_offset"), &Entity::get_damage_offset);

    ClassDB::bind_method(D_METHOD("set_defense_offset", "value"), &Entity::set_defense_offset);
    ClassDB::bind_method(D_METHOD("get_defense_offset"), &Entity::get_defense_offset);

    ClassDB::bind_method(D_METHOD("set_ground_friction_offset", "value"), &Entity::set_ground_friction_offset);
    ClassDB::bind_method(D_METHOD("get_ground_friction_offset"), &Entity::get_ground_friction_offset);

    ClassDB::bind_method(D_METHOD("set_air_friction_offset", "value"), &Entity::set_air_friction_offset);
    ClassDB::bind_method(D_METHOD("get_air_friction_offset"), &Entity::get_air_friction_offset);

    // methods
    ClassDB::bind_method(D_METHOD("update_values"), &Entity::UpdateValues);
    ClassDB::bind_method(D_METHOD("move", "velocity"), &Entity::Move);

    // signal
    ADD_SIGNAL(MethodInfo("damage",
         PropertyInfo(Variant::FLOAT, "damage_amount"),
         PropertyInfo(Variant::VECTOR2, "knockback")));
}

void Entity::_ready() {
    UpdateValues();
}

void Entity::UpdateValues() {
    max_health = base_max_health * max_health_multiplier + max_health_offset;
    max_speed = base_max_speed * max_speed_multiplier + max_speed_offset;
    acceleration = base_acceleration * acceleration_multiplier + acceleration_offset;
    damage = base_damage * damage_multiplier + damage_offset;

    flat_defense = base_flat_defense * defense_multiplier + defense_offset;
    percent_defense = base_percent_defense * defense_multiplier;

    ground_friction = base_ground_friction * ground_friction_multiplier + ground_friction_offset;
    air_friction = base_air_friction * air_friction_multiplier + air_friction_offset;
}

void Entity::Move(Vector2 velocity) {
    Vector2 orig = velocity;

    velocity *= max_speed_multiplier;
    velocity += Vector2(max_speed_offset, max_speed_offset);

    set_velocity(velocity);
    move_and_slide();

    set_velocity(orig);
}

void Entity::apply_damage(double dmg, Vector2 knockback) {
    emit_signal("damage", dmg, knockback);
}

// base stat setters/getters

void Entity::set_base_max_health(double v) { base_max_health = v; UpdateValues(); }
double Entity::get_base_max_health() const { return base_max_health; }

void Entity::set_base_max_speed(double v) { base_max_speed = v; UpdateValues(); }
double Entity::get_base_max_speed() const { return base_max_speed; }

void Entity::set_base_acceleration(double v) { base_acceleration = v; UpdateValues(); }
double Entity::get_base_acceleration() const { return base_acceleration; }

void Entity::set_base_damage(double v) { base_damage = v; UpdateValues(); }
double Entity::get_base_damage() const { return base_damage; }

void Entity::set_base_flat_defense(double v) { base_flat_defense = v; UpdateValues(); }
double Entity::get_base_flat_defense() const { return base_flat_defense; }

void Entity::set_base_percent_defense(double v) { base_percent_defense = v; UpdateValues(); }
double Entity::get_base_percent_defense() const { return base_percent_defense; }

void Entity::set_base_min_received_damage(double v) { base_min_received_damage = v; }
double Entity::get_base_min_received_damage() const { return base_min_received_damage; }

void Entity::set_base_ground_friction(double v) { base_ground_friction = v; UpdateValues(); }
double Entity::get_base_ground_friction() const { return base_ground_friction; }

void Entity::set_base_air_friction(double v) { base_air_friction = v; UpdateValues(); }
double Entity::get_base_air_friction() const { return base_air_friction; }

// multipliers

void Entity::set_max_health_multiplier(double v) { max_health_multiplier = v; UpdateValues(); }
double Entity::get_max_health_multiplier() const { return max_health_multiplier; }

void Entity::set_max_speed_multiplier(double v) { max_speed_multiplier = v; UpdateValues(); }
double Entity::get_max_speed_multiplier() const { return max_speed_multiplier; }

void Entity::set_acceleration_multiplier(double v) { acceleration_multiplier = v; UpdateValues(); }
double Entity::get_acceleration_multiplier() const { return acceleration_multiplier; }

void Entity::set_damage_multiplier(double v) { damage_multiplier = v; UpdateValues(); }
double Entity::get_damage_multiplier() const { return damage_multiplier; }

void Entity::set_defense_multiplier(double v) { defense_multiplier = v; UpdateValues(); }
double Entity::get_defense_multiplier() const { return defense_multiplier; }

void Entity::set_ground_friction_multiplier(double v) { ground_friction_multiplier = v; UpdateValues(); }
double Entity::get_ground_friction_multiplier() const { return ground_friction_multiplier; }

void Entity::set_air_friction_multiplier(double v) { air_friction_multiplier = v; UpdateValues(); }
double Entity::get_air_friction_multiplier() const { return air_friction_multiplier; }

// offsets

void Entity::set_max_health_offset(double v) { max_health_offset = v; UpdateValues(); }
double Entity::get_max_health_offset() const { return max_health_offset; }

void Entity::set_max_speed_offset(double v) { max_speed_offset = v; UpdateValues(); }
double Entity::get_max_speed_offset() const { return max_speed_offset; }

void Entity::set_acceleration_offset(double v) { acceleration_offset = v; UpdateValues(); }
double Entity::get_acceleration_offset() const { return acceleration_offset; }

void Entity::set_damage_offset(double v) { damage_offset = v; UpdateValues(); }
double Entity::get_damage_offset() const { return damage_offset; }

void Entity::set_defense_offset(double v) { defense_offset = v; UpdateValues(); }
double Entity::get_defense_offset() const { return defense_offset; }

void Entity::set_ground_friction_offset(double v) { ground_friction_offset = v; UpdateValues(); }
double Entity::get_ground_friction_offset() const { return ground_friction_offset; }

void Entity::set_air_friction_offset(double v) { air_friction_offset = v; UpdateValues(); }
double Entity::get_air_friction_offset() const { return air_friction_offset; }
