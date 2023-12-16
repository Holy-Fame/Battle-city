#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public:
	float dx, dy, x, y, speed, moveTimer;
	int w, h, health;
	bool life, isMove;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::String name;
	Entity(sf::Image& image, float X, float Y, int W, int H, sf::String Name);
	
	virtual void update(float time) = 0;
};

