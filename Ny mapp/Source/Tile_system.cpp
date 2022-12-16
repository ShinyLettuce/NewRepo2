#pragma once
#include "Tile_system.h"

void Tile_system::render_level(int level_order)
{
	//In order for us to create the proper tile system, we need to be able to check that created_tile is correct in the selected column (c) and row (r).
	
	int created_tile = 0;
	Color colour[3] = { GRAY, ORANGE, RAYWHITE };

	for (int c = 0; c < cols; c++)
	{
		for (int r = 0; r < rows; r++)
		{
			if (level_order == 0)
			{
				setTiles(mainMenu_);
			}

			if (level_order == 1)
			{
				setTiles(level1_);
			}
			if (level_order == 2)
			{
				setTiles(level2_);
			}
			if (level_order == 3)
			{
				setTiles(level3_);
			}
			if (level_order == 4)
			{
				setTiles(level4_);
			}
			if (level_order == 5)
			{
				setTiles(level5_);
			}
			if (level_order == 6)
			{
				setTiles(level6_);
			}

			int type = tiles[created_tile];

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

void Tile_system::setTiles(int tiles_[])
{
	for (int i = 0; i < 64; i++)
	{
		tiles[i] = tiles_[i];
	}
}