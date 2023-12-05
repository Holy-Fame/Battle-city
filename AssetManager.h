#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <string.h>
#include <assert.h>

class AssetManager
{
	std::map<std::string, sf::SoundBuffer> SoundBuffer;
	std::map<std::string, sf::Texture> Texture;
	std::map<std::string, sf::Font> Font;

	static AssetManager* ObjectManager;

public:
	AssetManager();

	static sf::SoundBuffer& GetSoundBuffer(const std::string& fileName);
	static sf::Texture& GetTexture(const std::string& fileName);
	static sf::Font& GetFont(const std::string& fileName);
};

