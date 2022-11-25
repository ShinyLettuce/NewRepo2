#include "raylib.h"


class Tile_system
{
public:
	static const int size = 64;
	const int cols = 8;
	const int rows = 8;
	int tiles[64] = { 1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1 };
	
Color GetColor(int type)
{
	if (type == 1)
	{
		return { 255,255,255,255 };
	}
	else
		return{ 0,0,0,255 };
}

void render_level()
{
	int allyourbase = 0;
	
	for(int c = 0;c<cols;c++)
	{ 
		for (int i_2 = 0; i_2 <rows; i_2++)
		{
			BeginDrawing();
			int  type = tiles[allyourbase];
			DrawRectangle(0 + size * i_2, 0 + (size * c), size, size, GetColor(type));
			
			allyourbase++;
		}
	}
}

};


class Entities 
{
public:
	Vector2 position = {16,16};

	virtual void render()
	{
	}

	virtual void update()
	{
	}

};

class Box : Entities
{
public:
	Vector2 position = { 80,16 };

	void render()
	{
		DrawRectangle((int)position.x, (int)position.y, 32, 32, BROWN);
	}
};

class Player : Entities
{
public:

	void render()
	{
		DrawRectangle((int)position.x,(int)position.y, 32, 32, RED);
	}

	void update()
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

};



class Level
{
	void level_init();
	void level_update();
	void level_render();
};




