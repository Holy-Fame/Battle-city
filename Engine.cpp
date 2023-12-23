#include "Engine.h"
#include "Maps.h"
#include <random>

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

void printInterface(std::vector<Tank>& players, int enemysCount, sf::RenderWindow& window, int level)
{
	sf::Image interfaceImage;
	interfaceImage.loadFromFile("image/interface.png");
	sf::Texture interface;
	interface.loadFromImage(interfaceImage);
	sf::Sprite s_Interface;
	s_Interface.setTexture(interface);

	for (int i = 0; i < enemysCount; ++i)
	{
		s_Interface.setTextureRect(sf::IntRect(0, 0, 40, 40));
		s_Interface.setPosition( i % 2 * 40 + 1520, i / 2 * 40 + 20);
		window.draw(s_Interface);
	}

	for (int i = 0; i < players.size(); ++i)
	{
		if (i == 0)
		{
			s_Interface.setTextureRect(sf::IntRect(40, 0, 80, 80));
			s_Interface.setPosition(i + 1520, i + 540);
			window.draw(s_Interface);
			if (players[i].health == 3)
			{
				s_Interface.setTextureRect(sf::IntRect(0, 80, 40, 40));
				s_Interface.setPosition(1560, 580);
				window.draw(s_Interface);
			}
			else if (players[i].health == 2)
			{
				s_Interface.setTextureRect(sf::IntRect(0, 40, 40, 40));
				s_Interface.setPosition(1560, 580);
				window.draw(s_Interface);
			}
			if (players[i].health == 1)
			{
				s_Interface.setTextureRect(sf::IntRect(40, 80, 40, 40));
				s_Interface.setPosition(1560, 580);
				window.draw(s_Interface);
			}

		}
		if (i == 1)
		{
			s_Interface.setTextureRect(sf::IntRect(120, 0, 80, 80));
			s_Interface.setPosition(i + 1520, i * 100 + 540);
			window.draw(s_Interface);
			if (players[i].health == 3)
			{
				s_Interface.setTextureRect(sf::IntRect(0, 80, 40, 40));
				s_Interface.setPosition(1560, 680);
				window.draw(s_Interface);
			}
			else if (players[i].health == 2)
			{
				s_Interface.setTextureRect(sf::IntRect(0, 40, 40, 40));
				s_Interface.setPosition(1560, 680);
				window.draw(s_Interface);
			}
			if (players[i].health == 1)
			{
				s_Interface.setTextureRect(sf::IntRect(40, 80, 40, 40));
				s_Interface.setPosition(1560, 680);
				window.draw(s_Interface);
			}
		}
		if (level == 0)
			s_Interface.setTextureRect(sf::IntRect(0, 40, 40, 40));
		if (level == 1)
			s_Interface.setTextureRect(sf::IntRect(0, 80, 40, 40));
		if (level == 2)
			s_Interface.setTextureRect(sf::IntRect(80, 80, 40, 40));
		if (level == 3)
			s_Interface.setTextureRect(sf::IntRect(120, 80, 40, 40));
		if (level == 4)
			s_Interface.setTextureRect(sf::IntRect(160, 40, 40, 40));
	}
	s_Interface.setPosition(1560, 900);
	window.draw(s_Interface);
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
						SingleGame(window, mapsArr, botsFirstLevel, 0);
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

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void Engine::SingleGame(sf::RenderWindow& window, std::vector<sf::String*>& mapsArr, std::vector<std::string> bots, int levelNumber)
{
	float width = sf::VideoMode::getDesktopMode().width;
	float height = sf::VideoMode::getDesktopMode().height;

	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	background.setTexture(&AssetManager::GetTexture("image/game.png"));

	sf::Music startMusic;
	startMusic.openFromFile("sound/stage_start.ogg");
	startMusic.play();

	std::vector<Tank> players;
	sf::Image playerImage;
	playerImage.loadFromFile("image/tank.png");
	Tank p1(playerImage, 800, 980, 60, 60, "Player1");
	players.push_back(p1);

	sf::Image enemy1Image;
	enemy1Image.loadFromFile("image/enemy1.png");
	sf::Image enemy2Image;
	enemy2Image.loadFromFile("image/enemy2.png");

	std::list<Enemy*> enemies;
	std::list<Enemy*>::iterator ite;
	std::list<Enemy*>::iterator ite2;

	sf::Image bulletImage;
	bulletImage.loadFromFile("image/bullet.png");

	std::list<Entity*> bullets;
	std::list<Entity*>::iterator itb;

	float spawnTimer = 0;
	enemies.push_back(new Enemy(enemy1Image, getRandomNumber(450, 1400), 30, 60, 60, "Enemy1"));

	sf::Texture explosionTexture;
	explosionTexture.loadFromFile("image/explosion.png");
	std::vector<sf::IntRect> explosionFrames;
	for (int i = 0; i < 5; ++i)
	{
		explosionFrames.push_back(sf::IntRect(i * 30, 0, 30, 30));
	}


	sf::Sprite explosionSprite;
	explosionSprite.setTexture(explosionTexture);
	explosionSprite.setScale(2.5f, 2.5f);

	sf::Clock explosionClock;
	bool isExplosion = false;

	sf::SoundBuffer shootBuffer;
	shootBuffer.loadFromFile("sound/bullet_shot.ogg");
	sf::Sound shoot(shootBuffer);

	sf::SoundBuffer explosionBuffer;
	explosionBuffer.loadFromFile("sound/explosion.ogg");
	sf::Sound explosion(explosionBuffer);

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
					shoot.play();
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					exit(1);
				}
			}
		}

		spawnTimer += time;
		if (spawnTimer > 8000)
		{
			if (bots.size() != 0)
			{
				if (bots.back() == "Enemy1")
				{
					enemies.push_back(new Enemy(enemy1Image, getRandomNumber(450, 1400), 30, 60, 60, "Enemy1"));
				}
				else
				{
					enemies.push_back(new Enemy(enemy2Image, getRandomNumber(450, 1400), 30, 60, 60, "Enemy2"));
				}
				bots.pop_back();
				spawnTimer = 0;
			}
		}

		for (ite = enemies.begin(); ite != enemies.end(); ite++)
		{
			Enemy* e = *ite;
			if (e->sprite.getGlobalBounds().intersects(p1.sprite.getGlobalBounds()))
			{
				if (e->dx > 0)
				{
					e->x = p1.x - e->w;
					e->dx = 0;
				}
				if (e->dx < 0)
				{
					e->x = p1.x + e->w;
					e->dx = 0;
				}
				if (e->dy > 0)
				{
					e->y = p1.y - e->h;
					e->dy = 0;
				}
				if (e->dy < 0)
				{
					e->y = p1.y + e->h;
					e->dy = 0;
				}
				if (p1.dx > 0)
				{
					p1.x = e->x - p1.w;
				}
				if (p1.dx < 0)
				{
					p1.x = e->x + e->w;
				}
				if (p1.dy > 0)
				{
					p1.y = e->y - p1.h;
				}
				if (p1.dy < 0)
				{
					p1.y = e->y + e->h;
				}
			}
		}

		for (itb = bullets.begin(); itb != bullets.end(); itb++)
		{
			for (ite = enemies.begin(); ite != enemies.end(); ite++)
			{
				Entity* b = *itb;
				Enemy* e = *ite;
				if (b->sprite.getGlobalBounds().intersects(e->sprite.getGlobalBounds()))
				{
					b->life = false;
					e->health -= 1;

					if (e->health <= 0)
					{
						isExplosion = true;
						explosionClock.restart();
						explosionSprite.setPosition(e->x, e->y);
						explosion.play();
					}
				}
			}
		}

		for (itb = bullets.begin(); itb != bullets.end();)
		{
			Entity* b = *itb;
			b->update(time, mapsArr[levelNumber]);
			if (b->life == false)
			{
				itb = bullets.erase(itb);
				delete b;
			}
			else
			{
				itb++;
			}
		}
		
		for (ite = enemies.begin(); ite != enemies.end();)
		{
			Enemy* e = *ite;
			e->update(time, mapsArr[levelNumber]);
			if (e->life == false)
			{
				ite = enemies.erase(ite);
				delete e;
			}
			else
			{
				ite++;
			}
		}

		p1.update(time, mapsArr[levelNumber]);
		window.clear();
		
		window.draw(background);

		printMap(window, mapsArr[levelNumber]);

		if (isExplosion)
		{
			float elapsedSeconds = explosionClock.getElapsedTime().asSeconds();
			if (elapsedSeconds > 0.4f)
			{
				isExplosion = false;
			}
			else
			{
				int currentFrame = static_cast<int>(elapsedSeconds / (0.4f / 5.0f));
				explosionSprite.setTextureRect(explosionFrames[currentFrame]);
				window.draw(explosionSprite);
			}
		}

		printInterface(players, enemies.size(), window, levelNumber);

		for (itb = bullets.begin(); itb != bullets.end(); itb++)
		{
			window.draw((*itb)->sprite);
		}
		for (ite = enemies.begin(); ite != enemies.end(); ite++)
		{
			window.draw((*ite)->sprite);
		}
		window.draw(p1.sprite);
		window.display();
	}
}