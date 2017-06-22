#include "stdafx.h"
#include "WGameState.h"

WGameState::WGameState(const std::string& sceneName, Input* input) : State(sceneName, input)
{
	player = new Player();
	gridLevel = new GridLevel(GridLevelData("map_3.txt"));

	player->SetGlobalPosition(100, 100);


	wObjectHandler = new WObjectHandler();
	wObjectHandler->Add("wobj", new WObject("testObject.png"), true);
	wObjectHandler->GetWObject("wobj")->SetGlobalPosition(50, 200);

	float scale = 1.5;
	wFrame = new WFrame(gridLevel, wObjectHandler, player, 1280.0f / scale, 720.0f / scale, 60, 300);
}

WGameState::~WGameState()
{
	if (wFrame != nullptr)
		delete wFrame;

	if (player != nullptr)
		delete player;

	if (gridLevel != nullptr)
		delete gridLevel;

	if (wObjectHandler != nullptr)
		delete wObjectHandler;
}

void WGameState::Initialize()
{
	
}

void WGameState::Update()
{
	wFrame->Update();
	gridLevel->Update();
	player->Update();
}

void WGameState::Draw()
{
	gridLevel->DrawTopDown();
	player->DrawTopDown();
	wFrame->Draw();
}