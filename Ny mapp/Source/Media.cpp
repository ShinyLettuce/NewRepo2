#pragma once
#include "Media.h"

void Media::init_media()
{
	//Images
	honeycomb = LoadTexture("beehive-tiles5.png");
	flower = LoadTexture("flower2.png");
	bee = LoadTexture("beePlayer4.png");

	//Sound Effects:
	InitAudioDevice();
	hurray = LoadSound("Hurray.ogg");
	beeBgSound = LoadSound("beeBackgroundSound.mp3");
	beeMove = LoadSound("bzzz.mp3");
	pushFlower = LoadSound("push.mp3");
	failFlower = LoadSound("Hups.ogg");
}

Texture2D Media::get_image(enum request item)
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
	default: //We didn't have time to create error spirtes for wrongly requested images, thus bee is used as a default.
		return bee;
	}
}

Sound Media::get_sound(enum request item)
{
	switch (item)
	{
	case HURRAY:
		return hurray;
	case BEEBG:
		return beeBgSound;
	case BEEMOVE:
		return beeMove;
	case PUSH:
		return pushFlower;
	case FAIL:
		return failFlower;
	default: //We didn't have time to create error sound for wrongly requested sounds, thus hups is used as a default.
		return failFlower;
	}
}