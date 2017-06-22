#include "stdafx.h"

#include "Element.h"
#include "Window.h"
using namespace UI;

Element::Element()
{
	window = ServiceLocator<Window>::Get();

	position	= sf::Vector2f(0.0f, 0.0f);
	scale		= 1.0f;
	baseColor	= sf::Color::White;
	size		= sf::Vector2f(0.0f, 0.0f);
	depthLayer	= 0;
}

sf::FloatRect Element::GetBounds()
{
	return sf::FloatRect(position, size * scale);
}

int Element::GetDepthLayer() const
{
	return depthLayer;
}

void Element::SetDepthLayer(const int& depthLayer)
{
	this->depthLayer = depthLayer;
}

sf::Vector2f Element::GetPosition()
{
	return position;
}
void Element::SetPosition(const sf::Vector2f& position)
{
	this->position = position;
	UpdatePosition();
}

void Element::SetPosition(const float& x, const float& y)
{
	SetPosition(sf::Vector2f(x, y));
	UpdatePosition();
}

float Element::GetScale()
{
	return scale;
}

void Element::SetScale(const float& scale)
{
	this->scale = scale;
	UpdateScale();
}

void Element::SetSize(const sf::Vector2f& size)
{
	this->size = size;
	UpdateSize();
}

void Element::SetSize(const float& width, const float& height)
{
	SetSize(sf::Vector2f(width, height));
}

sf::Vector2f Element::GetSize()
{
	return size;
}

void Element::SetCurrentColor(const sf::Color& currentColor)
{
	this->currentColor = currentColor;
	UpdateColor();
}

sf::Color Element::GetCurrentColor()
{
	return currentColor;
}

void Element::SetBaseColor(const sf::Color& baseColor)
{
	this->baseColor = baseColor;
	
}

sf::Color Element::GetBaseColor()
{
	return baseColor;
}