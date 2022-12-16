#pragma once
#include <vector>
#include "raylib.h"
#include "Media.h"
#include "Entity.h"
#include "Tile_system.h"


class Level
{
	std::vector <Flower> flowers_in_level = {};
	Texture2D flower = images.get_image(FLOWER);
	Sound pushFlower;
	Sound failFlower;
	
	void move_player(Player& p, Vector2 input);
	void flowers_and_winning(Flower& b, int level_order);
	bool move_flower(Flower & b, Vector2 input);
	int currentlvl = 0;

public:
	int flowers_on_switch = 0;
	bool isWon = false;
	Media images;

	Tile_system tiles;
	Player playerBee;

	int level_order = 0; 


	void clear_entitylist_B();
	void add_entity_Flower(const Flower& b);
	

	void game_init();
	void media_loading();

	void level_init();
	void level_update();

	void level_render();
};