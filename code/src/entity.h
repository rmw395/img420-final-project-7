#pragma once

#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/core/binder_common.hpp>

namespace godot {

    class Entity : public CharacterBody2D {
        GDCLASS(Entity, CharacterBody2D);

    public:
        struct StatInfo {
            double base;
            double multiplier;
            double offset;
            double final;
        };
        struct VelocityInfo {
            double base;
            double multiplier;
            Vector2 offset;
            double final;
        };
        struct FrictionInfo {
            StatInfo ground;
            StatInfo air;
        };

        StatInfo max_health = { 100.0, 1.0, 0.0, 100.0 };
        double health = max_health.base;
        StatInfo max_speed = { 300.0, 1.0, 0.0, 300.0 };
        VelocityInfo velocity = { 0.0, 1.0, Vector2(0.0, 0.0), 0.0 };
        StatInfo acceleration = { 1500.0, 1.0, 0.0, 1500.0 };
        StatInfo damage = { 10.0, 1.0, 0.0, 10.0 };
        StatInfo defense = { 0.0, 1.0, 0.0, 0.0 };
        double min_received_damage = 0.0;
        FrictionInfo friction = { 800.0, 1.0, 0.0, 800.0, 200.0, 1.0, 0.0, 200.0 };
        bool invulnerable;

    protected:
        static void _bind_methods();

    public:
        Entity();
        ~Entity();

        void _enter_tree() override;
        void update_values();
        void move(Vector2 velocity);
        void _on_damage(double damage_amount, Vector2 knockback, bool bypass);
        void _on_heal(double heal_amount);

        void set_health(double v);
        double get_health() const;

        bool get_invulnerable() const;
        void set_invulnerable(bool v);

        // setters & getters (final stats)
        double get_max_health() const;
        double get_max_speed() const;
        double get_acceleration() const;
        double get_damage() const;
        double get_defense() const;
        double get_ground_friction() const;
        double get_air_friction() const;

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

}