#pragma once
#include "raylib.h"

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
	Sound pushBox;
	Sound failBox;

public:

	void init_media();

	Texture2D get_image(enum request item);

	Sound get_sound(enum request item);
};
