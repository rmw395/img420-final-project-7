#include "register_types.h"
#include "interaction_manager.h"
#include "status_effect.h"
#include "recipe.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/project_settings.hpp>

using namespace godot;

static InteractionManager* s_interaction_manager_singleton = nullptr;

void initialize_library_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	ProjectSettings* ps = ProjectSettings::get_singleton();
	ps->add_property_info(PropertyInfo(
		Variant::NIL, "interaction_manager/", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_CATEGORY
	));
	ps->set_setting("interaction_manager/recipe_file_path", String("res://recipes"));
	ps->add_property_info(PropertyInfo(
		Variant::STRING, "interaction_manager/recipe_file_path", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT
	));
	ps->set_setting("interaction_manager/status_effect_file_path", String("res://recipes"));
	ps->add_property_info(PropertyInfo(
		Variant::STRING, "interaction_manager/status_effect_file_path", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT
	));
	GDREGISTER_RUNTIME_CLASS(StatusEffect);
	s_interaction_manager_singleton = memnew(InteractionManager);
	Engine::get_singleton()->register_singleton("InteractionManager", s_interaction_manager_singleton);
	s_interaction_manager_singleton->_initialize();
	GDREGISTER_RUNTIME_CLASS(Recipe);
}

void uninitialize_library_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	Engine::get_singleton()->unregister_singleton("InteractionManager");
	memdelete(s_interaction_manager_singleton);
	s_interaction_manager_singleton = nullptr;
}

extern "C" {
	// Initialization.
	GDExtensionBool GDE_EXPORT library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization* r_initialization) {
		godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(initialize_library_module);
		init_obj.register_terminator(uninitialize_library_module);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}