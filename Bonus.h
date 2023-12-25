#pragma once
#include <list>

class Bonus
{
public:
	float x, y;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::String name;

	Bonus(sf::Image& image, float X, float Y, sf::String Name);
	void static Spawn(std::list<Bonus*>& bonuses, float X, float Y);
};
