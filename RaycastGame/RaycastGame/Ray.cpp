#include "stdafx.h"
#include "Ray.h"
#include "Vector2Utility.h"

Ray::Ray(const float& posX, const float& posY, const float& dirX, const float& dirY, const float& length)
{
	SetPosition(posX, posY);
	SetDirection(dirX, dirY);
	SetLength(length);
}

Ray::Ray(const sf::Vector2f& position, const sf::Vector2f& direction, const float& length)
{
	SetPosition(position);
	SetDirection(direction);
	SetLength(length);
}

void Ray::SetPosition(const sf::Vector2f& position)
{
	this->position = position;
}

void Ray::SetPosition(const float& posX, const float& posY)
{
	position = sf::Vector2f(posX, posY);
}

void Ray::SetDirection(const sf::Vector2f& direction)
{
	this->direction = Vector2Utility::Normalize(direction);
}

void Ray::SetDirection(const float& dirX, const float& dirY)
{
	direction = sf::Vector2f(dirX, dirY);
}

void Ray::SetLength(const float& length)
{
	this->length = length;
}

sf::Vector2f Ray::GetPosition()
{
	return position;
}

sf::Vector2f Ray::GetDirection()
{
	return direction;
}

float Ray::GetLength()
{
	return length;
}

void Ray::DrawRay(Ray ray, sf::Color color, sf::RenderWindow* renderWindow)
{
	DrawRay(ray.GetPosition(), ray.GetPosition() + ray.GetDirection() * ray.GetLength(), color, renderWindow);
};

void Ray::DrawRay(const sf::Vector2f& start, const sf::Vector2f& end, sf::Color color, sf::RenderWindow* renderWindow)
{
	sf::Vertex line[] =
	{
		sf::Vertex(start),
		sf::Vertex(end)
	};
	line[0].color = color;
	line[1].color = color;
	renderWindow->draw(line, 2, sf::Lines);
};