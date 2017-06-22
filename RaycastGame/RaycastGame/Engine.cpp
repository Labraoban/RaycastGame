#include "stdafx.h"
#include "Engine.h"

#include "TestState.h"
#include "WGameState.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define WINDOW_FPS 60


bool Engine::running = true;

Engine::Engine()
{
	running = true;

	window			= new Window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FPS);
	stateHandler	= new StateHandler();
	input			= new Input(window);
	textureHandler	= new TextureHandler("../Data/Textures/");
	fontHandler		= new FontHandler("../Data/Fonts/");

	window->SetClearColor(sf::Color(20, 20, 20));
}

Engine::~Engine()
{
	if (window != nullptr)
		delete window;
	if (stateHandler != nullptr)
		delete stateHandler;
	if (input != nullptr)
		delete input;
	if (textureHandler != nullptr)
		delete textureHandler;
	if (fontHandler != nullptr)
		delete fontHandler;
}

void Engine::Run()
{
	SetServices();
	AttachStates();

	while (running)
	{
		PreUpdate();
		Update();
		Draw();
	}
	CleanUp();
}

void Engine::SetServices()
{
	ServiceLocator<Window>::Set(window);
	ServiceLocator<StateHandler>::Set(stateHandler);
	ServiceLocator<TextureHandler>::Set(textureHandler);
	ServiceLocator<Input>::Set(input);
	ServiceLocator<FontHandler>::Set(fontHandler);
}

void Engine::AttachStates()
{
	stateHandler->AttachState("WGameState", new WGameState("WGameState", input));
	stateHandler->ActivateState("WGameState");
}

void Engine::PreUpdate()
{
	Time::UpdateDeltaTime();
	input->Update();
}

void Engine::Update()
{
	stateHandler->Update();
}

void Engine::Draw()
{
	window->Clear();

	stateHandler->Draw();

	window->Display();
}

void Engine::CleanUp()
{

}

void Engine::Shutdown()
{
	running = false;
}
