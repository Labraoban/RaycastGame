#pragma once

#include "SFML\Graphics.hpp"
#include <string>
#include <map>

class FontHandler

{
public:
	FontHandler(const std::string& filePath);
	~FontHandler();

	sf::Font* LoadFont(const std::string& fontName);

private:
	bool IsLoaded(const std::string& fontName);
private:
	std::string filePath;
	std::map<std::string, sf::Font*> fonts;
	
};