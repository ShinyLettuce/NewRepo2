#pragma once
#include "raylib.h"

class Tile_system
{
public:
	static const int size = 64;
	const int cols = 8;
	const int rows = 8;
	int tiles[64] = { 1,1,1,1,1,1,1,1
					 ,1,0,0,0,0,0,0,1
					 ,1,0,0,0,0,0,0,1
					 ,1,0,0,0,0,0,0,1
					 ,1,0,0,0,0,0,0,1
					 ,1,0,0,0,0,0,0,1
					 ,1,0,0,0,0,0,0,1
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

};

const enum face_directions
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Entity
{
private:

public:
	Vector2 position = { 16,16 };
	int size = 32;
	int face_directions = UP;
	int tile_position_index = 0;

	virtual void render()
	{
	}

	virtual void update()
	{
	}

};

class Box : public Entity
{
public:
	void render();
	void update();
};

class Player : public Entity
{
public:
	void render();
	void update();
};

class Level
{
public:
	Tile_system tiles;
	Player mario;
	Box boxxo;

	void level_init();
	void level_update();
	void level_render();
};