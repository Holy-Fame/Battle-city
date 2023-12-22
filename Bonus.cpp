//#include <SFML/Graphics.hpp>
//#include "Bonus.h"
//#include "random"
//
//
//Bonus::Bonus(sf::Image& image, float X, float Y, int W, int H, sf::String Name):Entity(image, X, Y, W, H, Name)
//{
//    m_bonus_show_time = 0;
//    m_show = true;
//}
//
//void Bonus::draw()
//{
//    if (m_show) Entity::draw();
//}
//
//void Bonus::deleteBonus(float dt, sf::String* level,float X, float Y)
//{
//    m_bonus_show_time += dt;
//    if (m_bonus_show_time > bonus_show_time)
//        life = false; level[X][Y] = ' ';
//}
//
//void Bonus::update(float dt,sf::String* level)
//{
//    Entity::update(dt,level);
//    x = rand() % MAP_WIDTH;
//    y = rand() % MAP_HIGHT;
//
//    if (m_bonus_show_time / (m_bonus_show_time < bonus_show_time / 4 * 3 ? bonus_blink_time : bonus_blink_time / 2) % 2)
//        m_show = true;
//    else m_show = false;
//}
//
//void randomPlacementBonuses(sf::RenderWindow& window, sf::Sprite& spriteBonus, int numBonuses, int fieldWidth, int fieldHeight)
//{
//    // Рандомное число для размещения бонусов
//    std::mt19937 seedGenerator;
//    seedGenerator.seed(std::random_device()());
//    std::uniform_int_distribution<int> seedDistributor;
//
//    // Рандомное размещение бонусов на поле
//    for (int i = 0; i < numBonuses; ++i)
//    {
//        // Сгенерировать случайные координаты
//        int x = seedDistributor(seedGenerator) % fieldWidth;
//        int y = seedDistributor(seedGenerator) % fieldHeight;
//
//        // Установить позицию спрайта бонуса
//        spriteBonus.setPosition(x, y);
//
//        // Отобразить спрайт бонуса на экране
//        window.draw(spriteBonus);
//    }
//}