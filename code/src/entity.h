#ifndef ENTITY_H
#define ENTITY_H

#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

class Entity : public CharacterBody2D {
    GDCLASS(Entity, CharacterBody2D);

private:
    // base stats
    double base_max_health = 100.0;
    double base_max_speed = 300.0;
    double base_acceleration = 1500.0;
    double base_damage = 10.0;
    double base_flat_defense = 0.0;
    double base_percent_defense = 0.0;
    double base_min_received_damage = 1.0;
    double base_ground_friction = 800.0;
    double base_air_friction = 200.0;

    // effective final values
    double max_health = 100.0;
    double max_speed = 300.0;
    double acceleration = 1500.0;
    double damage = 10.0;
    double flat_defense = 0.0;
    double percent_defense = 0.0;
    double min_received_damage = 1.0;
    double ground_friction = 800.0;
    double air_friction = 200.0;

    // multipliers
    double max_health_multiplier = 1.0;
    double max_speed_multiplier = 1.0;
    double acceleration_multiplier = 1.0;
    double damage_multiplier = 1.0;
    double defense_multiplier = 1.0;
    double ground_friction_multiplier = 1.0;
    double air_friction_multiplier = 1.0;

    // offsets
    double max_health_offset = 0.0;
    double max_speed_offset = 0.0;
    double acceleration_offset = 0.0;
    double damage_offset = 0.0;
    double defense_offset = 0.0;
    double ground_friction_offset = 0.0;
    double air_friction_offset = 0.0;

protected:
    static void _bind_methods();

public:
    Entity();
    ~Entity();

    void _ready() override;
    void UpdateValues();
    void Move(Vector2 velocity);
    void apply_damage(double damage_amount, Vector2 knockback);

    // setters & getters (base stats)
    void set_base_max_health(double v);
    double get_base_max_health() const;

    void set_base_max_speed(double v);
    double get_base_max_speed() const;

    void set_base_acceleration(double v);
    double get_base_acceleration() const;

    void set_base_damage(double v);
    double get_base_damage() const;

    void set_base_flat_defense(double v);
    double get_base_flat_defense() const;

    void set_base_percent_defense(double v);
    double get_base_percent_defense() const;

    void set_base_min_received_damage(double v);
    double get_base_min_received_damage() const;

    void set_base_ground_friction(double v);
    double get_base_ground_friction() const;

    void set_base_air_friction(double v);
    double get_base_air_friction() const;

    // multipliers
    void set_max_health_multiplier(double v);
    double get_max_health_multiplier() const;

    void set_max_speed_multiplier(double v);
    double get_max_speed_multiplier() const;

    void set_acceleration_multiplier(double v);
    double get_acceleration_multiplier() const;

    void set_damage_multiplier(double v);
    double get_damage_multiplier() const;

    void set_defense_multiplier(double v);
    double get_defense_multiplier() const;

    void set_ground_friction_multiplier(double v);
    double get_ground_friction_multiplier() const;

    void set_air_friction_multiplier(double v);
    double get_air_friction_multiplier() const;

    // offsets
    void set_max_health_offset(double v);
    double get_max_health_offset() const;

    void set_max_speed_offset(double v);
    double get_max_speed_offset() const;

    void set_acceleration_offset(double v);
    double get_acceleration_offset() const;

    void set_damage_offset(double v);
    double get_damage_offset() const;

    void set_defense_offset(double v);
    double get_defense_offset() const;

    void set_ground_friction_offset(double v);
    double get_ground_friction_offset() const;

    void set_air_friction_offset(double v);
    double get_air_friction_offset() const;
};

#endif
