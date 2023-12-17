#pragma once
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Entity.h"

class Tank : public Entity
{
public:
	enum {left, right, up, down} state;
	int playerScore;
	Tank(sf::Image& image, float X, float Y, int W, int H, sf::String Name);

	void control();
	void checkCollisionWithMap(float Dx, float Dy, sf::String* level);
	void update(float time, sf::String* level);
};

