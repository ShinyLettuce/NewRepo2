#include "raylib.h"
#include "Level.h"
#include <vector>
#include <iostream>
#include "Entity.cpp"


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

void Level::clear_entitylist_B()
{
	boxes_in_level.clear();
}

void Level::add_entity_B(const Box& b)
{
	boxes_in_level.push_back(b);
}

void Level::game_init()
{
	isWon = false;
	background.tile_images = images;
	background.honeycomb = images.get_image(HONEYCOMB);
	background.flower = images.get_image(FLOWER);
	level_order = 1;
	level_init();
}

void Level::level_init()
{
	tiles.tile_images = images;
	tiles.honeycomb = images.get_image(HONEYCOMB);
	tiles.flower = images.get_image(FLOWER);
	boxes_in_level.clear();

	mario.Bee = images.get_image(BEE);
	mario.face_directions = UP;
	
	if (level_order == 1)
	{
		mario.position = { 1,1 };
		for (int boxes = 0; boxes < 6; boxes++)
		{
			Box new_box;
			if (boxes == 0)
			{
				new_box.position = { 2 , 2 };
			}
			else if (boxes == 1)
			{
				new_box.position = { 3 , 2 };
			}
			else if (boxes == 2)
			{
				new_box.position = { 5 , 3 };
			}
			else if (boxes == 3)
			{
				new_box.position = { 5 , 2 };
			}
			else
			{
				break;
			}
			new_box.flower = images.get_image(FLOWER);
			add_entity_B(new_box);
		}
	}
	else
	{
		mario.position = { 2,2 };
		Box new_box;
		new_box.position = { 2 , 3 };
		new_box.flower = images.get_image(FLOWER);
		add_entity_B(new_box);
	}

	background.setTiles(background_);
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


	for (const Box& b : boxes_in_level)
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
	tiles.render_level();
	mario.render();
	for (Box b : boxes_in_level)
	{
		b.render();
	}
	
}
