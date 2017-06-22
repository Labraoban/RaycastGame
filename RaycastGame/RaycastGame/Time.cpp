#include "stdafx.h"
#include "Time.h"
#include "Engine.h"

float Time::deltaTime = 0;
float Time::timeScale = 1.0f;

sf::Time Time::time;
sf::Clock Time::clock;

void Time::UpdateDeltaTime()
{
	time = clock.restart();
	deltaTime = time.asSeconds();
}

float Time::GetScaledDeltaTime()
{
	return deltaTime * timeScale;
}

float Time::GetDeltaTime()
{
	return deltaTime;
}

void Time::SetTimeScale(float newTimeScale)
{
	timeScale = newTimeScale;
}

float Time::GetTimeScale()
{
	return timeScale;
}