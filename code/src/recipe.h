#pragma once

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/typed_array.hpp>

namespace godot 
{

class Recipe : public Resource 
{
    GDCLASS(Recipe, Resource)

private:
	TypedArray<StringName> input_effects;
	TypedArray<bool> consumed_effects;
	TypedArray<StringName> output_effects;
	int priority = 0;

protected:
    static void _bind_methods();

public:

	// Input Effects
    void set_input_effects(const TypedArray<StringName>& arr);
    TypedArray<StringName> get_input_effects() const;

    // Consumed Effects
    void set_consumed_effects(const TypedArray<bool>& arr);
    TypedArray<bool> get_consumed_effects() const;

    // Output Effects
    void set_output_effects(const TypedArray<StringName>& arr);
    TypedArray<StringName> get_output_effects() const;

    // Priority
    void set_priority(int p);
    int get_priority() const;
};

}
