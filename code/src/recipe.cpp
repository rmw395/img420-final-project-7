#include "recipe.h"

using namespace godot;

void Recipe::_bind_methods() 
{
    // Input Effects
    ClassDB::bind_method(D_METHOD("set_input_effects", "effects"), &Recipe::set_input_effects);
    ClassDB::bind_method(D_METHOD("get_input_effects"), &Recipe::get_input_effects);

    ClassDB::add_property(
        Recipe::get_class_static(),
        PropertyInfo(Variant::ARRAY, "input_effects", PROPERTY_HINT_ARRAY_TYPE, "String"),
        "set_input_effects",
        "get_input_effects"
    );

    // Consumed Effects
    ClassDB::bind_method(D_METHOD("set_consumed_effects", "consumed"), &Recipe::set_consumed_effects);
    ClassDB::bind_method(D_METHOD("get_consumed_effects"), &Recipe::get_consumed_effects);

    ClassDB::add_property(
        Recipe::get_class_static(),
        PropertyInfo(Variant::ARRAY, "consumed_effects", PROPERTY_HINT_ARRAY_TYPE, "bool"),
        "set_consumed_effects",
        "get_consumed_effects"
    );

    // Output Effects
    ClassDB::bind_method(D_METHOD("set_output_effects", "effects"), &Recipe::set_output_effects);
    ClassDB::bind_method(D_METHOD("get_output_effects"), &Recipe::get_output_effects);

    ClassDB::add_property(
        Recipe::get_class_static(),
        PropertyInfo(Variant::ARRAY, "output_effects", PROPERTY_HINT_ARRAY_TYPE, "String"),
        "set_output_effects",
        "get_output_effects"
    );

    // Priority
    ClassDB::bind_method(D_METHOD("set_priority", "value"), &Recipe::set_priority);
    ClassDB::bind_method(D_METHOD("get_priority"), &Recipe::get_priority);

    ClassDB::add_property(
        Recipe::get_class_static(),
        PropertyInfo(Variant::INT, "priority"),
        "set_priority",
        "get_priority"
    );
}

// input effects set and get
void Recipe::set_input_effects(const TypedArray<String>& arr) {
    input_effects = arr;
}

TypedArray<String> Recipe::get_input_effects() const {
    return input_effects;
}

// consumed effects set and get
void Recipe::set_consumed_effects(const TypedArray<bool>& arr) {
    consumed_effects = arr;
}

TypedArray<bool> Recipe::get_consumed_effects() const {
    return consumed_effects;
}

// output effects set and get
void Recipe::set_output_effects(const TypedArray<String>& arr) {
    output_effects = arr;
}

TypedArray<String> Recipe::get_output_effects() const {
    return output_effects;
}

// priority effects set and get
void Recipe::set_priority(int p) {
    priority = p;
}

int Recipe::get_priority() const {
    return priority;
}

