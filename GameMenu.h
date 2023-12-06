#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "AssetManager.h"

namespace game
{
	class GameMenu
	{
		float _menuX;
		float _menuY;
		int _step;
		int _maxMenu;
		int _sizeFont;
		int _mainMenuSelected;

		std::vector<sf::Text> _mainMenu;

		sf::Color _menuTextColor = sf::Color::Black;
		sf::Color _choseTextColor = sf::Color{ 237, 102, 5 };

		sf::RenderWindow& _window;

		void setInitText(sf::Text& text, sf::String str, float xpos, float ypos);

	public:
		GameMenu(sf::RenderWindow& window, float menuX, float menuY, std::vector<sf::String>& name, int sizeFont, int step);
		void draw();
		void moveUp();
		void moveDown();
		void setColorTextMenu(sf::Color textColor, sf::Color choseColor, sf::Color borderColor);
		void alignMenu(int posx);
		int getSelectedMenuNumber();
	};

}

