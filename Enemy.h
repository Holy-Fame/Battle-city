#pragma once
#include <SFML/Graphics.hpp>
#include "Tank.h"

class Enemy : public Tank
{
public:

	Enemy(sf::Image& image, float X, float Y, int W, int H, sf::String Name);
	void update(float time, sf::String* level);
	void control();
};

