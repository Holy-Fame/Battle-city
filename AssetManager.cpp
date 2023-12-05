#include "AssetManager.h"

AssetManager* AssetManager::ObjectManager = nullptr;

AssetManager::AssetManager()
{
	assert(ObjectManager == nullptr);
	ObjectManager = this;
}

sf::SoundBuffer& AssetManager::GetSoundBuffer(const std::string& fileName)
{
	auto& bufferMap = ObjectManager->SoundBuffer;
	auto pairFound = bufferMap.find(fileName);

	if (pairFound != bufferMap.end())
	{
		return pairFound->second;
	}
	else
	{
		auto& buffer = bufferMap[fileName];
		buffer.loadFromFile(fileName);
		return buffer;
	}
}

sf::Texture& AssetManager::GetTexture(const std::string& fileName)
{
	auto& textureMap = ObjectManager->Texture;
	auto pairFound = textureMap.find(fileName);

	if (pairFound != textureMap.end())
	{
		return pairFound->second;
	}
	else
	{
		auto& texture = textureMap[fileName];
		texture.loadFromFile(fileName);
		return texture;
	}
}

sf::Font& AssetManager::GetFont(const std::string& fileName)
{
	auto& fontMap = ObjectManager->Font;
	auto pairFound = fontMap.find(fileName);

	if (pairFound != fontMap.end())
	{
		return pairFound->second;
	}
	else
	{
		auto& font = fontMap[fileName];
		font.loadFromFile(fileName);
		return font;
	}
}
