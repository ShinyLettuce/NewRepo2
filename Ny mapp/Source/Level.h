#pragma once
#include <vector>
#include "raylib.h"
#include "Images.cpp"
#include "Entity.cpp"

class Tile_system
{
public:
	Images tile_images;
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

	Color GetColor(int type);
	void render_level();
	Texture2D honeycomb;
	Texture2D flower;

	void setTiles(int tiles_[])
	{
			for (int i = 0; i < 64; i++)
			{
				tiles[i] = tiles_[i];
			}

	}

};



class Level
{
	std::vector <Box> boxes_in_level = {};	
	//Texture2D flower = LoadTexture("flower.png");
	Texture2D flower = images.get_image(FLOWER);
	
	void move_player(Player& p, Vector2 input);
	bool move_box(Box & b, Vector2 input);
	int currentlvl = 0;
	int background_[64] = {		 1,1,1,1,1,1,1,1
								,1,0,0,0,0,0,0,1
								,1,0,0,0,0,0,0,1
								,1,2,0,2,0,2,0,1
								,1,0,2,0,2,0,2,1
								,1,2,0,2,0,2,0,1
								,1,0,2,0,2,0,2,1
								,1,1,1,1,1,1,1,1 };

public:
	bool isWon = false;
	Images images;

	Tile_system tiles;
	Tile_system background;

	Player mario;

	int level_order = 0; //ENI Comment: Choosing a level in MainMenu that would control the selected tile layout?


	void clear_entitylist_B();
	void add_entity_B(const Box& b);
	

	void game_init();

	void level_init();
	void level_update();

	void level_render();
};