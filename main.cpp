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
    // Создать окно sfml
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "f");

    // Загрузить изображение бонуса
    sf::Texture textureBonus;
    if (!textureBonus.loadFromFile("D:\\батла\\image\\bonus.png"))
        return -1;

    // Создать объект класса Bonus
    Bonus bonus(textureBonus, 10, 800, 600, 10);

    // Основной цикл sfml
    sf::Clock clock;
    while (window.isOpen())
    {
        // Обработка событий
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Очистить окно
        window.clear();

        // Обновить состояние бонусов
        bonus.update(clock.restart().asSeconds());

        // Нарисовать бонусы
        bonus.draw(window);

        // Отобразить содержимое окна
        window.display();
    }

    return 0;
}