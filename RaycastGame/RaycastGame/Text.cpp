#include "stdafx.h"
#include "Text.h"

using namespace UI;

Text::Text(const std::string& fontName, const std::string& textString)
{
	this->textString = textString;

	sf::Font* font = ServiceLocator<FontHandler>::Get()->LoadFont(fontName);
	text = new sf::Text(textString, *font);
}

Text::~Text()
{

}

void Text::Initialize()
{
	UpdatePosition();
	UpdateScale();
	UpdateSize();
	UpdateColor();
}

void Text::Draw()
{
	window->Draw(*text);
}

std::string Text::GetTextString()
{
	return textString;
}

void Text::SetTextString(const std::string& textString)
{
	this->textString = textString;
}

void Text::UpdatePosition()
{
	text->setPosition(GetPosition());
}

void Text::UpdateScale()
{
	float scale = GetScale();
	text->setScale(scale, scale);
}

void Text::UpdateSize()
{
	text->setCharacterSize(30.0f);
}

void Text::UpdateColor()
{
	text->setFillColor(GetCurrentColor());
}