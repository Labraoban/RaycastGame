#include "stdafx.h"
#include "Sprite.h"
#include "TextureHandler.h"

Sprite::Sprite(const std::string& textureName)
{
	sf::Texture* texture = ServiceLocator<TextureHandler>::Get()->LoadTexture(textureName);
	sprite = new sf::Sprite(*texture);
}

Sprite::Sprite(const std::string& textureName, const sf::IntRect& rect) : Sprite(textureName)
{
	SetRect(rect);
}

Sprite::~Sprite()
{
	if (sprite != nullptr)
		delete sprite;
}

void Sprite::Update()
{
	sprite->setPosition(GetGlobalPosition());
}

void Sprite::SetRect(sf::IntRect rect)
{
	this->rect = rect;
	sprite->setTextureRect(rect);
}

sf::IntRect Sprite::GetRect()
{
	return rect;
}

int Sprite::GetWidth()
{
	return sprite->getTextureRect().width;
}

int Sprite::GetHeight()
{
	return sprite->getTextureRect().height;
}

void Sprite::SetColor(const sf::Color& color)
{
	return sprite->setColor(color);
}

sf::Color Sprite::GetColor(const int& x, const int& y)
{
	const sf::Texture* tex = sprite->getTexture();
	sf::Image image = tex->copyToImage();
	return image.getPixel(x, y);
}

sf::Color Sprite::GetColor(const sf::Vector2i& color)
{
	return GetColor(color.x, color.y);
}

sf::Color Sprite::GetColor(const sf::Vector2f& color)
{
	return GetColor(color.x, color.y);
}

sf::Sprite* Sprite::GetSFSprite()
{
	return sprite;
}