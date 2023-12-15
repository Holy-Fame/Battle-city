#include "Tank.h"

Tank::Tank(sf::String F, int X, int Y, float W, float H)
{
	file = F;
	w = W;
	h = H;
	image.loadFromFile("image/" + file);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	x = X;
	y = Y;
	sprite.setTextureRect(sf::IntRect(w, h, w, h));
}

void Tank::update(float time)
{
	switch (dir)
	{
	case 0: dx = speed; dy = 0; break;
	case 1: dx = -speed; dy = 0; break;
	case 2: dx = 0; dy = speed; break;
	case 3: dx = 0; dy = -speed; break;
	}

	x += dx * time;
	y += dy * time;

	speed = 0;

	sprite.setPosition(x, y);
}
