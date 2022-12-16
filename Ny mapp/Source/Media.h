#pragma once
#include "raylib.h"

//Media class is used to control the media loading only once, since it felt to be easiest way to fix the issue whenever the game initialized, all images were loaded again.

enum request
{
	BEE,
	FLOWER,
	HONEYCOMB,
	HURRAY,
	BEEBG,
	BEEMOVE,
	PUSH,
	FAIL
};

class Media
{
	//Images:
	Texture2D honeycomb;
	Texture2D flower;
	Texture2D bee;

	//Sound Effects:
	Sound hurray;
	Sound beeBgSound;
	Sound beeMove;
	Sound pushFlower;
	Sound failFlower;

public:

	void init_media();

	Texture2D get_image(enum request item);

	Sound get_sound(enum request item);
};
