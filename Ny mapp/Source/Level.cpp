#include "raylib.h"
#include "Level.h"
#include <vector>
#include <iostream>
#include "Entity.cpp"
#include "Tile_system.cpp"

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
	level_order = 1;
	level_init();
}

void Level::level_init()
{
	boxes_on_switch = 0;
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
			if (!b.onaswitch)
			{
				boxes_on_switch += 1;
				b.onaswitch = true;
			}
			if (boxes_on_switch == 2)
			{
				isWon = true;
				//Sound hurraa = images.get_sound(HURRAY);
				//PlaySound(hurraa);
				std::cout << "Hurray!" << std::endl;
			}
		}
		if (tiles.tiles[((int)b.position.x + (8 * (int)b.position.y))] != 3)
		{
			if (b.onaswitch)
			{
				boxes_on_switch -= 1;
				b.onaswitch = false;
			}
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
