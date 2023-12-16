#include "Tank.h"

Tank::Tank(sf::String F, int X, int Y, float W, float H)
{
	file = F;
	w = W;
	h = H;
	image.loadFromFile("image/" + file);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	x = X;
	y = Y;
	sprite.setTextureRect(sf::IntRect(w, h, w, h));
}

void Tank::update(float time)
{
	switch (dir)
	{
	case 0: dx = speed; dy = 0; break;
	case 1: dx = -speed; dy = 0; break;
	case 2: dx = 0; dy = speed; break;
	case 3: dx = 0; dy = -speed; break;
	}

	x += dx * time;
	y += dy * time;

	if (x <= 440) x = 440;
	if (x >= 1440) x = 1440;
	if (y <= 40) y = 40;
	if (y >= 1000) y = 1000;

	speed = 0;

	sprite.setPosition(x, y);
	interectionWithMap();
}

float Tank::getTankX()
{
	return x;
}

float Tank::getTankY()
{
	return y;
}

void Tank::interectionWithMap()
{
	const int MAP_WIDTH = 26;
	const int MAP_HIGHT = 25;
	sf::String firstLevelMap[MAP_HIGHT] =
	{
		"                          ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##          ##  ##  ",
		"  ##  ##          ##  ##  ",
		"          ##  ##          ",
		"          ##  ##          ",
		"##  ####          ####  ##",
		"ww  ####          ####  ww",
		"          ##  ##          ",
		"          ######          ",
		"  ##  ##  ######  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##          ##  ##  ",
		"  ##  ##          ##  ##  ",
		"  ##  ##   ####   ##  ##  ",
		"           #  #           ",
		"           #  #           ",
	};

	for (int i = (y - 40) / 40; i < (y - 40 + h) / 40; i++)
	{
		for (int j = (x - 440) / 40; j < (x - 440 + w) / 40; j++)
		{
			if (firstLevelMap[i][j] == '#' || firstLevelMap[i][j] == 'w')
			{
				if (dy > 0)
				{
					y = i * 40 - h + 40;
				}
				if (dy < 0)
				{
					y = i * 40 + 40 + 40;
				}
				if (dx > 0)
				{
					x = j * 40 - w + 440;
				}
				if (dx < 0)
				{
					x = j * 40 + 40 + 440;
				}
			}
		}
	}
}