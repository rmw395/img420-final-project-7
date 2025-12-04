#include "entity.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

Entity::Entity() {}
Entity::~Entity() {}

void Entity::_bind_methods() {

    ClassDB::bind_method(D_METHOD("set_health", "value"), &Entity::set_health);
    ClassDB::bind_method(D_METHOD("get_health"), &Entity::get_health);

    ClassDB::bind_method(D_METHOD("set_invulnerable", "value"), &Entity::set_invulnerable);
    ClassDB::bind_method(D_METHOD("get_invulnerable"), &Entity::get_invulnerable);

    // --- FINAL STATS ---

    ClassDB::bind_method(D_METHOD("get_max_health"), &Entity::get_max_health);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_health", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_READ_ONLY), "", "get_max_health");

    ClassDB::bind_method(D_METHOD("get_max_speed"), &Entity::get_max_speed);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_speed", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_READ_ONLY), "", "get_max_speed");

    ClassDB::bind_method(D_METHOD("get_acceleration"), &Entity::get_acceleration);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "acceleration", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_READ_ONLY), "", "get_acceleration");

    ClassDB::bind_method(D_METHOD("get_damage"), &Entity::get_damage);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "damage", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_READ_ONLY), "", "get_damage");

    ClassDB::bind_method(D_METHOD("get_defense"), &Entity::get_defense);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "defense", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_READ_ONLY), "", "get_defense");

    ClassDB::bind_method(D_METHOD("get_ground_friction"), &Entity::get_ground_friction);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "ground_friction", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_READ_ONLY), "", "get_ground_friction");

    ClassDB::bind_method(D_METHOD("get_air_friction"), &Entity::get_air_friction);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "air_friction", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_READ_ONLY), "", "get_air_friction");

    // --- BASE STATS ---

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
    ClassDB::bind_method(D_METHOD("update_values"), &Entity::update_values);
    ClassDB::bind_method(D_METHOD("move", "velocity"), &Entity::move);

    // signal
    ClassDB::bind_method(D_METHOD("_on_damage", "damage_amount", "knockback", "bypass"), &Entity::_on_damage);

    ADD_SIGNAL(MethodInfo("damage",
        PropertyInfo(Variant::FLOAT, "damage_amount"),
        PropertyInfo(Variant::VECTOR2, "knockback"),
        PropertyInfo(Variant::BOOL, "bypass")));

    ADD_SIGNAL(MethodInfo("do_damage_effects",
        PropertyInfo(Variant::BOOL, "bypass")));

    ClassDB::bind_method(D_METHOD("_on_heal", "heal_amount"), &Entity::_on_heal);

    ADD_SIGNAL(MethodInfo("heal",
        PropertyInfo(Variant::FLOAT, "heal_amount")));
}

void Entity::_enter_tree() {
    connect("damage", Callable(this, "_on_damage"));
    connect("heal", Callable(this, "_on_heal"));
    bool invulnerable = false;
    update_values();
}

void Entity::update_values() {
    max_health.final = max_health.base * max_health.multiplier + max_health.offset;
    max_speed.final = max_speed.base * max_speed.multiplier + max_speed.offset;
    acceleration.final = acceleration.base * acceleration.multiplier + acceleration.offset;
    damage.final = damage.base * damage.multiplier + damage.offset;

    friction.ground.final = friction.ground.base * friction.ground.multiplier + friction.ground.offset;
    friction.air.final = friction.air.base * friction.air.multiplier + friction.air.offset;
}

void Entity::move(Vector2 given_velocity) {
    Vector2 orig = given_velocity;
    Vector2 adjusted_velocity = given_velocity;

    adjusted_velocity *= velocity.multiplier;
    adjusted_velocity += velocity.offset;

    set_velocity(adjusted_velocity);
    move_and_slide();

    set_velocity(orig);
}

void Entity::_on_damage(double dmg, Vector2 knockback, bool bypass) {
    print_line("Damage Received!  (", dmg, ")", " Invulnerable: ", invulnerable);
    if (!invulnerable || bypass) {
        print_line("Damage Dealt!  (", dmg, ")");
        health -= dmg;
        health = CLAMP(health, 0, max_health.final);
        set_velocity((get_velocity() + knockback));
        emit_signal("do_damage_effects", bypass);
    }
}

void Entity::_on_heal(double heal) {
    print_line("Heal Received!");
    health += heal;
    health = CLAMP(health, 0, max_health.final);
}

void Entity::set_health(double v) { health = v; }
double Entity::get_health() const { return health; }
void Entity::set_invulnerable(bool v) { invulnerable = v; }
bool Entity::get_invulnerable() const { return invulnerable; }

// final stat getters
double Entity::get_max_health() const { return max_health.final; }
double Entity::get_max_speed() const { return max_speed.final; }
double Entity::get_acceleration() const { return acceleration.final; }
double Entity::get_damage() const { return damage.final; }
double Entity::get_defense() const { return defense.final; }
double Entity::get_ground_friction() const { return friction.ground.final; }
double Entity::get_air_friction() const { return friction.air.final; }

// base stat setters/getters

void Entity::set_base_max_health(double v) { max_health.base = v; update_values(); }
double Entity::get_base_max_health() const { return max_health.base; }

void Entity::set_base_max_speed(double v) { max_speed.base = v; update_values(); }
double Entity::get_base_max_speed() const { return max_speed.base; }

void Entity::set_base_acceleration(double v) { acceleration.base = v; update_values(); }
double Entity::get_base_acceleration() const { return acceleration.base; }

void Entity::set_base_damage(double v) { damage.base = v; update_values(); }
double Entity::get_base_damage() const { return damage.base; }

void Entity::set_base_flat_defense(double v) { defense.base = v; update_values(); }
double Entity::get_base_flat_defense() const { return defense.base; }

void Entity::set_base_percent_defense(double v) { defense.base = v; update_values(); }
double Entity::get_base_percent_defense() const { return defense.base; }

void Entity::set_base_min_received_damage(double v) { min_received_damage = v; update_values(); }
double Entity::get_base_min_received_damage() const { return min_received_damage; }

void Entity::set_base_ground_friction(double v) { friction.ground.base = v; update_values(); }
double Entity::get_base_ground_friction() const { return friction.ground.base; }

void Entity::set_base_air_friction(double v) { friction.air.base = v; update_values(); }
double Entity::get_base_air_friction() const { return friction.air.base; }

// multipliers

void Entity::set_max_health_multiplier(double v) { max_health.multiplier = v; update_values(); }
double Entity::get_max_health_multiplier() const { return max_health.multiplier; }

void Entity::set_max_speed_multiplier(double v) { max_speed.multiplier = v; update_values(); }
double Entity::get_max_speed_multiplier() const { return max_speed.multiplier; }

void Entity::set_acceleration_multiplier(double v) { acceleration.multiplier = v; update_values(); }
double Entity::get_acceleration_multiplier() const { return acceleration.multiplier; }

void Entity::set_damage_multiplier(double v) { damage.multiplier = v; update_values(); }
double Entity::get_damage_multiplier() const { return damage.multiplier; }

void Entity::set_defense_multiplier(double v) { defense.multiplier = v; update_values(); }
double Entity::get_defense_multiplier() const { return defense.multiplier; }

void Entity::set_ground_friction_multiplier(double v) { friction.ground.multiplier = v; update_values(); }
double Entity::get_ground_friction_multiplier() const { return friction.ground.multiplier; }

void Entity::set_air_friction_multiplier(double v) { friction.air.multiplier = v; update_values(); }
double Entity::get_air_friction_multiplier() const { return friction.air.multiplier; }

// offsets

void Entity::set_max_health_offset(double v) { max_health.offset = v; update_values(); }
double Entity::get_max_health_offset() const { return max_health.offset; }

void Entity::set_max_speed_offset(double v) { max_speed.offset = v; update_values(); }
double Entity::get_max_speed_offset() const { return max_speed.offset; }

void Entity::set_acceleration_offset(double v) { acceleration.offset = v; update_values(); }
double Entity::get_acceleration_offset() const { return acceleration.offset; }

void Entity::set_damage_offset(double v) { damage.offset = v; update_values(); }
double Entity::get_damage_offset() const { return damage.offset; }

void Entity::set_defense_offset(double v) { defense.offset = v; update_values(); }
double Entity::get_defense_offset() const { return defense.offset; }

void Entity::set_ground_friction_offset(double v) { friction.ground.offset = v; update_values(); }
double Entity::get_ground_friction_offset() const { return friction.ground.offset; }

void Entity::set_air_friction_offset(double v) { friction.air.offset = v; update_values(); }
double Entity::get_air_friction_offset() const { return friction.air.offset; }