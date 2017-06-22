#pragma once

#include "Transform.h"
#include "Sprite.h"
#include "Input.h"
#include "Window.h"

class Player : public Transform
{
public:
	Player();
	~Player();

	void Update();
	void DrawTopDown();

	float GetHeadHeightOffset();
private:
	void UpdateHeadbob();
	

private:
	Input* input;
	Window* window;

	Sprite* topDownSprite;
	float moveSpeed;
	float turnSpeed;
	float sensitivity;

	bool isMoving;

	float headHeightOffset;

	float fieldOfView;
};

