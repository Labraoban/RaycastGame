#include "stdafx.h"
#include "WObject.h"

WObject::WObject(const std::string& fileName)
{
	window = ServiceLocator<Window>::Get();

	sprite = new Sprite(fileName);
	this->scale = 3;
	sprite->GetSFSprite()->setOrigin(sprite->GetWidth() / 2, sprite->GetHeight() / 2);
}

WObject::WObject(const std::string& fileName, const sf::IntRect& rect) : WObject(fileName)
{
	sprite->SetRect(rect);
	sprite->SetLocalPosition(-sprite->GetRect().width / 2, -sprite->GetRect().height / 2);
}

WObject::~WObject()
{
	if (sprite != nullptr)
		delete sprite;
}

void WObject::Draw(const sf::Vector2f& position, const float& scale)
{
	sprite->SetGlobalPosition(position);
	sprite->GetSFSprite()->setScale(sf::Vector2f(this->scale * scale, this->scale * scale));
	window->Draw(sprite);
}

void WObject::DrawTopDown()
{
	window->Draw(sprite);
}