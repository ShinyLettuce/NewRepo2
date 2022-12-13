#pragma once
#include "raylib.h"
#include "Images.cpp"

const enum face_directions
{
	UP,
	RIGHT,
	DOWN,
	LEFT
};

class Entity
{
private:

public:
	Media entity_images;
	Vector2 position = { 1.f,1.f };
	int size = 32;
	int face_directions = UP;

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
	Texture2D flower;
	
	void render()
	{
		float pixel_x = (position.x * 64) + 16;
		float pixel_y = (position.y * 64) + 16;

		DrawTexture(flower, (int)pixel_x, (int)pixel_y, WHITE);
	}
};

class Player : public Entity
{
public:
	Vector2 input = { 0,0 };
	Texture2D Bee;

	void render()
	{
		Vector2 pos = { (position.x * 64) + 16, (position.y * 64) + 16 };
		switch (face_directions)
		{
		case UP:
		{
			DrawTextureEx(Bee, pos, 0.f, 1.f, WHITE);
			break;
		}
		case RIGHT:
		{
			pos.x += 32;
			DrawTextureEx(Bee, pos, 90.f, 1.f, WHITE);
			break;
		}
		case DOWN:
		{
			pos.y += 32; pos.x += 32;
			DrawTextureEx(Bee, pos, 180.f, 1.f, WHITE);
			break;
		}
		case LEFT:
		{
			pos.y += 32;
			DrawTextureEx(Bee, pos, 270.f, 1.f, WHITE);
			break;
		}
		}
	}

	void update()
	{
		if (IsKeyPressed(KEY_RIGHT))
		{
			input = { 1,0 };
			face_directions = RIGHT;
		}

		if (IsKeyPressed(KEY_LEFT))
		{
			input = { -1, 0 };
			face_directions = LEFT;
		}

		if (IsKeyPressed(KEY_DOWN))
		{
			input = { 0, 1 };
			face_directions = DOWN;
		}

		if (IsKeyPressed(KEY_UP))
		{
			input = { 0,-1 };
			face_directions = UP;
		}
	}

};