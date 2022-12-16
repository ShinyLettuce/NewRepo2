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
	level_order = 0;
	mario.position = { 3,4 };
	Sound beebg = images.get_sound(BEEBG);
	PlaySoundMulti(beebg);
	isWon = false;
	level_init();
}

void Level::level_init()
{
	pushBox = images.get_sound(PUSH);
	failBox = images.get_sound(FAIL);
	boxes_on_switch = 0;
	tiles.tile_images = images;
	tiles.honeycomb = images.get_image(HONEYCOMB);
	tiles.flower = images.get_image(FLOWER);
	boxes_in_level.clear();

	mario.Bee = images.get_image(BEE);
	mario.beeMove = images.get_sound(BEEMOVE);

	mario.face_directions = UP;

	if (level_order == 1)
	{
		mario.position = { 1,3 };

		Box new_box_1;
		new_box_1.position = { 4,3 };
		new_box_1.flower = images.get_image(FLOWER);
		add_entity_B(new_box_1);

		Box new_box_2;
		new_box_2.position = { 4,4 };
		new_box_2.flower = images.get_image(FLOWER);
		add_entity_B(new_box_2);

	}
	else if (level_order == 2)
	{
		mario.position = { 6,5 };

		Box new_box_1;
		new_box_1.position = { 4,3 };
		new_box_1.flower = images.get_image(FLOWER);
		add_entity_B(new_box_1);

		Box new_box_2;
		new_box_2.position = { 3,4 };
		new_box_2.flower = images.get_image(FLOWER);
		add_entity_B(new_box_2);

	}
	else if (level_order == 3)
	{
		mario.position = { 3,3 };

		Box new_box_1;
		new_box_1.position = { 2,2 };
		new_box_1.flower = images.get_image(FLOWER);
		add_entity_B(new_box_1);

		Box new_box_2;
		new_box_2.position = { 5,2 };
		new_box_2.flower = images.get_image(FLOWER);
		add_entity_B(new_box_2);

		Box new_box_3;
		new_box_3.position = { 2,5 };
		new_box_3.flower = images.get_image(FLOWER);
		add_entity_B(new_box_3);

		Box new_box_4;
		new_box_4.position = { 5,5 };
		new_box_4.flower = images.get_image(FLOWER);
		add_entity_B(new_box_4);

	}
	else if (level_order == 4)
	{
		mario.position = { 5,2 };

		Box new_box_1;
		new_box_1.position = { 3,3 };
		new_box_1.flower = images.get_image(FLOWER);
		add_entity_B(new_box_1);

		Box new_box_2;
		new_box_2.position = { 2,4 };
		new_box_2.flower = images.get_image(FLOWER);
		add_entity_B(new_box_2);

		Box new_box_3;
		new_box_3.position = { 3,5 };
		new_box_3.flower = images.get_image(FLOWER);
		add_entity_B(new_box_3);

	}
	else if(level_order == 5)
	{
		mario.position = { 1,1 };

		Box new_box_1;
		new_box_1.position = { 3,2 };
		new_box_1.flower = images.get_image(FLOWER);
		add_entity_B(new_box_1);

		Box new_box_2;
		new_box_2.position = { 3,3 };
		new_box_2.flower = images.get_image(FLOWER);
		add_entity_B(new_box_2);

		Box new_box_3;
		new_box_3.position = { 2,3 };
		new_box_3.flower = images.get_image(FLOWER);
		add_entity_B(new_box_3);

	}
	else if (level_order == 6)
	{
		mario.position = { 1,1 };
		Box new_box_1;
		new_box_1.position = { 2,2 };
		new_box_1.flower = images.get_image(FLOWER);
		add_entity_B(new_box_1);

		Box new_box_2;
		new_box_2.position = { 2,3 };
		new_box_2.flower = images.get_image(FLOWER);
		add_entity_B(new_box_2);

		Box new_box_3;
		new_box_3.position = { 1,4 };
		new_box_3.flower = images.get_image(FLOWER);
		add_entity_B(new_box_3);

		Box new_box_4;
		new_box_4.position = { 5,2 };
		new_box_4.flower = images.get_image(FLOWER);
		add_entity_B(new_box_4);
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

void Level::boxes_winning(Box& b, int level_order)
{
	int win_condition = 0;
	if (level_order == 1 || level_order == 2)
	{
		win_condition = 2;
	}
	if (level_order == 3)
	{
		win_condition = 4;
	}
	if (level_order == 4 || level_order == 5 || level_order == 6)
	{
		win_condition = 3;
	}

	if (tiles.tiles[((int)b.position.x + (8 * (int)b.position.y))] == 3)
	{
		if (!b.onaswitch)
		{
			boxes_on_switch += 1;
			b.onaswitch = true;
		}
		if (boxes_on_switch == win_condition)
		{
			isWon = true;
			if (IsAudioDeviceReady)
			{
				Sound hurraa = images.get_sound(HURRAY);
				PlaySoundMulti(hurraa);
			}
			else
			{
				std::cout << "Audio device is not ready. :(" << std::endl;
			}
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
		PlaySoundMulti(pushBox);
		boxes_winning(b, level_order);
		return false;
	}
	else
		PlaySoundMulti(failBox);
		return true;
}

void Level::level_render()
{
	tiles.render_level(level_order);
	mario.render();
	for (Box b : boxes_in_level)
	{
		b.render();
	}
	
}
