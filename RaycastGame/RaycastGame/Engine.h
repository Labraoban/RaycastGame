#pragma once

#include "Window.h"
#include "StateHandler.h"
#include "Input.h"
#include "TextureHandler.h"
#include "FontHandler.h"

#include "UserInterface.h"

class Engine
{
public:
	Engine();
	~Engine();

	void Run();

	static void Shutdown();

private:

	void SetServices();
	void AttachStates();

	void PreUpdate();
	void Update();
	void Draw();

	void CleanUp();
	
private:
	static bool running;

	Window* window;
	StateHandler* stateHandler;
	Input* input;
	TextureHandler* textureHandler;
	FontHandler* fontHandler;

	//UI::UserInterface* userInterface;
};

