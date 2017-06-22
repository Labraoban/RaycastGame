#pragma once

#include "Transform.h"
#include "Sprite.h"
#include "Window.h"

class WObject : public Transform
{
public:
	WObject(const std::string& fileName);
	WObject(const std::string& fileName, const sf::IntRect& rect);
	~WObject();

	virtual void Update() {};
	
	void Draw(const sf::Vector2f& position, const float& scale);
	void DrawTopDown();
	

private:
	Window* window;
	Sprite* sprite;

	float scale;

};