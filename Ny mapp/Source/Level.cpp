#include "raylib.h"
#include "Level.h"


Color Tile_system::GetColor(int type)
{
	if (type == 2)
	{
		return { GRAY };
	}
	else if (type == 1)
	{
		return { WHITE };
	}
	else
		return{ BLACK };
}

void Tile_system::render_level()
{
	int allyourbase = 0;

	for (int c = 0; c < cols; c++)
	{
		for (int r = 0; r < rows; r++)
		{
			int  type = tiles[allyourbase];
			DrawRectangle(0 + size * r, 0 + (size * c), size, size, GetColor(type));

			allyourbase++;
		}
	}
}


void Box::render()
{
	DrawRectangle((int)position.x, (int)position.y, size, size, BROWN);
}

void Box::update()
{
	switch (face_directions)
	{
	case RIGHT:
		position.x += 64.f;
		break;
	case LEFT:
		position.x -= 64.f;
		break;
	case DOWN:
		position.y += 64.f;
		break;
	case UP:
		position.y -= 64.f;
		break;
	}
}

void Player::render()
{
	DrawRectangle((int)position.x, (int)position.y, size, size, RED);
}

void Player::update()
{
	switch (face_directions)
	{
	case RIGHT:
		position.x += 64.f;
		break;
	case LEFT:
		position.x -= 64.f;
		break;
	case DOWN:
		position.y += 64.f;
		break;
	case UP:
		position.y -= 64.f;
		break;
	}
}

void Level::level_init()
{
	mario.position = { 80,80 };
	boxxo.position = { 80,144 };
}

void Level::level_update()
{
	if (IsKeyPressed(KEY_RIGHT))
	{
		mario.face_directions = RIGHT;
		if (mario.position.x + 64.f == boxxo.position.x && mario.position.y == boxxo.position.y)
		{
			boxxo.face_directions = RIGHT;
			boxxo.update();
		}
		mario.update();
	}

	if (IsKeyPressed(KEY_LEFT))
	{
		mario.face_directions = LEFT;
		if (mario.position.x - 64.f == boxxo.position.x && mario.position.y == boxxo.position.y)
		{
			boxxo.face_directions = LEFT;
			boxxo.update();
		}
		mario.update();
	}

	if (IsKeyPressed(KEY_DOWN))
	{
		mario.face_directions = DOWN;
		if (mario.position.y + 64.f == boxxo.position.y && mario.position.x == boxxo.position.x)
		{
			boxxo.face_directions = DOWN;
			boxxo.update();
		}
		mario.update();
	}

	if (IsKeyPressed(KEY_UP))
	{
		mario.face_directions = UP;
		if (mario.position.y - 64.f == boxxo.position.y && mario.position.x == boxxo.position.x)
		{
			boxxo.face_directions = UP;
			boxxo.update();
		}
		mario.update();
	}
}

void Level::level_render()
{
	tiles.render_level();
	mario.render();
	boxxo.render();
}
