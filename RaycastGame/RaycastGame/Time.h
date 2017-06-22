#pragma once

#include "SFML\System.hpp"

class Time
{
	friend class Engine;
public:

	static float GetScaledDeltaTime();
	static float GetDeltaTime();

	static void SetTimeScale(float timeScale);
	static float GetTimeScale();

private:
	static void UpdateDeltaTime();

	static float timeScale;
	static float deltaTime;

	static sf::Clock clock;
	static sf::Time time;
};

