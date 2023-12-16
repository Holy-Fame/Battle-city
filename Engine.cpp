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


	while (window.isOpen()) {

		float CurrentFrame = 0;
		sf::Clock clock;

		Tank t("tank.png", 800, 1000, 40.0, 40.0);

		while (window.isOpen())
		{
			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 800;

			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				exit(1);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				t.dir = 1; t.speed = 0.1;
				CurrentFrame += 0.005 * time;
				if (CurrentFrame > 2) CurrentFrame -= 2;
				t.sprite.setTextureRect(sf::IntRect(40 * int(CurrentFrame), 40, 40, 40));
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				t.dir = 0; t.speed = 0.1;
				CurrentFrame += 0.005 * time;
				if (CurrentFrame > 2) CurrentFrame -= 2;
				t.sprite.setTextureRect(sf::IntRect(40 * int(CurrentFrame), 80, 40, 40));
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				t.dir = 3; t.speed = 0.1;
				CurrentFrame += 0.005 * time;
				if (CurrentFrame > 2) CurrentFrame -= 2;
				t.sprite.setTextureRect(sf::IntRect(40 * int(CurrentFrame), 120, 40, 40));

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				t.dir = 2; t.speed = 0.1;
				CurrentFrame += 0.005 * time;
				if (CurrentFrame > 2) CurrentFrame -= 2;
				t.sprite.setTextureRect(sf::IntRect(40 * int(CurrentFrame), 0, 40, 40));

			}

			t.update(time);

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
			window.draw(t.sprite);
			window.display();
		}
	}
}