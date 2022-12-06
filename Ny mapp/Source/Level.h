#pragma once
#include <list>
#include "raylib.h"

class Tile_system
{
public:
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

	/*
					  1,0,1,0,1,0,1,0
					 ,0,1,0,1,0,1,0,1
					 ,1,0,1,0,1,0,1,0
					 ,0,1,0,1,0,1,0,1
					 ,1,0,1,0,1,0,1,0
					 ,0,1,0,1,0,1,0,1
					 ,1,0,1,0,1,0,1,0
					 ,0,1,0,1,0,1,0,1
	*/

	Color GetColor(int type);
	void render_level();
	Texture2D honeycomb = LoadTexture("beehive-tiles.png");

};

/*
const enum face_directions
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
*/

class Entity
{
private:

public:
	Vector2 position = { 1.f,1.f };
	int size = 32;
	//int face_directions = UP;
	int tile_position_index = 0;

	virtual void render()
	{
	}

	virtual void update()
	{
	}

	virtual void move()
	{
	}

};

class Box : public Entity
{
public:
	void render();
	void update();
	Texture2D flower = LoadTexture("flower.png");
};

class Player : public Entity
{
public:
	Vector2 input = { 0,0 };
	Texture2D Bee = LoadTexture("beePlayer1.png");

	void render();
	void update();
	
};

class Level
{
	//std::list <Box> boxes_in_level = {};	
	void move_player(Player& p, Vector2 input);
	bool move_box(Box & b, Vector2 input);

public:
	Tile_system tiles;
	Player mario;
	Box boxxo;


	/*
	void clear_entitylist_B();
	void add_entity_B(const Box& b);
	*/

	void level_init();
	void level_update();

	void level_render();
};