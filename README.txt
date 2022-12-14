# Group number: 1;
Bee Game

Group Members (roles):
Erik Nikiforov (Quality Assurance)
Jacob Engelhardt (Lead Programmer)
Nom Köhler (Art Design and Graphics Programmer)

The game is based on Sokoban clone by lawric (https://lawric.itch.io/sokoban).
The player controls a bee and the goal of each level is to push flowers into flower places.
The game has five different levels, each one getting progressively harder and introducing one new mechanic of the game, represented by the yellow tile.

Link to the repository:
https://github.com/ShinyLettuce/NewRepo2

Tile based game play mechanics, movements and the main menu were based on Jacob's initial code.
Art and texture loading were based on Nom's initial code.
Logic of level's flower data storage, flower movement and victory conditions were based on Erik's initial code.
In the end product, every group member had a role on optimizing and merging additions to match the wanted outcome.
Levels from 1-5 were based on Sokoban or original designs by Nom, and optimized by each group member.
Level 6 was designed from scratch as a collaboration with all team members.


Controls:
Arrow keys - move the bee
Delete - restart the level
Home - return to the level selection screen

Tiles:
Brown - accessed by the bee and flowers
Yellow - accessed only by the bee
Flower Button - accessed by the bee and flowers, activated by flowers on them
Orange - unaccessable

All art used in the game is made by Nom.
All assets used in the game are not stored in their own folder due to issues of understanding how GitHub works.

Sound Design:
Bee's movement - Nom's voice
Flower's failed movement and the level victory screen - Erik's voice
Other sounds:
Downloaded from https://pixabay.com/sound-effects/

Code logic:
(Tile system)
The game's 8x8 tile system is based on an array with 64 elements, every index represents a tile in the game and contains
a value that decides its properties. The array "tiles" decides what is being rendered on screen and when the rendered tile system changes, "tiles" gets
overwritten with one of the stored arrays in the Tile_system class. 

Flower buttons were used as part of a tile system instead of being own entity due to learning process, the plan was to optimize the idea but the deadline hit too soon.
As it works, it works.

(Game states: levels, main menu)
The main menu, the gameplay and the win screen are managed by a stack in main.cpp that pushes and pops the different game states. When the player moves to a level from
the main menu, the variable "level_order" is changed accordingly which affects what level is drawn, how many flowers are rendered and the position of all entities.
There are two initializing functions, game_init and level_init, the first one initializes the game itself and the main menu while the other one initialized the levels.

