#pragma once

#include "State.h"
#include <string>
#include "Sprite.h"

class TestState : public State
{
public:
	TestState(const std::string& sceneName, Input* input);



	void Initialize();
	void Update();
	void Draw();

private:

	Sprite* sprite1;
	Sprite* sprite2;
	Sprite* sprite3;
	
};
