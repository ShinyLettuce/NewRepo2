#pragma once
#include "raylib.h"
#include "Media.h"

const enum face_directions
{
	UP,
	RIGHT,
	DOWN,
	LEFT
};

class Entity
{
public:
	Media entity_images;
	Vector2 position = { 1.f,1.f };	
	int face_directions = UP;

	virtual void render()
	{
	}

	virtual void update()
	{
	}
};

class Flower : public Entity
{
public:
	Texture2D flower;
	bool on_a_button = false;

	void render();
};

class Player : public Entity
{
public:
	Vector2 input = { 0,0 };
	Texture2D Bee;
	Sound beeMove;

	void render();

	void update();

};
