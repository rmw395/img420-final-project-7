#pragma once

#include <godot_cpp/classes/node2d.hpp>

namespace godot {

	class StatusEffect : public Node2D {
		GDCLASS(StatusEffect, Node2D)

	private:
		int variable;

	protected:
		static void _bind_methods();

	public:
		StatusEffect();
		~StatusEffect();

		int get_variable() const;
		void set_variable(int value);
	};

}