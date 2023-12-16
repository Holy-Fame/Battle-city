#include "Entity.h"

Entity::Entity(sf::Image& image, float X, float Y, int W, int H, sf::String Name) 
{
	x = X; y = Y; w = W; h = H; name = Name; moveTimer = 0;
	speed = 0; health = 100; dx = 0; dy = 0;
	life = true; isMove = false;
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}
