#include <SFML/Graphics.hpp>
#include "Bonus.h"

Bonus::Bonus(sf::Image& image, float X, float Y, sf::String Name)
{
	x = X; y = Y; name = Name;
	texture.loadFromImage(image);
	sprite.setTexture(texture);

	if (Name == "hp")
	{
		sprite.setTextureRect(sf::IntRect(0, 0, 60, 60));
	}

	if (Name == "time")
	{
		sprite.setTextureRect(sf::IntRect(60, 0, 60, 60));
	}

	if (Name == "def")
	{
		sprite.setTextureRect(sf::IntRect(120, 0, 60, 60));
	}

	sprite.setPosition(x, y);
}

int Random(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void Bonus::Spawn(std::list<Bonus*>& bonuses, float X, float Y)
{
	sf::Image bonusImage;
	bonusImage.loadFromFile("image/bonus.png");
	int bonusType = Random(0, 2);

	switch (bonusType)
	{
	case 0:
		bonuses.push_back(new Bonus(bonusImage, X, Y, "hp"));
		break;
	case 1:
		bonuses.push_back(new Bonus(bonusImage, X, Y, "time"));
		break;
	case 2:
		bonuses.push_back(new Bonus(bonusImage, X, Y, "def"));
		break;
	default:
		break;
	}
}