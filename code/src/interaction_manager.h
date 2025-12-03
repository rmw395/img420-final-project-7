#pragma once

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/classes/dir_access.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include "status_effect.h"
#include "recipe.h"
#include "entity.h"

namespace godot {

	class InteractionManager : public Object {
		GDCLASS(InteractionManager, Object)

	private:
		Dictionary recipe_index;
		Dictionary status_effect_dictionary;
		static InteractionManager* singleton;
		bool is_initialized = false;

	protected:

	public:
		InteractionManager();
		~InteractionManager();
		static void _bind_methods();
		static InteractionManager* get_singleton();
		void load_recipes();
		void load_status_effects();
		void add_status_effect(Entity* entity, String effect_id, double duration = 0);
		void _initialize();
		
	};

}