#include "Enemy.h"

Enemy::Enemy(sf::Image& image, float X, float Y, int W, int H, sf::String Name) : Tank(image, X, Y, W, H, Name)
{
	state = down;
	if (Name == "Enemy1")
	{
		health = 1;
	}
	else
	{
		health = 2;
	}
	sprite.setTextureRect(sf::IntRect(0, 0, w, h));
}

void Enemy::control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		state = left; speed = 0.12;
		sprite.setTextureRect(sf::IntRect(0, 60, 60, 60));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		state = right; speed = 0.12;
		sprite.setTextureRect(sf::IntRect(0, 120, 60, 60));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		state = up; speed = 0.12;
		sprite.setTextureRect(sf::IntRect(0, 180, 60, 60));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		state = down; speed = 0.12;
		sprite.setTextureRect(sf::IntRect(0, 0, 60, 60));
	}
}

void Enemy::update(float time, sf::String* level)
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