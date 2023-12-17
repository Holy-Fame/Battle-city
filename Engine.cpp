#include "Engine.h"
#include "Maps.h"

int printMap(sf::RenderWindow& window, sf::String* level)
{
	sf::Image mapImage;
	mapImage.loadFromFile("image/tiles.png");
	sf::Texture map;
	map.loadFromImage(mapImage);
	sf::Sprite s_Map;
	s_Map.setTexture(map);

	for (int i = 0; i < MAP_HIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (level[i][j] == '#') s_Map.setTextureRect(sf::IntRect(120, 120, 40, 40));
			if (level[i][j] == ' ') s_Map.setTextureRect(sf::IntRect(0, 0, 40, 40));
			if (level[i][j] == 'w') s_Map.setTextureRect(sf::IntRect(160, 40, 40, 40));

			if (level[i][j] == 'q') s_Map.setTextureRect(sf::IntRect(160, 120, 40, 40));
			if (level[i][j] == 'o') s_Map.setTextureRect(sf::IntRect(200, 120, 40, 40));
			if (level[i][j] == 'e') s_Map.setTextureRect(sf::IntRect(160, 160, 40, 40));
			if (level[i][j] == 'r') s_Map.setTextureRect(sf::IntRect(200, 160, 40, 40));

			if (level[i][j] == '_') s_Map.setTextureRect(sf::IntRect(60, 120, 40, 40));
			if (level[i][j] == '-') s_Map.setTextureRect(sf::IntRect(120, 0, 40, 40));
			if (level[i][j] == ')') s_Map.setTextureRect(sf::IntRect(80, 100, 40, 40));
			if (level[i][j] == '(') s_Map.setTextureRect(sf::IntRect(40, 60, 40, 40));

			s_Map.setPosition(j * 40 + 440, i * 40 + 20);
			window.draw(s_Map);
		}
	}
	return 0;
}

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
						SingleGame(window, mapsArr);
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

void Engine::SingleGame(sf::RenderWindow& window, std::vector<sf::String*>& mapsArr)
{


	float width = sf::VideoMode::getDesktopMode().width;
	float height = sf::VideoMode::getDesktopMode().height;

	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	background.setTexture(&AssetManager::GetTexture("image/game.png"));

	sf::Image playerImage;
	playerImage.loadFromFile("image/enemy2.png");
	Tank p1(playerImage, 800, 960, 60, 60, "Player1");

	sf::Image bulletImage;
	bulletImage.loadFromFile("image/bullet.png");

	std::list<Entity*> bullets;
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
					bullets.push_back(new Bullet(bulletImage, p1.x, p1.y, 10, 10, p1.state, "Bullet"));
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					exit(1);
				}
			}
		}

		for (it = bullets.begin(); it != bullets.end();)
		{
			Entity* b = *it;
			b->update(time, mapsArr[1]);
			if (b->life == false)
			{
				it = bullets.erase(it);
				delete b;
			}
			else
			{
				it++;
			}
		}
		p1.update(time, mapsArr[1]);
		window.clear();
		
		window.draw(background);

		printMap(window, mapsArr[1]);

		for (it = bullets.begin(); it != bullets.end(); it++)
		{
			window.draw((*it)->sprite);
		}
		window.draw(p1.sprite);
		window.display();
	}
}