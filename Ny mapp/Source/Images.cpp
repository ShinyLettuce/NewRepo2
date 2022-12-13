#pragma once
#include "raylib.h"

enum request
{
	BEE,
	FLOWER,
	HONEYCOMB,
	HURRAY
};

class Media
{
	//Images:
	Texture2D honeycomb;
	Texture2D flower;
	Texture2D bee;

	//Music:
	//AudioStream background_music;

	//Sound Effects:
	Sound hurray;
public:
	
	void init_media()
	{
		//Images
		honeycomb = LoadTexture("beehive-tiles5.png");
		flower = LoadTexture("flower.png");
		bee = LoadTexture("beePlayer4.png");

		//Music
		/*
		background_music = LoadMusicStream("");
		*/
		//Sound Effects:
		InitAudioDevice();
		hurray = LoadSound("hurray.wav");
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

	/*
	Music get_music(enum request item)
	{
		switch (item)
		{
		case BACKGROUND:
			return background_music;
		}
	}
	*/

	Sound get_sound(enum request item)
	{
		switch (item)
		{
		case HURRAY:
			return hurray;
		}
	}
};