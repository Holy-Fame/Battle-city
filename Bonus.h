#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <vector>
#include "Entity.h"


class Bonus
{
public:
    Bonus(sf::Texture& texture, int numBonuses, int fieldWidth, int fieldHeight, int duration);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    struct BonusInfo
    {
        sf::Sprite sprite;
        sf::Clock clock;
    };

    void randomPlacementBonuses(int numBonuses, int fieldWidth, int fieldHeight);

    sf::Texture& m_texture;
    int m_fieldWidth;
    int m_fieldHeight;
    int m_duration;
    std::vector<BonusInfo> m_bonuses;
};

