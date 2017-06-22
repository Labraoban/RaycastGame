#include "stdafx.h"
#include "Vector2Utility.h"
#define _USE_MATH_DEFINES
#include <math.h>

sf::Vector2f Vector2Utility::Normalize(const sf::Vector2f& vector)
{
	sf::Vector2f normalized;
	normalized.x = vector.x / Length(vector);
	normalized.y = vector.y / Length(vector);
	return normalized;
}

float Vector2Utility::Length(const sf::Vector2f& vector)
{
	return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}

float Vector2Utility::Distance(const sf::Vector2f& first, const sf::Vector2f& second)
{
	return sqrt(pow(second.x - first.x, 2) + pow(second.y - first.y, 2));
}

//Interger
float Vector2Utility::Length(const sf::Vector2i& vector)
{
	return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}

float Vector2Utility::Distance(const sf::Vector2i& first, const sf::Vector2i& second)
{
	return sqrt(pow(second.x - first.x, 2) + pow(second.y - first.y, 2));
}

sf::Vector2f Vector2Utility::Rotate(const sf::Vector2f& vector, const float& angle)
{
	double theta = Deg2Rad(angle);

	double cs = cos(theta);
	double sn = sin(theta);

	double px = (vector.x * cs) - (vector.y * sn);
	double py = (vector.x * sn) + (vector.y * cs);

	return sf::Vector2f(px, py);
}

sf::Vector2f Vector2Utility::Lerp(const sf::Vector2f& vector, const sf::Vector2f& target, float& amount)
{
	if (amount <= 0.0f)
		return vector;
	if (amount > 1.0f)
		return target;

	return vector + (target - vector) * amount;
}

double Vector2Utility::Deg2Rad(double degrees)
{
	return degrees * M_PI / 180.0f;
}

double Vector2Utility::Rad2Deg(double radians)
{
	return (180.0 / 3.14) * radians;
}

float Vector2Utility::Angle(const sf::Vector2f& vector)
{
	float angle = atan(1.0f);
	return Rad2Deg(angle);
}

float Vector2Utility::Angle(const sf::Vector2f& first, const sf::Vector2f& second)
{
	return atan2(second.y, second.x) - atan2(first.y, first.x);
}