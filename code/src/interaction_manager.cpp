#include "interaction_manager.h"

using namespace godot;

InteractionManager::InteractionManager() {
	singleton = this;
}

InteractionManager::~InteractionManager() {
	if (singleton == this) {
		singleton = nullptr;
	}
}

void InteractionManager::_bind_methods() {

}

InteractionManager* InteractionManager::singleton = nullptr;

InteractionManager* InteractionManager::get_singleton() {
	return singleton;
}

void InteractionManager::_initialize() {
	load_recipes();
	load_status_effects();
}

void InteractionManager::load_recipes() {
	ResourceLoader* rl = ResourceLoader::get_singleton();
	ProjectSettings* ps = ProjectSettings::get_singleton();
	String folder_path = ps->get_setting("interaction_manager/recipe_file_path", "res://recipes/");
	if (!folder_path.ends_with("/")) {
		folder_path += "/";
	}
	Ref<DirAccess> dir = DirAccess::open(folder_path);
	if (dir.is_null()) {
		return;
	}
	dir->list_dir_begin();
	String file_name = dir->get_next();

	while (file_name != "") {
		if (!dir->current_is_dir()) {
			String resource_path = folder_path + file_name;
			Ref<Recipe> loaded_recipe = rl->load(resource_path);
			if (loaded_recipe.is_valid()) {
				for (int i = 0; i < loaded_recipe->get_input_effects().size(); i++) {
					String effect_id = loaded_recipe->get_input_effects()[i];
					if (RecipeIndex.has(effect_id)) {
						Array recipes = RecipeIndex[effect_id];
						recipes.append(loaded_recipe);
						RecipeIndex[effect_id] = recipes;
					}
					else {
						Array recipes = { loaded_recipe };
						RecipeIndex[effect_id] = recipes;
					}
				}
			}
		}
		file_name = dir->get_next();
	}
	dir->list_dir_end();
}

void InteractionManager::load_status_effects() {
	ResourceLoader* rl = ResourceLoader::get_singleton();
	ProjectSettings* ps = ProjectSettings::get_singleton();
	String folder_path = ps->get_setting("interaction_manager/status_effect_file_path", "res://recipes");
	Ref<DirAccess> dir = DirAccess::open(folder_path);
	if (dir.is_null()) {
		return;
	}
	dir->list_dir_begin();
	String file_name = dir->get_next();

	while (file_name != "") {
		if (!dir->current_is_dir()) {
			String scene_path = folder_path + file_name;
			Ref<PackedScene> loaded_scene = rl->load(scene_path);
			if (loaded_scene.is_valid()) {
				Node* root_node = loaded_scene->instantiate();
				if (root_node) {
					StatusEffect* status_effect = Object::cast_to<StatusEffect>(root_node);
					if (status_effect) {
						String id = status_effect->get_id();
						if (id != "") {
							StatusEffectDictionary[id] = loaded_scene;
						}
					}
					// FIX: Delete the orphan node immediately
					memdelete(root_node);
				}
			}
		}
		file_name = dir->get_next();
	}
	dir->list_dir_end();
}

void InteractionManager::add_status_effect(Entity* entity, String effect_id, double duration) {
	Dictionary entity_status_map;
	int child_count = entity->get_child_count();

	for (int k = 0; k < child_count; k++) {
		Node* child = entity->get_child(k);
		StatusEffect* status_effect = Object::cast_to<StatusEffect>(child);

		if (status_effect) {
			entity_status_map[status_effect->get_id()] = status_effect;
		}
	}
	if (entity_status_map.has(effect_id)) {
		Object* generic_object = (Object*)entity_status_map.get(effect_id, Ref<PackedScene>());
		StatusEffect* status_effect = Object::cast_to<StatusEffect>(generic_object);
		double current_duration = status_effect->get_duration();
		double setting_duration;
		if (duration > 0.0) {
			setting_duration = duration;
		}
		else {
			Ref<PackedScene> default_effect_scene = StatusEffectDictionary[effect_id];
			Node* root_node = default_effect_scene->instantiate();
			if (root_node) {
				StatusEffect* default_effect = Object::cast_to<StatusEffect>(root_node);
				if (default_effect) {
					setting_duration = default_effect->get_duration();
				}
				else {
					setting_duration = 0.0;
				}
				// FIX: Delete the orphan node immediately
				memdelete(root_node);
			}
		}
		double new_duration = (current_duration < setting_duration) ? setting_duration : current_duration;
		status_effect->set_duration(new_duration);
		return;
	}
	Array available_recipes_variant = RecipeIndex.get(effect_id, Array());
	Array candidate_recipes;
	for (int i = 0; i < available_recipes_variant.size(); i++) {
		Ref<Recipe> recipe = available_recipes_variant[i];

		if (!recipe.is_valid()) continue;

		bool all_ingredients_present = true;
		const Array& input_effects = recipe->get_input_effects();
		for (int j = 0; j < input_effects.size(); j++) {
			String required_effect_id = input_effects[j];
			if (required_effect_id != effect_id && !entity_status_map.has(required_effect_id)) {
				all_ingredients_present = false;
				break;
			}
		}

		if (all_ingredients_present) {
			candidate_recipes.append(recipe);
		}
	}
	if (candidate_recipes.size() > 0) {
		Ref<Recipe> best_recipe = candidate_recipes[0];
		for (int i = 1; i < candidate_recipes.size(); i++) {
			Ref<Recipe> current = candidate_recipes[i];
			if (current->get_priority() > best_recipe->get_priority()) {
				best_recipe = current;
			}
		}
		for (int i = 0; i < best_recipe->get_input_effects().size(); i++) {
			String consumed_id = best_recipe->get_input_effects()[i];
			if (i < best_recipe->get_consumed_effects().size() && (bool)best_recipe->get_consumed_effects()[i] && consumed_id != effect_id) {
				if (entity_status_map.has(consumed_id)) {
					StatusEffect* effect_node = Object::cast_to<StatusEffect>(entity_status_map[consumed_id]);
					if (effect_node) {
						effect_node->queue_free();
					}
				}
			}
		}
		for (int i = 0; i < best_recipe->get_output_effects().size(); i++) {
			add_status_effect(entity, best_recipe->get_output_effects()[i]);
		}
	}
	else {
		Variant recipe_scene_variant = StatusEffectDictionary.get(effect_id, "");
		Ref<PackedScene> recipe_scene = recipe_scene_variant;

		if (recipe_scene.is_valid()) {
			Node* new_effect_node = recipe_scene->instantiate();
			if (new_effect_node) {
				entity->add_child(new_effect_node);
			}
		}
	}
}