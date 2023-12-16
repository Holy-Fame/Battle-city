#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "AssetManager.h"
#include "GameMenu.h"
#include <vector>
#include "Tank.h"

class Engine
{
	std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1920, 1080), L"Battle city", sf::Style::Fullscreen);
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(1920, 1080));

	AssetManager manager;

	void input();
	void update(sf::Time& deltaTime);
	void draw();

public:
	void GameMenu();
	Engine();
	void run();
	void RenderMap(sf::RenderWindow& window);
	void SingleGame(sf::RenderWindow& window);
};
