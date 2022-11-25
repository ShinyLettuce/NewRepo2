#include "raylib.h"
#include <vector>

enum tile_types
{
	FLOOR,
	WALL,
	SWITCH,
	SAND
};

struct Position
{
	float x;
	float y;
};

struct Tiles
{
	const int tile_size = 32;

	Position location = { 0,0 };

	int type = WALL;

	Tiles() = default;

	inline Tiles(Position location, int type) :
		location{ location }, type{ type }
	{}
};

class Tile_system
{
public:

	int tile_amount = 0;

	Tile_system() = default;
	~Tile_system() = default;
};

class TileSetLevel
{
public:
	Tile_system tilesystem;
	std::vector<Tiles> created_tiles;

	void initialize()
	{
		int row = 0;
		int column = 0;
		int tile_size = 32;
		bool isitfloor = true;

		for (int i = 0; i < 32; i++)
		{
			Tiles newTile = Tiles();
			newTile.location.x = (float)row * tile_size;
			newTile.location.y = (float)column * tile_size;
			if (isitfloor)
			{
				newTile.type = FLOOR;
				isitfloor = false;
			}
			else
			{
				newTile.type = WALL;
				isitfloor = true;
			}
			if (column == 7)
			{
				row += 1;
				column = 0;
				isitfloor = !isitfloor;
			}
			else
			{
				column += 1;
			}
			//Insert here pointers for head, tail, next and previous
			created_tiles.push_back(newTile);
			tilesystem.tile_amount = (int)created_tiles.size();
		}
	}

	void render()
	{
		for (size_t index = 0; index < created_tiles.size(); index++)
		{
			int x = (int)created_tiles[index].location.x;
			int y = (int)created_tiles[index].location.y;
			int size = created_tiles[index].tile_size;

			if (created_tiles[index].type == WALL)
			{
				DrawRectangle(x, y, size, size, BLACK);
			}
			else
			{
				DrawRectangle(x, y, size, size, WHITE);
			}
		}
	}

	TileSetLevel() = default;
	~TileSetLevel() = default;
};
