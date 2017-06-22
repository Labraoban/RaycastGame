#include "stdafx.h"

#include "Image.h"
#include "TextureHandler.h"

using namespace UI;

Image::Image(const std::string& fileName) : Panel(sf::Vector2f(0, 0), sf::Vector2f(0, 0))
{
	TextureHandler* textureHandeler = ServiceLocator<TextureHandler>::Get();
	rectangleShape->setTexture(textureHandeler->LoadTexture(fileName));
}

Image::Image(const std::string& fileName, const sf::Vector2f& position, const sf::IntRect& textureCoordinates) : Image(fileName)
{
	SetPosition(position);
	SetSize(textureCoordinates.width, textureCoordinates.height);
	rectangleShape->setTextureRect(textureCoordinates);
}

Image::Image(const std::string& fileName, const float& x, const float& y, const sf::IntRect& textureCoordinates)
	 : Image(fileName, sf::Vector2f(x, y), textureCoordinates) {}


void Image::SetTextureRect(const sf::IntRect& textureText)
{
	rectangleShape->setTextureRect(textureText);
};

sf::IntRect Image::GetTextureRect()
{
	return rectangleShape->getTextureRect();
}
