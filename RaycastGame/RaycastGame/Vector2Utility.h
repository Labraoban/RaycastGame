#pragma once

#include "SFML\Graphics.hpp"

class Vector2Utility
{
public:

	//Float
	static sf::Vector2f Normalize(const sf::Vector2f& vector);
	static float Length(const sf::Vector2f& vector);
	static float Distance(const sf::Vector2f& first, const sf::Vector2f& second);

	//Interger
	static float Length(const sf::Vector2i& vector);
	static float Distance(const sf::Vector2i& first, const sf::Vector2i& second);

	static sf::Vector2f Rotate(const sf::Vector2f& vector, const float& angle);

	static sf::Vector2f Lerp(const sf::Vector2f& vector, const sf::Vector2f& target, float& amount);

	static float Angle(const sf::Vector2f& vector);
	static float Angle(const sf::Vector2f& first, const sf::Vector2f& second);

	//MoveThis
	static double Deg2Rad(double degrees);
	static double Rad2Deg(double radians);
private:



};

