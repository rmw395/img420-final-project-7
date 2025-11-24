#pragma once

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/core/property_info.hpp>
#include <godot_cpp/classes/engine.hpp>

namespace godot {

	class StatusEffect : public Node2D {
		GDCLASS(StatusEffect, Node2D)

	private:
		struct StatInfo {
			double Multiplier;
			double Offset;
		};
		struct FrictionInfo {
			StatInfo Ground;
			StatInfo Air;
		};
		struct DurationInfo {
			float Seconds;
			int Ticks;
		};
		struct HealthChangeInfo {
			float Amount;
			DurationInfo Interval;
		};

		String Id;
		DurationInfo Duration;
		StatInfo MaxHealth;
		StatInfo MaxSpeed;
		StatInfo Velocity;
		StatInfo Acceleration;
		StatInfo Damage;
		StatInfo Defense;
		FrictionInfo Friction;
		HealthChangeInfo HealthChange;
		String TransitionEffect;
		DurationInfo TransitionInterval;
		Entity* EntityParent = nullptr;

	protected:
		void _notification(int p_what);
		static void _bind_methods();

	public:
		StatusEffect();
		~StatusEffect();
		void _ready();
		void _exit_tree();

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
		double get_velocity_offset() const;
		void set_velocity_offset(double value);

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