#include "Level.h"
#include <iostream>

void Level::move_player(Player& p, Vector2 input)
{
	float newposx = playerBee.position.x + input.x;
	float newposy = playerBee.position.y + input.y;

	bool flower_stayed = false;

	for (Flower& b : flowers_in_level)
	{
		if (newposx == b.position.x && newposy == b.position.y)
		{
			flower_stayed = move_flower(b, input);
		}
		if (flower_stayed)
		{
			break;
		}
	}

	if (!flower_stayed && tiles.tiles[((int)newposx + (8 * (int)newposy))] != 1)
	{
		p.position.x += input.x;
		p.position.y += input.y;
	}
	return;
}

void Level::flowers_and_winning(Flower& b, int level_order)
{
	int win_condition = 0;
	if (level_order == 1 || level_order == 2)
	{
		win_condition = 2;
	}
	if (level_order == 4)
	{
		win_condition = 4;
	}
	if (level_order == 3 || level_order == 5 || level_order == 6)
	{
		win_condition = 3;
	}

	if (tiles.tiles[((int)b.position.x + (8 * (int)b.position.y))] == 3)
	{
		if (!b.onaswitch)
		{
			flowers_on_switch += 1;
			b.onaswitch = true;
		}
		if (flowers_on_switch == win_condition)
		{
			isWon = true;
			if (IsAudioDeviceReady)
			{
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
			flowers_on_switch -= 1;
			b.onaswitch = false;
		}
	}
}

bool Level::move_flower(Flower& b, Vector2 input)
{
	float newposx = b.position.x + input.x;
	float newposy = b.position.y + input.y;


	for (const Flower& b : flowers_in_level)
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
		PlaySoundMulti(pushFlower);
		flowers_and_winning(b, level_order);
		return false;
	}
	else
		PlaySoundMulti(failFlower);
	return true;
}

void Level::clear_entitylist_Flower()
{
	flowers_in_level.clear();
}

void Level::add_entity_Flower(const Flower& b)
{
	flowers_in_level.push_back(b);
}

void Level::game_init()
{
	level_order = 0;
	playerBee.position = { 3,4 };
	isWon = false;
	level_init();
}

void Level::media_loading()
{
	hurraa = images.get_sound(HURRAY);
	beebg = images.get_sound(BEEBG);
	PlaySoundMulti(beebg);

	pushFlower = images.get_sound(PUSH);
	failFlower = images.get_sound(FAIL);

	tiles.honeycomb = images.get_image(HONEYCOMB);
	tiles.flower = images.get_image(FLOWER);

	playerBee.Bee = images.get_image(BEE);
	playerBee.beeMove = images.get_sound(BEEMOVE);

	tiles.tile_images = images;
}

void Level::level_init()
{
	flowers_on_switch = 0;
	flowers_in_level.clear();

	playerBee.face_directions = UP;

	tiles.setTiles(level_order);

	if (level_order == 1)
	{
		playerBee.position = { 1,3 };

		Flower new_flower_1;
		new_flower_1.position = { 4,3 };
		new_flower_1.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_1);

		Flower new_flower_2;
		new_flower_2.position = { 4,4 };
		new_flower_2.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_2);

	}
	else if (level_order == 2)
	{
		playerBee.position = { 6,5 };

		Flower new_flower_1;
		new_flower_1.position = { 4,3 };
		new_flower_1.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_1);

		Flower new_flower_2;
		new_flower_2.position = { 3,4 };
		new_flower_2.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_2);

	}
	else if (level_order == 3)
	{
		playerBee.position = { 5,2 };

		Flower new_flower_1;
		new_flower_1.position = { 3,3 };
		new_flower_1.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_1);

		Flower new_flower_2;
		new_flower_2.position = { 2,4 };
		new_flower_2.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_2);

		Flower new_flower_3;
		new_flower_3.position = { 3,5 };
		new_flower_3.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_3);

	}
	else if (level_order == 4)
	{
		playerBee.position = { 3,3 };

		Flower new_flower_1;
		new_flower_1.position = { 2,2 };
		new_flower_1.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_1);

		Flower new_flower_2;
		new_flower_2.position = { 5,2 };
		new_flower_2.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_2);

		Flower new_flower_3;
		new_flower_3.position = { 2,5 };
		new_flower_3.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_3);

		Flower new_flower_4;
		new_flower_4.position = { 5,5 };
		new_flower_4.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_4);

	}
	else if(level_order == 5)
	{
		playerBee.position = { 1,1 };

		Flower new_flower_1;
		new_flower_1.position = { 3,2 };
		new_flower_1.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_1);

		Flower new_flower_2;
		new_flower_2.position = { 3,3 };
		new_flower_2.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_2);

		Flower new_flower_3;
		new_flower_3.position = { 2,3 };
		new_flower_3.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_3);

	}
	else if (level_order == 6)
	{
		playerBee.position = { 6,3 };
		Flower new_flower_1;
		new_flower_1.position = { 2,2 };
		new_flower_1.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_1);

		Flower new_flower_2;
		new_flower_2.position = { 2,3 };
		new_flower_2.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_2);

		Flower new_flower_3;
		new_flower_3.position = { 1,4 };
		new_flower_3.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_3);

		Flower new_flower_4;
		new_flower_4.position = { 5,2 };
		new_flower_4.flower = images.get_image(FLOWER);
		add_entity_Flower(new_flower_4);
	}

}

void Level::level_update()
{
	if (IsKeyPressed(KEY_DELETE))
	{
		level_init();
	}

	playerBee.update();

	move_player(playerBee, playerBee.input);
	playerBee.input = { 0,0 };
}

void Level::level_render()
{
	tiles.render_level();
	playerBee.render();
	for (Flower b : flowers_in_level)
	{
		b.render();
	}
	
}
