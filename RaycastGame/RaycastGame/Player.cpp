#include "stdafx.h"
#include "Player.h"

#define HEADBOB_DIR_UP true
#define HEADBOB_DIR_DOWN false

Player::Player()
{
	input = ServiceLocator<Input>::Get();
	window = ServiceLocator<Window>::Get();

	topDownSprite = new Sprite("playerTopDown.png");
	topDownSprite->SetParent(this);
	moveSpeed = 64;
	turnSpeed = 130;
	sensitivity = 0.1f;

	topDownSprite->SetLocalPosition(sf::Vector2f(-8, -8));


	headHeightOffset = 5;
}

Player::~Player()
{
	if (topDownSprite != nullptr)
		delete topDownSprite;
}

void Player::Update()
{
	sf::Vector2f movement(0, 0);

	sf::Vector2f right = Vector2Utility::Rotate(GetForward(), 90);
	sf::Vector2f left = Vector2Utility::Rotate(GetForward(), -90);

	//if (input->GetKey(sf::Keyboard::Down))
	//	headHeightOffset -= turnSpeed * Time::GetDeltaTime();

	//if (input->GetKey(sf::Keyboard::Up))
	//	headHeightOffset += turnSpeed * Time::GetDeltaTime();

	if (input->GetKey(sf::Keyboard::A))
		movement += left;

	if (input->GetKey(sf::Keyboard::D))
		movement += right;

	if (input->GetKey(sf::Keyboard::W))
		movement += GetForward();

	if (input->GetKey(sf::Keyboard::S))
		movement -= GetForward();

	if (input->GetKey(sf::Keyboard::Space))
		Rotate(sensitivity * input->GetMouseDelta().x);

	if (input->GetKey(sf::Keyboard::Right))
		Rotate(turnSpeed * Time::GetDeltaTime());
	if (input->GetKey(sf::Keyboard::Left))
		Rotate(-turnSpeed * Time::GetDeltaTime());

	if (movement.x != 0 && movement.y != 0)
		isMoving = true;
	else
		isMoving = false;

	if (input->GetKey(sf::Keyboard::LShift))
		Move(movement * moveSpeed * 2.0f * Time::GetDeltaTime());
	else
		Move(movement * moveSpeed * Time::GetDeltaTime());

	//Quick an ugly crash prevention, fix as soon as possible
	int x = GetGlobalPosition().x;
	int y = GetGlobalPosition().y;
	if (x <= 17)
		SetGlobalPosition(sf::Vector2f(17, y));

	x = GetGlobalPosition().x;
	y = GetGlobalPosition().y;
	if (y <= 17)
		SetGlobalPosition(sf::Vector2f(x, 17));
}

void Player::DrawTopDown()
{
	window->Draw(topDownSprite);
};

float Player::GetHeadHeightOffset()
{
	return headHeightOffset;
}

void Player::UpdateHeadbob()
{
}
