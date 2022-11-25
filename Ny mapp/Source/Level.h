#pragma once
#include "raylib.h"

class Tile_system
{
public:
	static const int size = 64;
	const int cols = 8;
	const int rows = 8;
	int tiles[64] = { 2,2,2,2,2,2,2,2
					 ,2,0,0,0,0,0,0,2
					 ,2,1,0,0,0,0,0,2
					 ,2,0,0,0,0,0,0,2
					 ,2,0,0,0,0,0,0,2
					 ,2,0,0,0,0,0,0,2
					 ,2,0,0,0,0,0,0,2
					 ,2,2,2,2,2,2,2,2 };

	Color GetColor(int type);
	void render_level();

};

class Entity
{
public:
	Vector2 position = { 16,16 };

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
	Player mario;
	Box boxxo;
	Tile_system tiles;

	void level_init();
	void level_update();
	void level_render();
};