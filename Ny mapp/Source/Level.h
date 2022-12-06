#pragma once
#include <vector>
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

	Color GetColor(int type);
	void render_level();
	Texture2D honeycomb = LoadTexture("beehive-tiles.png");
	Texture2D flower = LoadTexture("flower.png");

	void setTiles(int tiles_[])
	{
			for (int i = 0; i < 64; i++)
			{
				tiles[i] = tiles_[i];
			}

	}

};

//const enum face_directions
//{
//	UP,
//	DOWN,
//	LEFT,
//	RIGHT
//};


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
	int dir = 0;
	Texture2D Bee = LoadTexture("beePlayer1.png");




	void render();
	void update();
	
};

class Level
{
	std::vector <Box> boxes_in_level = {};	
	Texture2D flower = LoadTexture("flower.png");
	//std::list <Box> boxes_in_level = {};	
	void move_player(Player& p, Vector2 input);
	bool move_box(Box & b, Vector2 input);
	bool startmenu = true;
	bool isWon = false;
	int currentlvl = 0;
	int background_[64] = {		1,1,1,1,1,1,1,1
								,1,0,0,0,0,0,0,1
								,1,0,0,0,0,0,0,1
								,1,2,0,2,0,2,0,1
								,1,0,2,0,2,0,2,1
								,1,2,0,2,0,2,0,1
								,1,0,2,0,2,0,2,1
								,1,1,1,1,1,1,1,1 };

public:
	Tile_system tiles;
	Tile_system background;


	Player mario;
	//Box boxxo;

	int level_order = 0;


	void clear_entitylist_B();
	void add_entity_B(const Box& b);
	

	void level_init();
	void level_update();

	void level_render();
};