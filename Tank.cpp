#include "Tank.h"

Tank::Tank(sf::Image& image, float X, float Y, int W, int H, sf::String Name) : Entity(image, X, Y, W, H, Name)
{
	playerScore = 0; state = down;
	if (name == "Player1")
	{
		sprite.setTextureRect(sf::IntRect(0, 0, w, h));
	}
}

void Tank::control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		state = left; speed = 0.1;
		//CurrentFrame += 0.005 * time;
		//if (CurrentFrame > 2) CurrentFrame -= 2;
		//t.sprite.setTextureRect(sf::IntRect(40 * int(CurrentFrame), 40, 40, 40));
		sprite.setTextureRect(sf::IntRect(0, 40, 40, 40));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		state = right; speed = 0.1;
		//CurrentFrame += 0.005 * time;
		//if (CurrentFrame > 2) CurrentFrame -= 2;
		//t.sprite.setTextureRect(sf::IntRect(40 * int(CurrentFrame), 80, 40, 40));
		sprite.setTextureRect(sf::IntRect(0, 80, 40, 40));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		state = up; speed = 0.1;
		//CurrentFrame += 0.005 * time;
		//if (CurrentFrame > 2) CurrentFrame -= 2;
		//t.sprite.setTextureRect(sf::IntRect(40 * int(CurrentFrame), 120, 40, 40));
		sprite.setTextureRect(sf::IntRect(0, 120, 40, 40));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		state = down; speed = 0.1;
		//CurrentFrame += 0.005 * time;
		//if (CurrentFrame > 2) CurrentFrame -= 2;
		//t.sprite.setTextureRect(sf::IntRect(40 * int(CurrentFrame), 0, 40, 40));
		sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
	}
}

void Tank::update(float time)
{
	control();
	switch (state)
	{
	case right: dx = speed; dy = 0; break;
	case left: dx = -speed; dy = 0; break;
	case down: dx = 0; dy = speed; break;
	case up: dx = 0; dy = -speed; break;
	}

	x += dx * time;
	checkCollisionWithMap(dx, 0);
	y += dy * time;
	checkCollisionWithMap(0, dy);

	if (x <= 440) x = 440;
	if (x >= 1440) x = 1440;
	if (y <= 40) y = 40;
	if (y >= 999) y = 999;

	sprite.setPosition(x, y);
	if (health <= 0)
	{
		life = false;
	}
	if (!isMove) {
		speed = 0;
	}
}

void Tank::checkCollisionWithMap(float Dx, float Dy)
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
				if (Dy > 0)
				{
					y = i * 40 - h + 40;
				}
				if (Dy < 0)
				{
					y = i * 40 + 40 + 40;
				}
				if (Dx > 0)
				{
					x = j * 40 - w + 440;
				}
				if (Dx < 0)
				{
					x = j * 40 + 40 + 440;
				}
			}
		}
	}
}