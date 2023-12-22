#include "Engine.h"
#include "GameMenu.h"
#include "Tank.h"
#include "Bonus.h"
//
//int main()
//{
//    Engine game;
//    game.run();
//    return 0;
//}

int main()
{
    // ������� ���� sfml
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "f");

    // ��������� ����������� ������
    sf::Texture textureBonus;
    if (!textureBonus.loadFromFile("D:\\�����\\image\\bonus.png"))
        return -1;

    // ������� ������ ������ Bonus
    Bonus bonus(textureBonus, 10, 800, 600, 10);

    // �������� ���� sfml
    sf::Clock clock;
    while (window.isOpen())
    {
        // ��������� �������
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // �������� ����
        window.clear();

        // �������� ��������� �������
        bonus.update(clock.restart().asSeconds());

        // ���������� ������
        bonus.draw(window);

        // ���������� ���������� ����
        window.display();
    }

    return 0;
}