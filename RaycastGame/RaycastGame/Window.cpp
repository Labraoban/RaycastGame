#include "stdafx.h"
#include "Window.h"

Window::Window(const int& width, const int& height, const int& fps)
{
	renderWindow = new sf::RenderWindow(sf::VideoMode(width, height), "Cool Window");
	renderWindow->setFramerateLimit(fps);

	//view = sf::View();
	//view.setSize(width, height);
 //   view.zoom(0.5f);
	//view.setCenter(100, 100);
	//
	//renderWindow->setView(view);
	//renderWindow->setMouseCursorGrabbed(true);

}

Window::~Window()
{
	if (renderWindow != nullptr)
		delete renderWindow;
}


void Window::Draw(sf::Drawable& drawable)
{
	renderWindow->draw(drawable);
}

void Window::Draw(Sprite* sprite)
{
	sprite->Update();
	Draw(*sprite->sprite);
};

void Window::Display()
{
	renderWindow->display();
}

void Window::SetClearColor(const sf::Color& clearColor)
{
	this->clearColor = clearColor;
}

void Window::Clear()
{
	renderWindow->clear(clearColor);
}

sf::RenderWindow* Window::GetRenderWindow()
{
	return renderWindow;
};