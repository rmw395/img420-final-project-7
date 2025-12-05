# User Guide #

## Your First Status Effect ##
- Start by creating a scene and making the root node a `StatusEffect` node.
- Go to the inspector on the right-hand side of the Godot Editor and look through the attribute and see what you would like to change about an entity, and give the status effect a name.
- Save this status effect scene into your dedicated directory for status effects (by default, this is `res://status_effects`, but this can be changed in the project settings).

## Your First Entity ##
- For this, you will want to create some sort of character, maybe a player, or maybe an enemy, that you would like to be affected by the status effect you just made, or any others you might make. 
- When writing scripts for this Entity, if you would like to take advantage of the power of the module, you will need to make sure you are using the final values calculated for you when you do things.
- For example, you don't want to or need to define your own variable for acceleration (and you can change the base settings for this and other stats on the left), instead you can retrieve the value from your entity using the `get_acceleration()` function. <br>**Note**: GDExtension does not support calling these function directly, you will need to use `Call("get_acceleration")` and convert the result into a float directly since it returns a Variant.
- Now that you have written a script that utilizes all of the variables held by the `Entity` class and modified by the `StatusEffect` class, you are ready to move forward.

## Adding a Status Effect ##
- When adding a status effect, you will first want to gain a reference to the `InteractionManager`. This can be done in a script using `Engine.GetSingleton("InteractionManager");` and applying that to a variable of type `GodotObject` to use later.
- Then, in any case where you want to apply a status effect, you will want to use the command `*(InteractionManager variable)*.Call("add_status_effect", *(Entity node)*, *(name of status effect)*);` which might look like `_interactionManager.Call("add_status_effect", GetNode("Player"), "fire");`.

## Your First Recipe ##
- If you want to get full use out of this module, you won't want to stop at just having a straight forward status effect system where status effects simply stack and don't react to each other, and that is where `Recipes` come in.
- To get started, make a directory that will hold you directories as defined in your project settings (by default, this is `res://recipes`) and then right click on that folder, click `New Resource`, and find the resource named `Recipe`.
- Now that you have this new recipe, you are able to define some attributes on the right-hand side of the screen. 
- You will want to put the "ingredient" status effects for this recipe into the `input_status_effects` array, and you will want to indicate if you want those status effects to be removed when the recipe is invoked through the `consumed_status_effects` array. 
- If you want a new status effect to appear from this recipe, you will define that in the `output_status_effects` array.
- If multiple recipes might happen from anm added status effect, you will want to explicitly state the priority of interactions with the priority value, where higher means it will be prioritized over other recipes that could happen.
- That's it, no code needing to be written from you, now if that recipe happens, that recipe will be invoked with little effort from you.'

## Your Turn ##
Now that you have worked through this and done the basics, push this system to its limits, create large trees of interconnecting recipes that affect gameplay in exciting ways, the possiblities are endless and the potential for emergent systems of alchemy with status effects is huge.