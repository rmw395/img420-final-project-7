#pragma once

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/core/property_info.hpp>

namespace godot {

	class StatusEffect : public Node2D {
		GDCLASS(StatusEffect, Node2D)

	private:
		StringName ID;
		double MaxHealthMultiplier;
		double MaxHealthOffset;
		double MaxSpeedMultiplier;
		double MaxSpeedOffset;
		double VelocityMultiplier;
		double VelocityOffset;
		double AccelerationMultiplier;
		double AccelerationOffset;
		double DamageMultiplier;
		double DamageOffset;
		double DefenseMultiplier;
		double DefenseOffset;
		double GroundFrictionMultiplier;
		double GroundFrictionOffset;
		double AirFrictionMultiplier;
		double AirFrictionOffset;
		double DamageOverTime;
		int DamageInterval;
		double Duration;
		bool Transition;
		StringName TransitionEffect;
		int TransitionWaitTime;

	protected:
		static void _bind_methods();

	public:
		StatusEffect();
		~StatusEffect();

		StringName get_id() const;
		void set_id(StringName value);

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

		double get_damage_over_time() const;
		void set_damage_over_time(double value);

		int get_damage_interval() const;
		void set_damage_interval(int value);

		double get_duration() const;
		void set_duration(double value);

		bool get_transition() const;
		void set_transition(bool value);

		StringName get_transition_effect() const;
		void set_transition_effect(StringName value);

		int get_transition_wait_time() const;
		void set_transition_wait_time(int value);
	};

}