#include "raylib.h"
#include "Level.h"
#include <vector>
#include <iostream>



Color Tile_system::GetColor(int type)
{
	if (type == 3)
	{
		return { BLUE };
	}
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
	Color colour[3] = { GRAY, ORANGE, RAYWHITE };

	for (int c = 0; c < cols; c++)
	{
		for (int r = 0; r < rows; r++)
		{
			int  type = tiles[allyourbase];
			if (tiles[allyourbase] == 3)
			{
				DrawTexture(honeycomb, 0 + size * r, 0 + (size * c), GRAY);
				DrawTexture(flower, 16 + 64 * r, 16 + 64 * c, DARKGRAY);
			}

			else 
			{
				DrawTexture(honeycomb, 0 + size * r, 0 + (size * c), colour[tiles[allyourbase]]);
			}

			allyourbase++;
		}
	}
}


void Box::render()
{
	float pixel_x = (position.x * 64) + 16;
	float pixel_y = (position.y * 64) + 16;

	DrawTexture(flower, (int)pixel_x, (int)pixel_y, WHITE);
}

void Box::update()
{
	
}


void Player::render()
{


	Vector2 pos = { (position.x * 64) + 16, (position.y * 64) + 16 };


	switch (dir)
	{
	case 0:  //Up
	{
		DrawTextureEx(Bee, pos, 0.f, 1.f, WHITE);
		break;
	}
	case 1:  //Right
	{
		pos.x += 32;
		DrawTextureEx(Bee, pos, 90.f, 1.f, WHITE);
		break;
	}
	case 2:  //Down
	{
		pos.y += 32; pos.x += 32;
		DrawTextureEx(Bee, pos, 180.f, 1.f, WHITE);
		break;
	}
	case 3:  //Left
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
		dir = 1;
	}

	if (IsKeyPressed(KEY_LEFT))
	{
		input = { -1, 0 };
		dir = 3;
	}

	if (IsKeyPressed(KEY_DOWN))
	{
		input = { 0, 1 };
		dir = 2;
	}

	if (IsKeyPressed(KEY_UP))
	{
		input = { 0,-1 };
		dir = 0;
	}
}

void Level::clear_entitylist_B()
{
	boxes_in_level.clear();
}

void Level::add_entity_B(const Box& b)
{
	boxes_in_level.push_back(b);
}


void Level::level_init()
{
	//TODO: make Vector that stores all created Entities in the level so the movement check could work better.
	boxes_in_level.clear();

	mario.position = { 2,2 };
	
	if (level_order == 1)
	{
		for (int boxes = 0; boxes < 2; boxes++)
		{
			float times_boxes = 1.f * boxes;
			Box new_box;
			new_box.position = { (2 + times_boxes), (3 + times_boxes) };
			add_entity_B(new_box);
		}
	}
	else
	{
		for (int boxes = 0; boxes < 1; boxes++)
		{
			Box new_box;
			new_box.position = { 2 , 3};
			add_entity_B(new_box);
		}
	}
	//boxxo.position = { 2,3 };
	//add_entity_B(boxxo);
}

void Level::level_update()
{
	if (IsKeyPressed(KEY_DELETE))
	{
		level_init();
		isWon = false;
	}
	mario.update();

	move_player(mario, mario.input);
	mario.input = { 0,0 };
}

void Level::move_player(Player& p, Vector2 input)
{
	float newposx = mario.position.x + input.x;
	float newposy = mario.position.y + input.y;

	bool boxstayed = false;
	
	for (Box& b : boxes_in_level)
	{
		if (newposx == b.position.x && newposy == b.position.y)
		{
			boxstayed = move_box(b, input);
		}
		if (boxstayed)
		{
			break;
		}
	}	
	
	if (!boxstayed && tiles.tiles[((int)newposx + (8 * (int)newposy))] != 1)
	{
		p.position.x += input.x;
		p.position.y += input.y;
	}
	return;
}

bool Level::move_box(Box& b, Vector2 input)
{
	float newposx = b.position.x + input.x;
	float newposy = b.position.y + input.y;


	for (Box b : boxes_in_level)
	{
		if (newposx == b.position.x && newposy == b.position.y)
		{
			return true;
		}
	}
	if (tiles.tiles[((int)newposx + (8 * (int)newposy))] == 0 || tiles.tiles[((int)newposx + (8 * (int)newposy))] == 3)
	{
		b.position.x += input.x;
		b.position.y += input.y;
		if (tiles.tiles[((int)b.position.x + (8 * (int)b.position.y))] == 3)
		{
			isWon = true;
			std::cout << "Hurray!" << std::endl;
		}
		return false;
	}
	else
		return true;
}

void Level::level_render()
{
	if (isWon == false)
	{
		tiles.render_level();
		mario.render();
		for (Box b : boxes_in_level)
		{
			b.render();
		}
	}
	else if (isWon == true)
	{
		ClearBackground(BLACK);
		DrawText("Congratz!", 128, 64, 64, WHITE);
	}
}
