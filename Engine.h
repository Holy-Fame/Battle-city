#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class Engine
{
	std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1920, 1080), L"Battle city", sf::Style::Fullscreen);
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(1920, 1080));
	sf::Texture background_texture;

	void input();
	void update(sf::Time& deltaTime);
	void draw();

public:
	Engine();
	void run();
};
