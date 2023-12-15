#include "Engine.h"
#include "GameMenu.h"
#include "Tank.h"

int main()
{
    //Engine game;

    //game.run();

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "f");

    float CurrentFrame = 0;
    sf::Clock clock;

    Tank t("tank.png", 250, 250, 40.0, 40.0);

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
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

		window.clear();
		window.draw(t.sprite);
		window.display();
    }

    return 0;
}