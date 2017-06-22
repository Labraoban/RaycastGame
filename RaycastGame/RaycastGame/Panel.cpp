#include "stdafx.h"
#include "Panel.h"

using namespace UI;

Panel::Panel(const sf::Vector2f& position, const sf::Vector2f& size)
{
	rectangleShape = new sf::RectangleShape();
	this->position = position;
	this->size     = size;
}

Panel::Panel(const float& left, const float& top, const float& width, const float& height) 
	 : Panel(sf::Vector2f(left, top), sf::Vector2f(width, height)) {}

Panel::Panel(const float& left, const float& top, const float& width, const float& height, const sf::Color& baseColor)
	: Panel(left, top, width, height) 
{
	this->baseColor = baseColor;
	this->currentColor = baseColor;
}


Panel::~Panel()
{
	if (rectangleShape != nullptr) 
		delete rectangleShape;
}

void Panel::Initialize()
{
	UpdatePosition();
	UpdateScale();
	UpdateSize();
	UpdateScale();
	UpdateColor();
}

void Panel::Draw()
{
	window->Draw(*rectangleShape);
}

void Panel::UpdatePosition()
{
	rectangleShape->setPosition(GetPosition());
}

void Panel::UpdateScale()
{
	float scale = GetScale();
	rectangleShape->setScale(scale, scale);
}

void Panel::UpdateSize()
{
	rectangleShape->setSize(GetSize());
}

void Panel::UpdateColor()
{
	rectangleShape->setFillColor(GetCurrentColor());
}