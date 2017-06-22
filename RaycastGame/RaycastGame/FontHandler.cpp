#include "stdafx.h"

#include "FontHandler.h"


FontHandler::FontHandler(const std::string& filePath)
{
	this->filePath = filePath;
}

FontHandler::~FontHandler()
{
	auto it = fonts.begin();
	while (it != fonts.end())
	{
		delete it->second;
		it++;
	}
	fonts.clear();
}

sf::Font* FontHandler::LoadFont(const std::string& fontName)
{
	if (IsLoaded(fontName))
		return fonts[fontName];

	sf::Font* font = new sf::Font();
	font->loadFromFile(filePath + fontName);
	return font;
}

bool FontHandler::IsLoaded(const std::string& fontName)
{
	auto it = fonts.begin();
	while (it != fonts.end())
	{
		if (it->first == fontName)
			return true;
		it++;
	}
	return false;
};