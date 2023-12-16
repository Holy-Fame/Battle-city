#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Bullet : public Entity
{
public:
	int direction;

	Bullet(sf::Image& image, float X, float Y, int W, int H, int dir, sf::String Name);
	void update(float time);
};

