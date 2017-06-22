#pragma once


class Math
{
public:
	static int Sign(const float& value);
	static int Sign(const int& value);

	static float Clampf(const float&  value, const float&  min, const float& max);
	static int Clampi(const int&  value, const int&  min, const int& max);

	static bool WithinRange(const int& value, const int& min, const int& max);
	static bool WithinRange(const float& value, const float& min, const float& max);
	static bool WithinRange(const double& value, const double& min, const double& max);

};