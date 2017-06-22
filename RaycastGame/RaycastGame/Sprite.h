#pragma once

#include "SFML\Graphics.hpp"
#include "Transform.h"

class Sprite : public Transform
{
	friend class Window;
public:
	Sprite(const std::string& textureName);
	Sprite(const std::string& textureName, const sf::IntRect& rect);

	~Sprite();

	virtual void Update();

	void SetRect(sf::IntRect rect);
	sf::IntRect GetRect();

	int GetWidth();
	int GetHeight();

	void SetColor(const sf::Color& color);
	sf::Color GetColor(const int& x, const int& y);
	sf::Color GetColor(const sf::Vector2i& color);
	sf::Color GetColor(const sf::Vector2f& color);

	sf::Sprite* GetSFSprite();

private:
	sf::Sprite* sprite;
	sf::IntRect rect;
};