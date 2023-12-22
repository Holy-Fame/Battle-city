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

Bonus::Bonus(sf::Texture& texture, int numBonuses, int fieldWidth, int fieldHeight, int duration)
    : m_texture(texture)
    , m_fieldWidth(fieldWidth)
    , m_fieldHeight(fieldHeight)
    , m_duration(duration)
{
    randomPlacementBonuses(numBonuses, fieldWidth, fieldHeight);
}

void Bonus::update(float deltaTime)
{
    for (auto it = m_bonuses.begin(); it != m_bonuses.end();)
    {
        if (it->clock.getElapsedTime().asSeconds() > m_duration)
        {
            it = m_bonuses.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Bonus::draw(sf::RenderWindow& window)
{
    for (const auto& bonus : m_bonuses)
    {
        window.draw(bonus.sprite);
    }
}

void Bonus::randomPlacementBonuses(int numBonuses, int fieldWidth, int fieldHeight)
{
    std::mt19937 seedGenerator;
    seedGenerator.seed(std::random_device()());
    std::uniform_int_distribution<int> seedDistributor;

    for (int i = 0; i < numBonuses; ++i)
    {
        int x = seedDistributor(seedGenerator) % fieldWidth;
        int y = seedDistributor(seedGenerator) % fieldHeight;

        BonusInfo bonusInfo;
        bonusInfo.sprite.setTexture(m_texture);
        bonusInfo.sprite.setPosition(x, y);
        bonusInfo.clock.restart();

        m_bonuses.push_back(bonusInfo);
    }
}