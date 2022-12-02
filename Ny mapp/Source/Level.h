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
	Vector2 position = { 1.f,1.f };
	int size = 32;
	int face_directions = UP;
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
	void move(Box& b, Vector2 input);
};

class Player : public Entity
{
public:
	void render();
	void update();
	void move(Player& p, Vector2 input);
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