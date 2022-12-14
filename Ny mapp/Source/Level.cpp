#include "Level.h"
#include <iostream>

// created to reduce redundant code in level_init
void Level::create_flower(Vector2 position)
{
	Flower new_flower;
	new_flower.position = { position.x,position.y };
	new_flower.flower = images.get_image(FLOWER);
	add_entity_Flower(new_flower);
}

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

	// vvv Implemented this way since the flowers check for buttons and certain levels uses more flowers than there are buttons
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
		if (!b.on_a_button)
		{
			flowers_on_button += 1;
			b.on_a_button = true;
		}
		if (flowers_on_button == win_condition)
		{
			isWon = true;
			PlaySoundMulti(hurraa);
			std::cout << "Hurray!" << std::endl; //Left as an easter egg and reminder how much fun we had when we were able to create a victory screen.

		}
	}
	if (tiles.tiles[((int)b.position.x + (8 * (int)b.position.y))] != 3)
	{
		if (b.on_a_button)
		{
			flowers_on_button -= 1;
			b.on_a_button = false;
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
	tiles.flower_button = images.get_image(FLOWER);

	playerBee.Bee = images.get_image(BEE);
	playerBee.beeMove = images.get_sound(BEEMOVE);

	tiles.tile_images = images;
}

void Level::level_init()
{
	flowers_on_button = 0;
	flowers_in_level.clear();

	playerBee.face_directions = UP;

	tiles.setTiles(level_order);

	switch (level_order)
	{
	case 1:
		playerBee.position = { 1,3 };

		create_flower({ 4,3 });
		create_flower({ 4,4 });
		break;
	case 2:
		playerBee.position = { 6,5 };

		create_flower({ 4,3 });
		create_flower({ 3,4 });
		break;
	case 3:
		playerBee.position = { 5,2 };

		create_flower({ 3,3 });
		create_flower({ 2,4 });
		create_flower({ 3,5 });
		break;
	case 4:
		playerBee.position = { 3,3 };

		create_flower({ 2,2 });
		create_flower({ 5,2 });
		create_flower({ 2,5 });
		create_flower({ 5,5 });
		break;
	case 5:
		playerBee.position = { 1,1 };

		create_flower({ 3,2 });
		create_flower({ 3,3 });
		create_flower({ 2,3 });
		break;
	case 6:
		playerBee.position = { 6,3 };

		create_flower({ 2,2 });
		create_flower({ 2,3 });
		create_flower({ 1,4 });
		create_flower({ 5,2 });
		break;
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
