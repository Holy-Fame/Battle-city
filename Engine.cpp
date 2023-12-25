#include "Engine.h"
#include "Maps.h"
#include "Bots.h"
#include <random>

void Immortality(sf::String* map, bool flag)
{
	if (flag)
	{
		map[23][11] = 'w';
		map[23][12] = 'w';
		map[23][13] = 'w';
		map[23][14] = 'w';
		map[24][11] = 'w';
		map[25][11] = 'w';
		map[24][14] = 'w';
		map[25][14] = 'w';
	}
	else
	{
		map[23][11] = '#';
		map[23][12] = '#';
		map[23][13] = '#';
		map[23][14] = '#';
		map[24][11] = '#';
		map[25][11] = '#';
		map[24][14] = '#';
		map[25][14] = '#';
	}
}

void printTableScore(std::vector<Tank>& players, sf::RenderWindow& window)
{
	sf::Image interfaceImage;
	interfaceImage.loadFromFile("image/interface.png");
	sf::Texture interface;
	interface.loadFromImage(interfaceImage);
	sf::Sprite s_Interface;
	s_Interface.setTexture(interface);

	sf::Image ScoreImage;

	if (players.size() == 1)
	{
		ScoreImage.loadFromFile("image/tableScore1.png");
	}
	else
	{
		ScoreImage.loadFromFile("image/tableScore2.png");
	}

	sf::Texture Score;
	Score.loadFromImage(ScoreImage);
	sf::Sprite s_Score;
	s_Score.setTexture(Score);
	s_Score.setTextureRect(sf::IntRect(0, 0, 1920, 1080));

	sf::Text txt;
	txt.setFont(AssetManager::GetFont("font/ROGFontsv1.6-Regular.ttf"));

	window.clear();
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		window.draw(s_Score);
		if (players.size() == 1)
		{

			txt.setString(std::to_string(players[0].playerScore));
			txt.setFillColor(sf::Color::Black);
			txt.setPosition(1100, 270);
			txt.setCharacterSize(100);
			window.draw(txt);
		}
		else
		{
			txt.setString(std::to_string(players[0].playerScore));
			txt.setFillColor(sf::Color::Black);
			txt.setPosition(1100, 270);
			txt.setCharacterSize(100);
			window.draw(txt);

			txt.setString(std::to_string(players[1].playerScore));
			txt.setFillColor(sf::Color::Black);
			txt.setPosition(1100, 525);
			txt.setCharacterSize(100);
			window.draw(txt);
		}
		window.display();
	}
}

void NextLevelPicture(sf::RenderWindow& window, int level)
{
	sf::Image interfaceImage;
	interfaceImage.loadFromFile("image/interface.png");
	sf::Texture interface;
	interface.loadFromImage(interfaceImage);
	sf::Sprite s_Interface;
	s_Interface.setTexture(interface);

	sf::Image nextLevelImage;
	nextLevelImage.loadFromFile("image/nextLevel.png");
	sf::Texture nextLevel;
	nextLevel.loadFromImage(nextLevelImage);
	sf::Sprite s_nextLevel;
	s_nextLevel.setTexture(nextLevel);
	s_nextLevel.setTextureRect(sf::IntRect(0, 0, 1920, 1080));

	window.clear();
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		window.draw(s_nextLevel);
		switch (level)
		{
		case (0):
			s_Interface.setTextureRect(sf::IntRect(0, 40, 40, 40));
			break;
		case (1):
			s_Interface.setTextureRect(sf::IntRect(0, 80, 40, 40));
			break;
		case (2):
			s_Interface.setTextureRect(sf::IntRect(80, 80, 40, 40));
			break;
		case (3):
			s_Interface.setTextureRect(sf::IntRect(120, 80, 40, 40));
			break;
		case (4):
			s_Interface.setTextureRect(sf::IntRect(160, 80, 40, 40));
			break;
		}
		s_Interface.setPosition(1050, 450);
		s_Interface.setScale(2, 2);
		window.draw(s_Interface);
		window.display();
	}

	return;
}

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
		s_Interface.setPosition(i % 2 * 40 + 1520, i / 2 * 40 + 20);
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
						GameRun(window, mapsArr, bots, 1);
						break;
					case 1:
						GameRun(window, mapsArr, bots, 2);
						break;
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

void Engine::GameRun(sf::RenderWindow& window, std::vector<sf::String*> mapsArr, std::vector<std::vector<std::string>> bots, int mode)
{
	if (SingleGame(window, mapsArr, bots, mode)) { GameRun(window, mapsArr, bots, mode); }
}

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

bool Engine::SingleGame(sf::RenderWindow& window, std::vector<sf::String*> mapsArr, std::vector<std::vector<std::string>> bots, int mode)
{
	float width = sf::VideoMode::getDesktopMode().width;
	float height = sf::VideoMode::getDesktopMode().height;

	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	background.setTexture(&AssetManager::GetTexture("image/game.png"));

	sf::Image pauseImage;
	pauseImage.loadFromFile("image/pause.png");
	sf::Texture pauseTexture;
	pauseTexture.loadFromImage(pauseImage);
	sf::Sprite pauseSprite;
	pauseSprite.setTexture(pauseTexture);

	sf::Image playerImage;
	playerImage.loadFromFile("image/tank.png");
	sf::Image playerImage2;
	playerImage2.loadFromFile("image/tank2.png");
	Tank p1(playerImage, 800, 980, 60, 60, "Player1");
	std::vector<Tank> players;
	players.push_back(p1);


	Tank p2(playerImage2, 740, 980, 60, 60, "Player2");
	if (mode == 2)
	{
		players.push_back(p2);
	}

	sf::Image enemy1Image;
	enemy1Image.loadFromFile("image/enemy1.png");
	sf::Image enemy2Image;
	enemy2Image.loadFromFile("image/enemy2.png");

	std::list<Enemy*> enemies;
	std::list<Enemy*>::iterator ite;
	std::list<Enemy*>::iterator ite2;

	std::list<Bonus*> bonuses;
	std::list<Bonus*>::iterator itbo;

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

	sf::Music startMusic;
	startMusic.openFromFile("sound/stage_start.ogg");

	bool isPause = false;

	sf::Clock clock;

	for (int levelNumber = 0; levelNumber < 5; ++levelNumber)
	{
		bool isStopTime = false;
		float stopTimeTimer = 0;
		bool isDef = false;
		float defTimer = 0;
		int botsCount = 10;
		NextLevelPicture(window, levelNumber);
		sf::String map[MAP_HIGHT];
		for (int i = 0; i < 26; ++i)
		{
			map[i] = mapsArr[levelNumber][i];
		}
		if (levelNumber == 0)
		{
			startMusic.play();
		}
		while (window.isOpen()) {
			float CurrentFrame = 0;
			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 800;

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (isPause == false && event.key.code == sf::Keyboard::Escape)
				{
					isPause = true;
				}

				if (isPause == true && event.key.code == sf::Keyboard::Return)
				{
					isPause = false;
				}

				if (isPause == true && event.key.code == sf::Keyboard::BackSpace)
				{
					return true;
				}

				if (event.type == sf::Event::KeyReleased && isPause == false)
				{
					if (event.key.code == sf::Keyboard::Space)
					{
						bullets.push_back(new Bullet(bulletImage, players[0].x, players[0].y, 10, 10, players[0].state, "Bullet1"));
						shoot.play();
					}
					if (event.key.code == sf::Keyboard::P)
					{
						bullets.push_back(new Bullet(bulletImage, players[1].x, players[1].y, 10, 10, players[1].state, "Bullet2"));
						shoot.play();
					}
					if (event.key.code == sf::Keyboard::O)
					{
						exit(1);
					}
				}
			}

			if (isStopTime == true)
			{
				stopTimeTimer += time;
			}

			if (stopTimeTimer > 5000)
			{
				isStopTime = false;
				stopTimeTimer = 0;
			}

			if (isDef == true)
			{
				defTimer += time;
			}

			if (defTimer > 10000)
			{
				isDef = false;
				Immortality(map, false);
				defTimer = 0;
			}

			if (isPause == false)
			{
				spawnTimer += time;
			}

			if (enemies.size() >= 5)
			{
				spawnTimer = 0;
			}

			if (spawnTimer > 3000 && isPause == false && isStopTime == false)
			{
				if (bots[levelNumber].size() != 0)
				{
					if (bots[levelNumber].back() == "Enemy1")
					{
						enemies.push_back(new Enemy(enemy1Image, getRandomNumber(450, 1400), 30, 60, 60, "Enemy1"));
					}
					else
					{
						enemies.push_back(new Enemy(enemy2Image, getRandomNumber(450, 1400), 30, 60, 60, "Enemy2"));
					}
					bots[levelNumber].pop_back();
					spawnTimer = 0;
				}
			}

			for (ite = enemies.begin(); ite != enemies.end(); ite++)
			{
				Enemy* e = *ite;
				for (int i = 0; i < players.size(); ++i)
				{
					if (e->sprite.getGlobalBounds().intersects(players[i].sprite.getGlobalBounds()))
					{
						if (e->dx > 0)
						{
							e->x = players[i].x - e->w;
							e->dx = 0;
						}
						if (e->dx < 0)
						{
							e->x = players[i].x + e->w;
							e->dx = 0;
						}
						if (e->dy > 0)
						{
							e->y = players[i].y - e->h;
							e->dy = 0;
						}
						if (e->dy < 0)
						{
							e->y = players[i].y + e->h;
							e->dy = 0;
						}
						if (players[i].dx > 0)
						{
							players[i].x = e->x - players[i].w;
						}
						if (players[i].dx < 0)
						{
							players[i].x = e->x + e->w;
						}
						if (players[i].dy > 0)
						{
							players[i].y = e->y - players[i].h;
						}
						if (players[i].dy < 0)
						{
							players[i].y = e->y + e->h;
						}
					}
				}
			}

			for (itb = bullets.begin(); itb != bullets.end(); itb++)
			{
				Entity* b = *itb;
				for (int i = 0; i < players.size(); ++i)
				{
					if (b->sprite.getGlobalBounds().intersects(players[i].sprite.getGlobalBounds()) && b->name == "BulletEnemy")
					{
						b->life = false;
						players[i].health -= 1;
						players[i].x = 800;
						players[i].y = 980;

						if (players[i].health <= 0)
						{
							isExplosion = true;
							explosionClock.restart();
							explosionSprite.setPosition(players[i].x, players[i].y);
							explosion.play();
						}
					}
				}
				for (ite = enemies.begin(); ite != enemies.end(); ite++)
				{
					Entity* b = *itb;
					Enemy* e = *ite;
					if (b->sprite.getGlobalBounds().intersects(e->sprite.getGlobalBounds()) && b->name != "BulletEnemy")
					{
						b->life = false;
						e->health -= 1;
						if (b->name == "Bullet1")
						{
							players[0].playerScore += e->name == "Enemy1" ? 100 : 200;
						}
						else
						{
							players[1].playerScore += e->name == "Enemy1" ? 100 : 200;
						}

						if (e->health <= 0)
						{
							if (botsCount % 4 == 0)
							{
								Bonus::Spawn(bonuses, e->x, e->y);
							}

							isExplosion = true;
							explosionClock.restart();
							explosionSprite.setPosition(e->x, e->y);
							explosion.play();
						}
					}
				}
			}


			for (itbo = bonuses.begin(); itbo != bonuses.end();)
			{
				Bonus* b = *itbo;

				for (int i = 0; i < players.size(); ++i)
				{
					if (players[i].sprite.getGlobalBounds().intersects(b->sprite.getGlobalBounds()))
					{
						if (b->name == "hp" && players[i].health < 3)
						{
							players[i].health += 1;
						}

						if (b->name == "time")
						{
							isStopTime = true;
						}

						if (b->name == "def")
						{
							isDef = true;
							Immortality(map, true);
						}

						itbo = bonuses.erase(itbo);
						delete b;
					}
					else if (i == players.size() - 1 && itbo != bonuses.end())
					{
						itbo++;
					}
				}
			}

			if (isPause == false)
			{
				for (ite = enemies.begin(); ite != enemies.end();)
				{
					Enemy* e = *ite;
					if (isStopTime == false)
					{
						e->update(time, map, bullets);
					}

					if (e->life == false)
					{
						ite = enemies.erase(ite);
						delete e;
						--botsCount;
					}
					else
					{
						ite++;
					}
				}
			}

			if (isPause == false)
			{
				for (int i = 0; i < players.size(); ++i)
				{
					players[i].update(time, map);
				}
			}

			window.clear();

			window.draw(background);

			printMap(window, map);

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
			printInterface(players, bots[levelNumber].size(), window, levelNumber);
			if (botsCount == 0)
			{
				for (itb = bullets.begin(); itb != bullets.end();)
				{
					Entity* b = *itb;
					itb = bullets.erase(itb);
					delete b;
				}

				for (int i = 0; i < players.size(); ++i)
				{
					players[i].x = 800;
					players[i].y = 980;
					players[i].sprite.setTextureRect(sf::IntRect(0, 180, 60, 60));
					window.draw(players[i].sprite);
				}
				break;
			}

			if (players.size() == 2)
			{
				if (players[0].health <= 0 && players[1].health <= 0)
				{
					return GameOver(players, window);
				}
			}
			else
			{
				if (players[0].health <= 0)
				{
					return GameOver(players, window);
				}
			}

			for (itb = bullets.begin(); itb != bullets.end();)
			{
				Entity* b = *itb;
				if (b->x > 925 && b->x < 995 && b->y>990 && b->y < 1060)
				{
					return GameOver(players, window);
				}
				itb++;
			}

			if (isPause == false)
			{
				for (itb = bullets.begin(); itb != bullets.end();)
				{
					Entity* b = *itb;
					b->update(time, map);
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
			}

			for (itb = bullets.begin(); itb != bullets.end(); itb++)
			{
				window.draw((*itb)->sprite);
			}


			for (ite = enemies.begin(); ite != enemies.end(); ite++)
			{
				window.draw((*ite)->sprite);
			}

			if (players.size() == 2)
			{
				for (int i = 0; i < 2; ++i)
				{
					if (players[0].health > 0 && players[1].health > 0)
						window.draw(players[i].sprite);
					if (players[0].health > 0 && players[1].health <= 0)
					{
						players[1].x = 995;
						players[1].y = 990;
						window.draw(players[0].sprite);
						break;
					}
					if (players[0].health <= 0 && players[1].health > 0)
					{
						players[0].x = 995;
						players[0].y = 990;
						window.draw(players[1].sprite);
						break;
					}
				}
			}
			else
			{
				window.draw(players[0].sprite);
			}


			if (isPause)
			{
				window.draw(pauseSprite);
			}

			for (itbo = bonuses.begin(); itbo != bonuses.end(); itbo++)
			{
				window.draw((*itbo)->sprite);
			}

			window.display();
		}

		enemies.push_back(new Enemy(enemy1Image, getRandomNumber(450, 1400), 30, 60, 60, "Enemy1"));
	}
	printTableScore(players, window);
	return false;
}

bool Engine::GameOver(std::vector<Tank>& players, sf::RenderWindow& window)
{
	sf::Image gameOverImage;
	gameOverImage.loadFromFile("image/gameOver.png");
	sf::Texture gameOverTexture;
	gameOverTexture.loadFromImage(gameOverImage);
	sf::Sprite gameOverSprite;
	gameOverSprite.setTexture(gameOverTexture);
	gameOverSprite.setPosition(836, 1080);

	float speed = 0.5f;
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		float deltaTime = 0.1f;
		gameOverSprite.move(0, -speed * deltaTime);
		if (gameOverSprite.getPosition().y < window.getSize().y / 2 - gameOverSprite.getLocalBounds().height / 2)
		{
			gameOverSprite.setPosition(gameOverSprite.getPosition().x, window.getSize().y / 2 - gameOverSprite.getLocalBounds().height / 2);
		}
		window.clear();
		window.draw(gameOverSprite);
		window.display();
	}

	printTableScore(players, window);
	return false;
}

