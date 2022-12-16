#pragma once
#include "Tile_system.h"

void Tile_system::render_level()
{
	// In order for us render the levels, we go through each row (r) and column (c) of tiles[] and render each
	// and depending on what type it is (number in the array) it renders different type of tile (floor, wall, etc)
	// Since our game is completely based on tiles this was the easiest way to render the background / layouts
	
	int created_tile = 0;
	int type;
	Color colour[3] = { GRAY, ORANGE, RAYWHITE };

	for (int c = 0; c < cols; c++)
	{
		for (int r = 0; r < rows; r++)
		{
			type = tiles[created_tile];

			if (type == 3)
			{
				DrawTexture(honeycomb, 0 + size * r, 0 + (size * c), GRAY);
				DrawTexture(flower, 16 + 64 * r, 16 + 64 * c, DARKGRAY);
			}
			else
			{
				DrawTexture(honeycomb, 0 + size * r, 0 + (size * c), colour[type]);
			}

			created_tile++;
		}
	}
}


// In order to use more then one level, we need to have several arrays of the different levels, and a way to change between them.
// setTiles() is  a function that replaces the old layout with the new level tiles in the tiles[] array.

void Tile_system::setTiles(int activelevel)
{
	int* levels[7] = { mainMenu_, level1_, level2_, level3_, level4_, level5_, level6_ };

	int* newTiles = levels[activelevel];

	for (int i = 0; i < 64; i++)
	{
		tiles[i] = newTiles[i];
	}
}