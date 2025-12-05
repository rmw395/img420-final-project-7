# API Reference #

This module provides a robust system for managing complex entity statistics, status effects, and their interactions (interactions/recipes) within a Godot project.

---

## Entity ##

**Inherits:** `CharacterBody2D` < `PhysicsBody2D` < `CollisionObject2D` < `Node2D` < `CanvasItem` < `Node` < `Object`

A specialized physics body that manages complex statistics through a system of base values, multipliers, and offsets.

### Description ###

The `Entity` class extends the standard `CharacterBody2D` to include a comprehensive stat system. It allows for stats (like speed, health, damage) to be modified dynamically by `StatusEffect` nodes. It separates stats into **Base** (the inherent stat), **Multiplier** (percentage modifiers), and **Offset** (flat additions), which combine to form the **Final** read-only stats used during gameplay logic.

### Properties ###

| Type | Name | Default | Description |
| :--- | :--- | :--- | :--- |
| `float` | `health` | `100.0` | Current health of the entity. |
| `bool` | `invulnerable` | `false` | If true, the entity ignores incoming damage unless the damage source bypasses invulnerability. |
| | **Final Stats (Read-Only)** | | |
| `float` | `max_health` | `100.0` | `base * multiplier + offset`. |
| `float` | `max_speed` | `300.0` | `base * multiplier + offset`. |
| `float` | `acceleration` | `1500.0` | `base * multiplier + offset`. |
| `float` | `damage` | `10.0` | `base * multiplier + offset`. |
| `float` | `defense` | `0.0` | `base * multiplier + offset`. |
| `float` | `ground_friction` | `800.0` | `base * multiplier + offset`. |
| `float` | `air_friction` | `200.0` | `base * multiplier + offset`. |

> **Note:** The `Entity` class also exposes individual `base_`, `_multiplier`, and `_offset` properties for every stat listed above (e.g., `base_max_health`, `max_health_multiplier`, `max_health_offset`). These are primarily accessed by status effects in order to do their calculations, but there could be valid reasons for modifying them manually in code. These are used to calculate the Final Stats.

### Methods

| Return | Name | Arguments |
| :--- | :--- | :--- |
| `void` | `move` | `Vector2 velocity` |
| `void` | `update_values` | | |
| `void` | `set_health` | `float value` |
| `float` | `get_health` | | |
| `void` | `set_invulnerable` | `bool value` |
| `bool` | `get_invulnerable` | | |

### Signals

* **damage** ( `float` damage_amount, `Vector2` knockback, `bool` bypass )
    * Emitted when the entity processes a damage event. This damage function and the susequent on_damage_effect signal is not sent if the entity has `invulnerable` set to `true`.
* **d0_damage_effect** ( `float` damage_amount, `Vector2` knockback, `bool` bypass )
    * Emitted after the entity processes a damage event through the damage function. This signal is primarily used as a hook into causing something else to happen when an entity takes damage, like making the entity have a hit flash, or setting them to be invulnerable.
* **heal** ( `float` heal_amount )
    * Emitted when the entity processes a healing event.

### Method Descriptions

* **move** ( `Vector2` velocity )
    * Moves the entity with the given velocity. This method automatically applies the entity's current `velocity.multiplier` and `velocity.offset` (derived from active status effects) before calling `move_and_slide()`.

* **update_values** ( )
    * Forces a recalculation of all Final Stats based on the current Base, Multiplier, and Offset values. This is typically called automatically when a setter is used.

---

## StatusEffect

**Inherits:** `Node2D` < `CanvasItem` < `Node` < `Object`

A component that applies modifiers to an `Entity` parent.

### Description

A `StatusEffect` is intended to be added as a child of an `Entity`. Upon entering the tree, it modifies the parent Entity's stats (Health, Mobility, Combat) by adding to their multipliers or offsets. When removed from the tree, it reverses these changes. It can also handle periodic health changes (poison/regen) and transitions into other effects after a duration.

### Properties

| Type | Name | Default | Description |
| :--- | :--- | :--- | :--- |
| `String` | `id` | `""` | Unique identifier for this effect. Used by `Recipe`s and `InteractionManager`. This allows for referencing status effects by name in calls instead of needing to know the precise scene. |
| `float` | `duration` | `0.0` | Lifetime of the effect in seconds.|
| `bool` | `bypass_invulnerability` | `false` | If true, health changes from this effect ignore the parent's invulnerability, this is useful for if you want to have a rapid decay in health and don't want it to be blocked by some other action, or potentially block other interactions based on the implementation. |
| | **Health Modifiers** | | |
| `float` | `max_health_multiplier` | `0.0` | Adds to the parent's max health multiplier. |
| `float` | `max_health_offset` | `0.0` | Adds to the parent's max health flat value. |
| `float` | `health_change` | `0.0` | Amount of health to add (positive) or remove (negative) per interval. |
| `float` | `health_change_interval` | `0.0` | Time in seconds between health change ticks. |
| | **Mobility Modifiers** | | |
| `float` | `max_speed_multiplier` | `0.0` | Modifies top speed. |
| `float` | `max_speed_offset` | `0.0` | Modifies top speed. |
| `float` | `velocity_multiplier` | `0.0` | Multiplies the input velocity provided to `Entity.move()`. |
| `Vector2`| `velocity_offset` | `(0,0)` | Adds to the input velocity provided to `Entity.move()`. |
| `float` | `acceleration_multiplier`| `0.0` | Modifies acceleration. |
| `float` | `acceleration_offset` | `0.0` | Modifies acceleration. |
| `float` | `ground_friction_...` | `0.0` | Multipliers and offsets for ground friction. |
| `float` | `air_friction_...` | `0.0` | Multipliers and offsets for air friction. |
| | **Combat Modifiers** | | |
| `float` | `damage_multiplier` | `0.0` | Modifies the entity's output damage. |
| `float` | `damage_offset` | `0.0` | Modifies the entity's output damage. |
| `float` | `percent_defense` | `0.0` | Adds to the parent's defense multiplier. |
| `float` | `flat_defense` | `0.0` | Adds to the parent's defense offset. |
| | **Transitions** | | |
| `String` | `transition_effect_id` | `""` | The ID of the effect to apply when this effect expires. |
| `float` | `transition_interval` | `0.0` | Time in seconds before the transition occurs. |

### Methods

This class primarily uses getters and setters exposed via the Properties above. The `_physics_process` is used internally to handle duration timers and periodic health changes.

---

## Recipe

**Inherits:** `Resource` < `RefCounted` < `Object`

Defines rules for how `StatusEffects` interact and combine.

### Description

`Recipes` are Resources used by the `InteractionManager`. They are responsible for defining that if a specific set of effects exists under an `Entity` (`input_effects`) then some resulting thing will happen, whether it is the destruction of existing effects, or the addition of the effects in `output_effects`.
### Properties

| Type | Name | Default | Description |
| :--- | :--- | :--- | :--- |
| `Array[String]` | `input_effects` | `[]` | A list of StatusEffect IDs required on the Entity for this recipe to trigger. |
| `Array[bool]` | `consumed_effects` | `[]` | Corresponds to the effect in `input_effects` at the same index. If `true`, the corresponding input effect is removed when the recipe triggers. |
| `Array[String]` | `output_effects` | `[]` | A list of StatusEffect IDs to apply to the Entity if the recipe triggers. |
| `int` | `priority` | `0` | If multiple recipes match the current state, the one with the highest priority is chosen. |

---

## InteractionManager

**Inherits:** `Object`

A Singleton manager that handles the logic of adding status effects and processing recipes.

### Description

The `InteractionManager` is automatically registered as a Singleton in Godot. It caches `StatusEffect` scenes and `Recipe` resources at startup. When an effect is applied to an entity, this manager checks if any Recipes should trigger (combining existing effects with the new one) or if the effect should simply be added.

**Project Settings:**
The manager looks for two custom Project Settings to locate assets:
* `interaction_manager/recipe_file_path`: (Default: `res://recipes`)
* `interaction_manager/status_effect_file_path`: (Default: `res://status_effects`)

### Methods

| Return | Name | Arguments |
| :--- | :--- | :--- |
| `void` | `add_status_effect` | `Entity* entity`, `String effect_id`, `double duration = 0.0` |
| `void` | `load_recipes` | | |
| `void` | `load_status_effects` | | |

### Method Descriptions

* **add_status_effect** ( `Entity` entity, `String` effect_id, `double` duration = 0.0 )
    * Attempts to add a status effect to the specified Entity. This can express itself in many ways, like refreshing the duration of an already existing status effect if a match is found, starting a reaction based on a recipe defined by the developer, or simply getting added as a child to an `Entity` node.

* **load_recipes** ( )
    * Scans the directory defined in Project Settings for `.tres` or `.res` files, casting them to `Recipe` and adding them to the internal index. Called automatically on the first call of `add_status_effect` by the developer.

* **load_status_effects** ( )
    * Scans the directory defined in Project Settings for `.tscn` or `.scn` files. It instances them temporarily to read their `id` property, mapping the ID to the PackedScene for future instantiation. Called automatically on the first call of `add_status_effect` by the developer.