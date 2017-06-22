#include "stdafx.h"
#include "Input.h"
#include "Engine.h"

Input::Input(Window* window)
{
	renderWindow = window->GetRenderWindow();
}


Input::~Input()
{

}

void Input::Update()
{
	prevMousePosition = mousePosition;
	mousePosition = sf::Mouse::getPosition(*renderWindow);

	if (GetKey(sf::Keyboard::LAlt) && GetKey(sf::Keyboard::F4))
		Engine::Shutdown();

	for (int i = 0; i < sf::Keyboard::KeyCount; ++i)
	{
		previous[i] = current[i];
	}
	for (int i = 0; i < sf::Mouse::ButtonCount; ++i)
	{
		mousePrevious[i] = mouseCurrent[i];
	}

	sf::Event event;
	while (renderWindow->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			Engine::Shutdown();
			break;
		case sf::Event::KeyPressed:
			current[event.key.code] = true;
			break;
		case sf::Event::KeyReleased:
			current[event.key.code] = false;
			break;
		case sf::Event::MouseButtonPressed:
			mouseCurrent[event.mouseButton.button] = true;
			break;
		case sf::Event::MouseButtonReleased:
			mouseCurrent[event.mouseButton.button] = false;
			break;
		default:
			break;
		}
	}
}

bool Input::GetKey(sf::Keyboard::Key key)
{
	return current[key];
}
bool Input::GetKeyPressed(sf::Keyboard::Key key)
{
	return current[key] && !previous[key];
}
bool Input::GetKeyReleased(sf::Keyboard::Key key)
{
	return !current[key] && previous[key];
}

bool Input::GetMouseButton(sf::Mouse::Button button)
{
	return mouseCurrent[button];
}
bool Input::GetMousePressed(sf::Mouse::Button button)
{
	return mouseCurrent[button] && !mousePrevious[button];
}
bool Input::GetMouseReleased(sf::Mouse::Button button)
{
	return !mouseCurrent[button] && mousePrevious[button];
}

sf::Vector2i Input::GetMousePosition()
{
	return mousePosition;
};

sf::Vector2i Input::GetMouseDelta()
{
	return prevMousePosition - mousePosition;
};