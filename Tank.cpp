#include "Tank.h"

Tank::Tank(sf::Image& image, float X, float Y, int W, int H, sf::String Name) : Entity(image, X, Y, W, H, Name)
{
	playerScore = 0; state = up;
	if (name == "Player1")
	{
		sprite.setTextureRect(sf::IntRect(0, 180, w, h));
	}
}

void Tank::control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		state = left; speed = 0.12;
		sprite.setTextureRect(sf::IntRect(0, 60, 60, 60));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		state = right; speed = 0.12;
		sprite.setTextureRect(sf::IntRect(0, 120, 60, 60));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		state = up; speed = 0.12;
		sprite.setTextureRect(sf::IntRect(0, 180, 60, 60));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		state = down; speed = 0.12;
		sprite.setTextureRect(sf::IntRect(0, 0, 60, 60));
	}
}

void Tank::update(float time, sf::String* level)
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
	checkCollisionWithMap(dx, 0, level);
	y += dy * time;
	checkCollisionWithMap(0, dy, level);

	if (x <= 440) x = 440;
	if (x >= 1420) x = 1420;
	if (y <= 20) y = 20;
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

void Tank::checkCollisionWithMap(float Dx, float Dy, sf::String* level)
{
	for (int i = (y - 20) / 40; i < (y - 20 + h) / 40; i++)
	{
		for (int j = (x - 440) / 40; j < (x - 440 + w) / 40; j++)
		{
			if (level[i][j] == '#' || level[i][j] == 'w' || level[i][j] == '_' || level[i][j] == '-' || level[i][j] == '(' || level[i][j] == ')')
			{
				if (Dy > 0)
				{
					y = i * 40 - h + 20;
				}
				if (Dy < 0)
				{
					y = i * 40 + 40 + 20;
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