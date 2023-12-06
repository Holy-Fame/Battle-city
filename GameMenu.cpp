#include "GameMenu.h"

void game::GameMenu::setInitText(sf::Text& text, sf::String str, float xpos, float ypos)
{
	text.setFont(AssetManager::GetFont("font/ROGFontsv1.6-Regular.ttf"));
	text.setFillColor(_menuTextColor);
	text.setString(str);
	text.setCharacterSize(_sizeFont);
	text.setPosition(xpos, ypos);	
}

game::GameMenu::GameMenu(sf::RenderWindow& window, float menuX, float menuY, std::vector<sf::String>& name, int sizeFont, int step):
	_menuX(menuX),
	_menuY(menuY),
	_step(step),
	_maxMenu(static_cast<int>(name.size())),
	_sizeFont(sizeFont),
	_mainMenu(name.size()),
	_window(window)
{
	for (int i = 0, ypos = static_cast<int>(menuY); i < _maxMenu; i++, ypos += _step)
	{
		setInitText(_mainMenu[i], name[i], _menuX, static_cast<float>(ypos));
	}
	_mainMenuSelected = 0;
	_mainMenu[_mainMenuSelected].setFillColor(_choseTextColor);
}

void game::GameMenu::draw()
{
	for (int i = 0; i < _maxMenu; i++)
	{
		_window.draw(_mainMenu[i]);
	}
}

void game::GameMenu::moveUp()
{
	_mainMenuSelected--;

	if (_mainMenuSelected >= 0)
	{
		_mainMenu[_mainMenuSelected].setFillColor(_choseTextColor);
		_mainMenu[_mainMenuSelected + 1].setFillColor(_menuTextColor);
	}
	else
	{
		_mainMenu[0].setFillColor(_menuTextColor);
		_mainMenuSelected = _maxMenu - 1;
		_mainMenu[_mainMenuSelected].setFillColor(_choseTextColor);
	}
}

void game::GameMenu::moveDown()
{
	_mainMenuSelected++;

	if (_mainMenuSelected < _maxMenu)
	{
		_mainMenu[_mainMenuSelected - 1].setFillColor(_menuTextColor);
		_mainMenu[_mainMenuSelected].setFillColor(_choseTextColor);
	}
	else
	{
		_mainMenu[_maxMenu - 1].setFillColor(_menuTextColor);
		_mainMenuSelected = 0;
		_mainMenu[_mainMenuSelected].setFillColor(_choseTextColor);
	}
}

void game::GameMenu::setColorTextMenu(sf::Color textColor, sf::Color choseColor, sf::Color borderColor)
{
	_menuTextColor = textColor;
	_choseTextColor = choseColor;

	for (int i = 0; i < _maxMenu; i++)
	{
		_mainMenu[i].setFillColor(_menuTextColor);
	}

	_mainMenu[_mainMenuSelected].setFillColor(_choseTextColor);
}

void game::GameMenu::alignMenu(int posx)
{
	float nullx = 0;

	for (int i = 0; i < _maxMenu; i++) {

		switch (posx)
		{
		case 0:
			nullx = 0;
			break;
		case 1:
			nullx = _mainMenu[i].getLocalBounds().width;
			break;
		case 2:
			nullx = _menuX - (_mainMenu[i].getLocalBounds().width / 2);
			break;
		default:break;
		}

		_mainMenu[i].setPosition(nullx, _mainMenu[i].getPosition().y);
	}
}

int game::GameMenu::getSelectedMenuNumber()
{
	return _mainMenuSelected;
}
