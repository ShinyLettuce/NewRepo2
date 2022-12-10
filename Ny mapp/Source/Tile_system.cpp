#pragma once
#include "raylib.h"
#include "Images.cpp"

class Tile_system
{
public:
	Images tile_images;
	Texture2D honeycomb;
	Texture2D flower;

	static const int size = 64;
	const int cols = 8;
	const int rows = 8;
	int tiles[64] = { 1,1,1,1,1,1,1,1
					 ,1,2,2,0,0,2,2,1
					 ,1,2,0,0,0,0,2,1
					 ,1,0,0,2,1,0,0,1
					 ,1,0,0,1,2,0,3,1
					 ,1,2,0,0,0,0,2,1
					 ,1,2,2,0,0,2,2,1
					 ,1,1,1,1,1,1,1,1 };

	Color GetColor(int type)
	{
		if (type == 3)
		{
			return { BLUE };
		}
		if (type == 2)
		{
			return { GRAY };
		}
		else if (type == 1)
		{
			return { WHITE };
		}
		else
			return{ BLACK };
	}
	
	void render_level()
	{
		int allyourbase = 0;
		Color colour[3] = { GRAY, ORANGE, RAYWHITE };

		for (int c = 0; c < cols; c++)
		{
			for (int r = 0; r < rows; r++)
			{
				int  type = tiles[allyourbase];
				if (tiles[allyourbase] == 3)
				{
					DrawTexture(honeycomb, 0 + size * r, 0 + (size * c), GRAY);
					DrawTexture(flower, 16 + 64 * r, 16 + 64 * c, DARKGRAY);
				}

				else
				{
					DrawTexture(honeycomb, 0 + size * r, 0 + (size * c), colour[tiles[allyourbase]]);
				}

				allyourbase++;
			}
		}
	}
	

	void setTiles(int tiles_[])
	{
		for (int i = 0; i < 64; i++)
		{
			tiles[i] = tiles_[i];
		}

	}

	void setLevelTiles()
	{
		int mainMenu_[64] = {	1,1,1,1,1,1,1,1
								,1,0,0,0,0,0,0,1
								,1,0,0,0,0,0,0,1
								,1,2,0,2,0,2,0,1
								,1,0,2,0,2,0,2,1
								,1,2,0,2,0,2,0,1
								,1,0,2,0,2,0,2,1
								,1,1,1,1,1,1,1,1 };

		int level1_[64] = {		1,1,1,1,1,1,1,1,
								1,1,1,1,1,1,1,1,
								1,1,1,1,1,1,1,1,
								1,0,0,0,0,0,3,1,
								1,0,0,0,0,0,3,1,
								1,1,1,1,1,1,1,1,
								1,1,1,1,1,1,1,1,
								1,1,1,1,1,1,1,1
		};

		int level2_[64] = { 1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 3, 0, 0, 0, 1, 1,
							1, 0, 0, 1, 1, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 1, 1, 0, 0, 1,
							1, 1, 0, 0, 0, 3, 1, 1,
							1, 1, 1, 1, 1, 1, 1, 1
		};

		int level3_[64] = { 1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 2, 3, 0, 2, 1, 1,
							1, 2, 0, 0, 0, 0, 2, 1,
							1, 3, 0, 2, 2, 0, 0, 1,
							1, 0, 0, 2, 2, 0, 3, 1,
							1, 2, 0, 0, 0, 0, 2, 1,
							1, 1, 2, 0, 3, 2, 1, 1,
							1, 1, 1, 1, 1, 1, 1, 1
		};

		int level4_[64] = { 1, 1, 1, 1, 1, 1, 1, 1,
							1, 2, 2, 2, 2, 2, 2, 1,
							1, 2, 2, 2, 2, 2, 2, 1,
							1, 2, 2, 2, 2, 2, 2, 1,
							1, 2, 2, 3, 3, 3, 2, 1,
							1, 2, 2, 2, 2, 2, 2, 1,
							1, 2, 2, 2, 2, 2, 2, 1,
							1, 1, 1, 1, 1, 1, 1, 1
		};

		int level5_[64] = { 1, 1, 1, 1, 1, 1, 1, 1,
							1, 0, 0, 0, 2, 1, 3, 1,
							1, 0, 0, 0, 2, 1, 3, 1,
							1, 0, 0, 0, 2, 1, 3, 1,
							1, 2, 2, 0, 2, 1, 0, 1,
							1, 1, 2, 0, 0, 0, 0, 1,
							1, 1, 2, 2, 2, 2, 2, 1,
							1, 1, 1, 1, 1, 1, 1, 1
		};


	}

};