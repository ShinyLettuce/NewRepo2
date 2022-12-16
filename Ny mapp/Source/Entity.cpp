#pragma once
#include "Entity.h"

void Box::render()
{
	float pixel_x = (position.x * 64) + 16;
	float pixel_y = (position.y * 64) + 16;

	DrawTexture(flower, (int)pixel_x, (int)pixel_y, WHITE);
}

void Player::render()
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

void Player::update()
{
	if (IsKeyPressed(KEY_RIGHT))
	{
		input = { 1,0 };
		face_directions = RIGHT;
		PlaySoundMulti(beeMove);
	}

	if (IsKeyPressed(KEY_LEFT))
	{
		input = { -1, 0 };
		face_directions = LEFT;
		PlaySoundMulti(beeMove);
	}

	if (IsKeyPressed(KEY_DOWN))
	{
		input = { 0, 1 };
		face_directions = DOWN;
		PlaySoundMulti(beeMove);
	}

	if (IsKeyPressed(KEY_UP))
	{
		input = { 0,-1 };
		face_directions = UP;
		PlaySoundMulti(beeMove);
	}
}