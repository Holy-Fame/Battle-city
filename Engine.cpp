#include "Engine.h"

void Engine::input()
{
	sf::Event event_play;

	while (window->pollEvent(event_play))
	{
		if (event_play.key.code == sf::Keyboard::Escape)
		{
			window->close();
		}
	}
}

void Engine::update(sf::Time& deltaTime)
{

}

void Engine::draw()
{
	window->clear();
	window->draw(background);
	window->display();
}

Engine::Engine()
{
	background.setTexture(&AssetManager::GetTexture("image/background.jpg"));
}

void Engine::run()
{
	GameMenu();

	sf::Clock clock;

	while (window->isOpen())
	{
		sf::Time dt = clock.restart();

		input();
		update(dt);
		draw();
	}
}

void Engine::GameMenu()
{
	sf::RenderWindow window;

	window.create(sf::VideoMode::getDesktopMode(), L"Battle city", sf::Style::Fullscreen);
	window.setMouseCursorVisible(false);

	float width = sf::VideoMode::getDesktopMode().width;
	float height = sf::VideoMode::getDesktopMode().height;

	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	background.setTexture(&AssetManager::GetTexture("image/background.jpg"));
	
	std::vector<sf::String>name_menu{ L"1 Player", L"2 Player", "     Exit" };
	 
	game::GameMenu mymenu(window, 200, 585, name_menu, 70, 140);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					mymenu.moveUp();
				}

				if (event.key.code == sf::Keyboard::Down)
				{
					mymenu.moveDown();
				}

				if (event.key.code == sf::Keyboard::Return)
				{
					switch (mymenu.getSelectedMenuNumber())
					{
					case 0:
						SingleGame(window);
						break;
					case 1:
						continue;
					case 2:
						exit(0);
						break;
					default:
						break;
					}
				}
			}

			window.clear();
			window.draw(background);
			mymenu.draw();
			window.display();
		}
	}
}

void Engine::RenderMap(sf::RenderWindow& window)
{

}

void Engine::SingleGame(sf::RenderWindow& window)
{
	const int MAP_WIDTH = 26;
	const int MAP_HIGHT = 25;
	sf::String firstLevelMap[MAP_HIGHT] =
	{
		"                          ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##          ##  ##  ",
		"  ##  ##          ##  ##  ",
		"          ##  ##          ",
		"          ##  ##          ",
		"##  ####          ####  ##",
		"ww  ####          ####  ww",
		"          ##  ##          ",
		"          ######          ",
		"  ##  ##  ######  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##  ##  ##  ##  ##  ",
		"  ##  ##          ##  ##  ",
		"  ##  ##          ##  ##  ",
		"  ##  ##   ####   ##  ##  ",
		"           #  #           ",
		"           #  #           ",
	};

	sf::Image mapImage;
	mapImage.loadFromFile("image/tiles.png");
	sf::Texture map;
	map.loadFromImage(mapImage);
	sf::Sprite s_Map;
	s_Map.setTexture(map);

	float width = sf::VideoMode::getDesktopMode().width;
	float height = sf::VideoMode::getDesktopMode().height;

	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	background.setTexture(&AssetManager::GetTexture("image/game.png"));

	sf::Image playerImage;
	playerImage.loadFromFile("image/tank.png");
	Tank p1(playerImage, 800, 990, 40, 40, "Player1");

	sf::Image bulletImage;
	bulletImage.loadFromFile("image/bullet.png");

	std::list<Entity*> entities;
	std::list<Entity*>::iterator it;
	std::list<Entity*>::iterator i2;

	sf::Clock clock;
	while (window.isOpen()) {

		float CurrentFrame = 0;
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		sf::Event event;
		while (window.pollEvent(event))
		{	
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					entities.push_back(new Bullet(bulletImage, p1.x, p1.y, 8, 8, p1.state, "Bullet"));
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					exit(1);
				}
			}
		}

		for (it = entities.begin(); it != entities.end();)
		{
			Entity* b = *it;
			b->update(time);
			if (b->life == false)
			{
				it = entities.erase(it);
				delete b;
			}
			else
			{
				it++;
			}
		}
		p1.update(time);
		window.clear();
		
		window.draw(background);

		for (int i = 0; i < MAP_HIGHT; ++i)
		{
			for (int j = 0; j < MAP_WIDTH; ++j)
			{
				if (firstLevelMap[i][j] == '#') s_Map.setTextureRect(sf::IntRect(120, 120, 40, 40));
				if (firstLevelMap[i][j] == ' ') s_Map.setTextureRect(sf::IntRect(0, 0, 40, 40));
				if (firstLevelMap[i][j] == 'w') s_Map.setTextureRect(sf::IntRect(160, 40, 40, 40));
				s_Map.setPosition(j * 40 + 440, i * 40 + 40);
				window.draw(s_Map);
			}
		}

		for (it = entities.begin(); it != entities.end(); it++)
		{
			window.draw((*it)->sprite);
		}
		window.draw(p1.sprite);
		window.display();
	}
}