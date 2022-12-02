#include "raylib.h"
#include "Level.h"
#include <list>


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
	float pixel_x = (position.x * 64) + 16;
	float pixel_y = (position.y * 64) + 16;
	DrawRectangle((int)pixel_x, (int)pixel_y, size, size, BROWN);
}

void Box::update()
{
	
}


void Player::render()
{
	float pixel_x = (position.x * 64) + 16;
	float pixel_y = (position.y * 64) + 16;
	DrawRectangle((int)pixel_x, (int)pixel_y, size, size, RED);
}

void Player::update()
{
	
	if (IsKeyPressed(KEY_RIGHT))
	{
		input = { 1,0 };
	}

	if (IsKeyPressed(KEY_LEFT))
	{
		input = { -1, 0 };
	}

	if (IsKeyPressed(KEY_DOWN))
	{
		input = { 0, 1 };
	}

	if (IsKeyPressed(KEY_UP))
	{
		input = { 0,-1 };
	}
}
/*
void Level::clear_entitylist_B()
{
	boxes_in_level.clear();
}

void Level::add_entity_B(const Box& b)
{
	boxes_in_level.push_back(b);
}
*/

void Level::level_init()
{
	//TODO: make Vector that stores all created Entities in the level so the movement check could work better.
	//boxes_in_level.clear();

	mario.position = { 2,2 };
		
	boxxo.position = { 2,3 };
	//add_entity_B(boxxo);
}

void Level::level_update()
{
	if (IsKeyPressed(KEY_DELETE))
	{
		level_init();
	}
	mario.update();

	move_player(mario, mario.input);
	mario.input = { 0,0 };
}

void Level::move_player(Player& p, Vector2 input)
{
	float newposx = mario.position.x + input.x;
	float newposy = mario.position.y + input.y;
	
	if (newposx == boxxo.position.x && newposy == boxxo.position.y)
	{
		move_box(boxxo, input);
	}
	
	if (tiles.tiles[( (int)newposx + (8 * (int)newposy) ) ] != 1 )
	{
		p.position.x += input.x;
		p.position.y += input.y;
	}
	return;
}

void Level::move_box(Box& b, Vector2 input)
{
	float newposx = boxxo.position.x + input.x;
	float newposy = boxxo.position.y + input.y;


	if (tiles.tiles[((int)newposx + (8 * (int)newposy))] != 1)
	{
		b.position.x += input.x;
		b.position.y += input.y;
	}
}

void Level::level_render()
{
	tiles.render_level();
	mario.render();
	boxxo.render();
}
