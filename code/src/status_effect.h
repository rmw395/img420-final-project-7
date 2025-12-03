#pragma once

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/core/property_info.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/core/class_db.hpp>
#include "entity.h"

namespace godot {

	class InteractionManager;

	class StatusEffect : public Node2D {
		GDCLASS(StatusEffect, Node2D)

	private:
		struct StatInfo {
			double multiplier;
			double offset;
		};
		struct VelocityInfo {
			double multiplier;
			Vector2 offset;
		};
		struct FrictionInfo {
			StatInfo ground;
			StatInfo air;
		};
		struct DurationInfo {
			float seconds;
			int ticks;
			int current_wait_time;
		};
		struct HealthChangeInfo {
			float amount;
			DurationInfo interval;
		};
		struct TransistionInfo {
			String effect;
			DurationInfo interval;
		};

		String id;
		DurationInfo duration;
		StatInfo max_health;
		StatInfo max_speed;
		VelocityInfo velocity;
		StatInfo acceleration;
		StatInfo damage;
		StatInfo defense;
		FrictionInfo friction;
		HealthChangeInfo health_change;
		TransistionInfo transition;
		Entity* entity_parent;
		InteractionManager* interaction_manager;

	protected:
		static void _bind_methods();

	public:
		StatusEffect();
		~StatusEffect();

		void _ready() override;
		void _physics_process(double delta) override;
		void _exit_tree() override;

		void attempt_health_change();
		void attempt_transition();

		String get_id() const;
		void set_id(String value);

		double get_max_health_multiplier() const;
		void set_max_health_multiplier(double value);
		double get_max_health_offset() const;
		void set_max_health_offset(double value);

		double get_max_speed_multiplier() const;
		void set_max_speed_multiplier(double value);
		double get_max_speed_offset() const;
		void set_max_speed_offset(double value);

		double get_velocity_multiplier() const;
		void set_velocity_multiplier(double value);
		Vector2 get_velocity_offset() const;
		void set_velocity_offset(Vector2 value);

		double get_acceleration_multiplier() const;
		void set_acceleration_multiplier(double value);
		double get_acceleration_offset() const;
		void set_acceleration_offset(double value);

		double get_damage_multiplier() const;
		void set_damage_multiplier(double value);
		double get_damage_offset() const;
		void set_damage_offset(double value);

		double get_defense_multiplier() const;
		void set_defense_multiplier(double value);
		double get_defense_offset() const;
		void set_defense_offset(double value);

		double get_ground_friction_multiplier() const;
		void set_ground_friction_multiplier(double value);
		double get_ground_friction_offset() const;
		void set_ground_friction_offset(double value);

		double get_air_friction_multiplier() const;
		void set_air_friction_multiplier(double value);
		double get_air_friction_offset() const;
		void set_air_friction_offset(double value);

		double get_health_change() const;
		void set_health_change(double value);

		double get_health_change_interval() const;
		void set_health_change_interval(double value);

		double get_duration() const;
		void set_duration(double value);

		String get_transition_effect() const;
		void set_transition_effect(String value);

		double get_transition_interval() const;
		void set_transition_interval(double value);
	};

}