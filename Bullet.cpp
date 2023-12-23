#include "Bullet.h"

Bullet::Bullet(sf::Image& image, float X, float Y, int W, int H, int dir, sf::String Name) : Entity(image, X, Y, W, H, Name)
{
	x = X + 25;
	y = Y + 25;
	direction = dir;
	speed = 0.6;
	w = h = 8;
	life = true;
}

void Bullet::update(float time, sf::String* level)
{
	switch (direction)
	{
	case 0: dx = -speed; dy = 0; break;
	case 1: dx = speed; dy = 0; break;
	case 2: dx = 0; dy = -speed; break;
	case 3: dx = 0; dy = speed; break;
	}

	x += dx * time;
	checkCollisionWithMap(dx, 0, level);
	y += dy * time;
	checkCollisionWithMap(0, dy, level);

	if (x <= 440) life = false;
	if (x >= 1470) life = false;
	if (y <= 20) life = false;
	if (y >= 1050) life = false;

	sprite.setPosition(x, y);
}

void Bullet::checkCollisionWithMap(float Dx, float Dy, sf::String* level)
{
	for (int i = (y - 20) / 40; i < (y - 20 + h) / 40; i++)
	{
		for (int j = (x - 440) / 40; j < (x - 440 + w) / 40; j++)
		{
     		if (level[i][j] == '#' || level[i][j] == 'w' || level[i][j] == '_' || level[i][j] == '-' || level[i][j] == '(' || level[i][j] == ')')
			{
				if (Dy > 0)
				{
					life = false;
					level[i][j] = level[i][j] == '#' ? '_' : level[i][j] != 'w' ? ' ' : level[i][j];
				}
				if (Dy < 0)
				{
					life = false;
					level[i][j] = level[i][j] == '#' ? '-' : level[i][j] != 'w' ? ' ' : level[i][j];
				}
				if (Dx > 0)
				{
					life = false;
					level[i][j] = level[i][j] == '#' ? ')' : level[i][j] != 'w' ? ' ' : level[i][j];
				}
				if (Dx < 0)
				{
					life = false;
					level[i][j] = level[i][j] == '#' ? '(' : level[i][j] != 'w' ? ' ' : level[i][j];
				}
			}
		}
	}
}