#pragma once

#include <map>
#include "SFML\Graphics.hpp"


class TextureHandler
{
public:
	TextureHandler(const std::string& filePath);
	~TextureHandler();

	sf::Texture* LoadTexture(const std::string& textureName);

	void UnloadTexture(const std::string& textureName);

	sf::Texture* GetTexture(const std::string& textureName);

	bool IsLoaded(const std::string& textureName);

private:
	std::string filePath;

	std::map<std::string, sf::Texture*>* textures;

};

