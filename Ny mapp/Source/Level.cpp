#include "raylib.h"

class Tile_system
{
public:
	static const int size = 32;
	const int cols = 8;
	const int rows = 8;
	int tiles[64] = { 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0 };
	
Color GetColor(int type)
{
	if (type == 0)
	{
		return { 255,255,255,255 };
	}
	else
		return{ 0,0,0,0 };
}

void render()
{
	
	for(int i= 0;i<8;i++)
	{ 
		for (int i_2 = 0; i < 8; i++)
		{
			int  type = tiles[i*i_2];
			DrawRectangle(Tile_system::size * i_2, Tile_system::size * i, Tile_system::size, Tile_system::size, GetColor(type));
		}
	}
}

};





