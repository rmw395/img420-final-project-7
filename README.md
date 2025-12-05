# Waking of the Witch

Demo Video: https://youtu.be/A17S75Z1WUE

## Module ##
The module that we created for this assignment is a modular method of applying `StatusEffects` to `Entities`, and facilitating interactions between those `StatusEffects`.

### Why? ###
We believe that making tools for designers to ease the creation of great games is the goal of creating a low level module. By creating a module, you are making the declaration that you don't need to see underlying structures and can instead trust what is going on behind the scenes to work in the way that is expected. This is why we have many existing nodes within Godot that abstract underlying behavior like `RigidBody2D` `CharacterBody2D` or `Camera2D`.

We have been able to acheive this goal by making it so that the `Entities`, `StatusEffects`, and their interactions happen with very little effort and in a user friendly manner, where every variable you would want to change about how a `StatusEffect` works is revealed to the user all within the Godot editor, and doesn't demand high competency in the specific module, so anyone can begin using this module quickly after picking it up.

Along with the designer concerns, we are able to make performance enhancements because the increased amount of computation behind the scenes, and the search algorithm that has to run when `StatusEffects` are applied to check for applicable `Recipes` are sources of slowdown if it were implemented into the project using something like GDScript or C#.

### Overview ###
This module contains a few new tools at the disposal of designers like:

#### Status Effects ####
This is the basis for everything in the module, and you simply need to create a scene, modify your attributes, and give it a name, save it into the dedicated folder location you define in the project settings *(search "InteractionManager" in project settings)*, then it is ready for use everywhere else.

#### Entities ####
This is the universal interface that `StatusEffects` operate on, so whether it is an enemy or a player, `StatusEffects` can work all the same and all you need to do is do with the information gathered within them from `StatusEffects` how you would like. This is also saved into a dedicated directory defined by the user.

#### Recipes ####
This is the way in which `StatusEffects` can interact with each other. You can define the "ingredients" for this interaction, i.e. water and fire, define which "ingredients" you would like consumed on use, then which `StatusEffects` you would like to be created through the interface, along with identifying a priority if there are multiple interaction that could happen at once in complex systems.

#### Interaction Manager ####
This is the conductor for everything going on. When you add a `StatusEffect`, you are telling this singleton to do it, and it is what keeps track of name associations for `StatusEffects`, and what `Recipes` are currently loaded into the system. This keeps the concerns of each individual piece separated where they don't need to know a lot about the surrounding systems, and then this manager is the one that keeps everything under control and contained.

## Game Overview ##
Our game is called Waking of the Witch! Waking of the Witch is a side-scrolling platformer where the main objective of the game is to reach the end of the platformer without dying while fighting off enemies and avoiding obstacles.

The game takes place in a world where magic is kept secret and separated from the mortal realm, but due to a new corrupt leadership taking control over the mortal realm, the government wants to utilize the magical realm for their own benefit. The player plays as a witch whose cat familiar got stolen by the government to power their weapons of mass destruction. To retrieve their magical partner-in-crime, the player will adventure from their home in the magical realm to the governmental base in the mortal realm where their cat familiar is being kept. 

On their journey, the player will stumble upon a variety of different areas that have their own environmental effects that the player has to take note of to bypass… The player starts off at their own abode in the magical realm. The magical realm is fairly peaceful, but hiding in the shadows lurks otherworldly entities, some dangerous others not. The realm that separates the magical and mortal realms is one of fire and incredible heat to ward off any prying mortal adventurers. To bypass, the player has to move strategically while avoiding fire and lava pits. When the player first enters the mortal realm, they exit from an ancient cave and are met with a hefty thunderstorming rainforest where they have to be careful of slipping in puddles and getting struck by lightning. To reach the government base, the player must make their way through many different biomes ranging from a dry, blazing desert to a smelly, bustling city. The government base is located in a vast tundra where the player has to be mindful of conserving their warmth and the strong wind that seems to be working with the government to prevent the player from reaching the base.

The government has also managed to create their own weapons utilizing the magic they have stolen from the magical realm. This means their attacks/bullets do not only deal damage, but are also infused with magical powers that apply their own set of `StatusEffects` on the player such as fire, poison, etc.. The player and enemies have ranged weapons (magic) to show off the `StatusEffects` module and a fast-paced combat system.
