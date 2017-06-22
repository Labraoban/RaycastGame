#include "stdafx.h"

#include "TextureHandler.h"

TextureHandler::TextureHandler(const std::string& filePath)
{
	this->filePath = filePath;
	textures = new std::map<std::string, sf::Texture*>();
}

TextureHandler::~TextureHandler()
{
	auto it = textures->begin();
	while (it != textures->end())
	{
		delete it->second;
		it++;
	}
	textures->clear();
	delete textures;
}

sf::Texture* TextureHandler::LoadTexture(const std::string& textureName)
{
	if (IsLoaded(textureName))
		return textures->at(textureName);

	sf::Texture* newTex = new sf::Texture();
	newTex->loadFromFile(filePath + textureName);

	textures->insert(std::pair<std::string, sf::Texture*>(textureName, newTex));
	
	return newTex;
}

void TextureHandler::UnloadTexture(const std::string& textureName)
{
	if (IsLoaded(textureName))
	{
		sf::Texture* texture = textures->at(textureName);
		delete texture;
		textures->erase(textureName);
	}
}

sf::Texture* TextureHandler::GetTexture(const std::string& textureName)
{
	auto it = textures->begin();
	while (it != textures->end())
	{
		if (it->first == textureName)
			return it->second;
		it++;
	}
	return nullptr;
}

bool TextureHandler::IsLoaded(const std::string& textureName)
{
	if (textures->empty())
		return false;

	auto it = textures->begin();
	while (it != textures->end())
	{
		if (it->first == textureName)
			return true;
		it++;
	}
	return false;
}