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


	/*switch (dir)
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
	*/
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
		//dir = 1;
		face_directions = RIGHT;
	}

	if (IsKeyPressed(KEY_LEFT))
	{
		input = { -1, 0 };
		//dir = 3;
		face_directions = LEFT;
	}

	if (IsKeyPressed(KEY_DOWN))
	{
		input = { 0, 1 };
		//dir = 2;
		face_directions = DOWN;
	}

	if (IsKeyPressed(KEY_UP))
	{
		input = { 0,-1 };
		//dir = 0;
		face_directions = UP;
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
	level_order = 1;
	level_init();
}

void Level::level_init()
{
	boxes_in_level.clear();

	//mario.dir = 0;
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
			add_entity_B(new_box);
		}
	}
	else
	{
		mario.position = { 2,2 };
		Box new_box;
		new_box.position = { 2 , 3 };
		add_entity_B(new_box);
	}

	background.setTiles(background_);
}


void Level::level_update()
{
	/*
	if (IsKeyPressed(KEY_HOME)) //ENI Comment: Home in order to return to MainMenu and Delete to reset current level?
	{
		isWon = false;
		startmenu = true;
		game_init();
	}
	*/

	if (IsKeyPressed(KEY_DELETE))
	{
		level_init();
	}

	/*
	if (IsKeyPressed(KEY_ENTER)) //ENI Comment: Start Menu in MainMenu?
	{
		startmenu = false;
	}
	*/


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
	
	/*
	if (startmenu) //ENI Comment: Start Menu in MainManu?
	{
		//ClearBackground(BLACK);
		background.render_level();
		DrawText("Bee Game", 110, 64, 64, WHITE);
		DrawText("Press Enter to start", 80, 128, 32, WHITE);
	}
	*/

	if (!isWon) 
	{
		tiles.render_level();
		mario.render();
		for (Box b : boxes_in_level)
		{
			b.render();
		}
	}

	else if (isWon) //ENI Comment: End Screen in MainManu?
	{
		ClearBackground(BLACK);
		DrawTextureEx(flower, {0,0}, 0.f, 16.f, DARKGRAY);
		DrawText("Congratz!",			110, 64, 64, WHITE);
		DrawText("Press Home to go",	100, 128, 32, WHITE);
		DrawText("back to menu",		140, 160, 32, WHITE);
	}
}
