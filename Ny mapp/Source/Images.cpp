#pragma once
#include "raylib.h"

enum request
{
	BEE,
	FLOWER,
	HONEYCOMB
};

class Images
{
	Texture2D honeycomb;
	Texture2D flower;
	Texture2D bee;

public:
	
	void init_images()
	{
		honeycomb = LoadTexture("beehive-tiles.png");
		flower = LoadTexture("flower.png");
		bee = LoadTexture("beePlayer1.png");
	}

	Texture2D get_image(enum request item)
	{
		switch (item)
		{
		case BEE:
		{
			return bee;
		}
		case FLOWER:
		{
			return flower;
		}
		case HONEYCOMB:
		{
			return honeycomb;
		}
		}
	}
};