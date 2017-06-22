#include "stdafx.h"
#include "TestState.h"

TestState::TestState(const std::string& sceneName, Input* input) : State(sceneName, input)
{
	sprite1 = new Sprite("testTexture.png", sf::IntRect(0, 16, 16, 16));
	sprite1->SetGlobalPosition(100, 100);

	sprite2 = new Sprite("testTexture.png", sf::IntRect(16, 16, 16, 16));
	sprite2->SetGlobalPosition(50, 50);
	sprite2->SetParent(sprite1);

	sprite3= new Sprite("testTexture.png", sf::IntRect(16, 32, 16, 16));
	sprite3->SetParent(sprite2);
}

void TestState::Initialize()
{
	
}

void TestState::Update()
{
	if (input->GetKey(sf::Keyboard::A))
		sprite1->Move(sf::Vector2f(-100, 0) * Time::GetScaledDeltaTime());

	if (input->GetKey(sf::Keyboard::D))
		sprite1->Move(sf::Vector2f(100, 0) * Time::GetScaledDeltaTime());

	if (input->GetKey(sf::Keyboard::W))
		sprite1->Move(sf::Vector2f(0, -100) * Time::GetScaledDeltaTime());

	if (input->GetKey(sf::Keyboard::S))
		sprite1->Move(sf::Vector2f(0, 100) * Time::GetScaledDeltaTime());



	if (input->GetKey(sf::Keyboard::Left))
		sprite2->Move(sf::Vector2f(-100, 0) * Time::GetScaledDeltaTime());

	if (input->GetKey(sf::Keyboard::Right))
		sprite2->Move(sf::Vector2f(100, 0) * Time::GetScaledDeltaTime());

	if (input->GetKey(sf::Keyboard::Up))
		sprite2->Move(sf::Vector2f(0, -100) * Time::GetScaledDeltaTime());

	if (input->GetKey(sf::Keyboard::Down))
		sprite2->Move(sf::Vector2f(0, 100) * Time::GetScaledDeltaTime());

	if (input->GetKey(sf::Keyboard::Num1))
		sprite3->SetLocalPosition(0, 100);
	if (input->GetKey(sf::Keyboard::Num2))
		sprite3->SetLocalPosition(0, 200);
	if (input->GetKey(sf::Keyboard::Num3))
		sprite3->SetLocalPosition(0, 300);

	sprite1->Update();
	sprite2->Update();
	sprite3->Update();

	//Debug::WriteLine("1. X " + std::to_string(sprite1->GetGlobalPosition().x) +
	//				 ", Y " + std::to_string(sprite1->GetGlobalPosition().y) +
	//				 "\n2. " +
	//				 "X " + std::to_string(sprite2->GetGlobalPosition().x) +
	//				 ", Y " + std::to_string(sprite2->GetGlobalPosition().y) + "\n");
}

void TestState::Draw()
{
	ServiceLocator<Window>::Get()->Draw(sprite1);
	ServiceLocator<Window>::Get()->Draw(sprite2);
	ServiceLocator<Window>::Get()->Draw(sprite3);
}