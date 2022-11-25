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
		return { GREEN };
	}
	else
		return{ BLACK };
}

void Tile_system::render_level()
{
	int allyourbase = 0;
	
	for(int c = 0;c<cols;c++)
	{ 
		for (int i_2 = 0; i_2 <rows; i_2++)
		{
			int  type = tiles[allyourbase];
			DrawRectangle(0 + size * i_2, 0 + (size * c), size, size, GetColor(type));
			
			allyourbase++;
		}
	}
}


void Box::render()
{
	DrawRectangle((int)position.x, (int)position.y, 32, 32, BROWN);
}


void Player::render()
{
	DrawRectangle((int)position.x,(int)position.y, 32, 32, RED);
}

void Player::update()
{
	if (IsKeyPressed(KEY_RIGHT))
	{
		position.x += 64.f;
	}
		
	if (IsKeyPressed(KEY_LEFT))
	{
		position.x -= 64.f;
	}

	if (IsKeyPressed(KEY_DOWN))
	{
		position.y += 64.f;
	}

	if (IsKeyPressed(KEY_UP))
	{
		position.y -= 64.f;
	}
}

void Level::level_init()
{
	mario.position = { 80,80 };
	boxxo.position = { 80,144 };
}

void Level::level_update()
{
	mario.update();
	boxxo.update();
}

void Level::level_render()
{
	tiles.render_level();
	mario.render();
	boxxo.render();
}




