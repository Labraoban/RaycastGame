#include "stdafx.h"
#include "Math.h"

int Math::Sign(const float& value)
{
	return (value >= 0.0f) ? 1 : (value < 0) ? -1 : 0;
}

int Math::Sign(const int& value)
{
	return (value >= 0) ? 1 : (value < 0) ? -1 : 0;
}

float Math::Clampf(const float&  value, const float&  min, const float& max)
{
	return (value < min) ? min : (value > max) ? max : value;
}

int Math::Clampi(const int&  value, const int&  min, const int& max)
{
	return (value < min) ? min : (value > max) ? max : value;
}

bool Math::WithinRange(const int& value, const int& min, const int& max)
{
	if (min > max)
		return false;

	return (value >= min && value < max);
}

bool Math::WithinRange(const float& value, const float& min, const float& max)
{
	if (min > max)
		return false;

	return (value >= min && value <= max);
}

bool Math::WithinRange(const double& value, const double& min, const double& max)
{
	if (min > max)
		return false;

	return (value >= min && value <= max);
}