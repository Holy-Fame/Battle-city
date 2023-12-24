#pragma once
#include <SFML/Graphics.hpp>
#include "Tank.h"
#include <list>

class Enemy : public Tank
{
public:
	float changeDirectionTimer;
	float shootTimer;

	Enemy(sf::Image& image, float X, float Y, int W, int H, sf::String Name);
	void update(float time, sf::String* level, std::list<Entity*>& bullets);
	void control(float time, std::list<Entity*>& bullets);
};

