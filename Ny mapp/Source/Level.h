#pragma once
#include <vector>
#include "raylib.h"
#include "Media.h"
#include "Entity.h"
#include "Tile_system.h"


class Level
{
	//Everything that the level should use but not the main menu is in the private part.
	std::vector <Flower> flowers_in_level = {};
	Sound hurraa;
	Sound beebg;
	Sound pushFlower;
	Sound failFlower;

	int flowers_on_switch = 0;
	
	void create_flower(Vector2 position);
	void move_player(Player& p, Vector2 input);
	void flowers_and_winning(Flower& b, int level_order);
	bool move_flower(Flower & b, Vector2 input);
	void clear_entitylist_Flower();
	void add_entity_Flower(const Flower& b);	

public:	
	//Everything that the main menu should pass to level is public.
	Media images;
	Tile_system tiles;
	Player playerBee;
	
	int level_order = 0;
	bool isWon = false;	

	void game_init();
	void media_loading();

	void level_init();
	void level_update();

	void level_render();
};