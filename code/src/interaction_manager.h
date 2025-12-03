#pragma once

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/classes/dir_access.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include "status_effect.h"

namespace godot {

	class InteractionManager : public Object {
		GDCLASS(InteractionManager, Object)

	private:
		Dictionary RecipeIndex;
		Dictionary StatusEffectDictionary;
		static InteractionManager* singleton = nullptr;

	protected:

	public:
		InteractionManager();
		~InteractionManager();
		static InteractionManager* get_singleton();
		void load_recipes();
		void load_status_effects();
		void add_status_effect(Entity* entity, String effect_id, double duration = 0);
		void _initialize();
		
	};

}