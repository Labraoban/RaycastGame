#pragma once

#include <vector>
#include "Collider.h"


class Ray
{
public:
	Ray(const float& posX, const float& posY, const float& dirX, const float& dirY, const float& length);
	Ray(const sf::Vector2f& position, const sf::Vector2f& direction, const float& length);

	void SetPosition(const sf::Vector2f& position);
	void SetPosition(const float& posX, const float& posY);

	void SetDirection(const sf::Vector2f& direction);
	void SetDirection(const float& dirX, const float& dirY);

	void SetLength(const float& length);

	sf::Vector2f GetPosition();
	sf::Vector2f GetDirection();
	float GetLength();

	static void DrawRay(Ray ray, sf::Color color, sf::RenderWindow* renderWindow);
	static void DrawRay(const sf::Vector2f& start, const sf::Vector2f& end, sf::Color color, sf::RenderWindow* renderWindow);

private:

	sf::Vector2f position;
	sf::Vector2f direction;
	float length;
};