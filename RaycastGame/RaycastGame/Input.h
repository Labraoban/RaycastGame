#pragma once

#include "Window.h"

class Input
{
	friend class Engine;
public:
	Input(Window* window);
	~Input();

private:
	void Update();

public:
	bool GetKey(sf::Keyboard::Key key);
	bool GetKeyPressed(sf::Keyboard::Key key);
	bool GetKeyReleased(sf::Keyboard::Key key);

	bool GetMouseButton(sf::Mouse::Button button);
	bool GetMousePressed(sf::Mouse::Button button);
	bool GetMouseReleased(sf::Mouse::Button button);


	sf::Vector2i GetMousePosition();
	sf::Vector2i GetMouseDelta();

private:
	bool current[sf::Keyboard::KeyCount];
	bool previous[sf::Keyboard::KeyCount];

	bool mouseCurrent[sf::Mouse::ButtonCount];
	bool mousePrevious[sf::Mouse::ButtonCount];

	sf::Vector2i mousePosition;
	sf::Vector2i prevMousePosition;

	sf::RenderWindow* renderWindow;
};