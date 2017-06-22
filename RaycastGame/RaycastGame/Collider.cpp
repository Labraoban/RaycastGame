#include "stdafx.h"
#include "Collider.h"


void Collider::SetPosition(sf::Vector2f position)
{
	this->position = position;
	UpdatePosition();
}

void Collider::SetPosition(const float& x, const float& y)
{
	SetPosition(sf::Vector2f(x, y));
}