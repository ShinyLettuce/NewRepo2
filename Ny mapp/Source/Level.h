#pragma once
#include <vector>
#include "raylib.h"
#include "Images.cpp"
#include "Entity.cpp"
#include "Tile_system.cpp"


class Level
{
	std::vector <Box> boxes_in_level = {};
	Texture2D flower = images.get_image(FLOWER);
	Sound pushBox;
	
	void move_player(Player& p, Vector2 input);
	void boxes_winning(Box& b, int level_order);
	bool move_box(Box & b, Vector2 input);
	int currentlvl = 0;

public:
	int boxes_on_switch = 0;
	bool isWon = false;
	Media images;

	Tile_system tiles;
	Player mario;

	int level_order = 0; 


	void clear_entitylist_B();
	void add_entity_B(const Box& b);
	

	void game_init();

	void level_init();
	void level_update();

	void level_render();
};