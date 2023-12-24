#include "Enemy.h"
#include "Bullet.h"
#include "SFML/Audio.hpp"

Enemy::Enemy(sf::Image& image, float X, float Y, int W, int H, sf::String Name) : Tank(image, X, Y, W, H, Name)
{
	changeDirectionTimer = 2600;
	shootTimer = 0;
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

int getRandom(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void Enemy::control(float time, std::list<Entity*>& bullets)
{
	changeDirectionTimer += time;
	shootTimer += time;

	if (shootTimer > 2000)
	{
		sf::Image bulletImage;
		bulletImage.loadFromFile("image/bullet.png");
		bullets.push_back(new Bullet(bulletImage, x, y, 10, 10, state, "BulletEnemy"));
		shootTimer = 0;
	}

	if (changeDirectionTimer > 3000)
	{
		int randNum = getRandom(0, 3);
		switch (randNum)
		{
		case 0:
		{
			state = up; dx = 0; dy = -0.12;
			sprite.setTextureRect(sf::IntRect(0, 180, 60, 60));
			break;
		}
		case 1:
		{
			state = down; dx = 0; dy = 0.12;
			sprite.setTextureRect(sf::IntRect(0, 0, 60, 60));
			break;
		}
		case 2:
		{
			state = left; dy = 0; dx = -0.12;
			sprite.setTextureRect(sf::IntRect(0, 60, 60, 60));
			break;
		}
		case 3:
		{
			state = right; dy = 0; dx = 0.12;
			sprite.setTextureRect(sf::IntRect(0, 120, 60, 60));
			break;
		}
		default: break;
		}

		changeDirectionTimer = 0;
	}
}

void Enemy::update(float time, sf::String* level, std::list<Entity*>& bullets)
{
	control(time, bullets);

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