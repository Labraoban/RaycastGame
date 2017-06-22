#pragma once

#include "State.h"
#include <string>
#include "Sprite.h"
#include "GridLevel.h"
#include "Player.h"
#include "WFrame.h"

#include "BoxCollider.h"
#include "Ray.h"

class WGameState : public State
{
public:
	WGameState(const std::string& sceneName, Input* input);
	~WGameState();

	void Initialize();
	void Update();
	void Draw();

private:
	WObjectHandler* wObjectHandler;
	GridLevel* gridLevel;
	Player* player;
	WFrame* wFrame;
};
