#pragma once

#include "SFML\Graphics.hpp"
#include "Sprite.h"

class Window
{
public:
	Window(const int& width, const int& height, const int& fps);
	~Window();

	void Draw(sf::Drawable& drawable);
	void Draw(Sprite* sprite);

	void Display();

	void SetClearColor(const sf::Color& clearColor);
	void Clear();
	sf::RenderWindow* GetRenderWindow();

private:
	sf::RenderWindow* renderWindow;
	
	sf::Color clearColor;
	sf::View view;
};

