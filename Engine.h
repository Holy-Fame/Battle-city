#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "AssetManager.h"
#include "GameMenu.h"
#include <vector>
#include "Tank.h"
#include "Bullet.h"
#include <vector>
#include <list>
#include "Enemy.h"
#include "Bonus.h"

class Engine
{
	std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1920, 1080), L"Battle city", sf::Style::Fullscreen);
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(1920, 1080));

	AssetManager manager;

	void input();
	void update(sf::Time& deltaTime);
	void draw();

public:
	void GameRun(sf::RenderWindow& window, std::vector<sf::String*> mapsArr, std::vector<std::vector<std::string>> bots, int mode);
	void GameMenu();
	Engine();
	void run();
	bool SingleGame(sf::RenderWindow& window, std::vector<sf::String*> mapsArr, std::vector<std::vector<std::string>> bots, int mode);
	bool GameOver(std::vector<Tank>& players, sf::RenderWindow& window);
};
