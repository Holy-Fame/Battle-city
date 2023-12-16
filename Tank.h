#pragma once
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class Tank
{
public:
	float x, y, w, h, dx, dy, speed = 0;
	int dir = 0;
	sf::String file;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	Tank(sf::String F, int X, int Y, float W, float H);
	void update(float time);
	float getTankX();
	float getTankY();
	void interectionWithMap();
};

