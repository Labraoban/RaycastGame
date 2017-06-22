#include "stdafx.h"

#include "Selectable.h"

using namespace UI;

Selectable::Selectable(Element* element, const sf::Color& selectedColor)
{
	this->element		= element;
	this->position		= element->GetPosition();
	this->scale			= element->GetScale();
	this->size			= element->GetSize();
	this->baseColor		= element->GetBaseColor();
	this->currentColor	= element->GetCurrentColor();

	this->isSelected = false;
	this->isSelectable = true;
	SetSelectedColor(selectedColor);
}

Selectable::~Selectable()
{
	if (element != nullptr)
		delete element;
}

void Selectable::Initialize()
{
	UpdateColor();
	UpdatePosition();
	UpdateScale();
	UpdateSize();
}

void Selectable::Update()
{
	if (element != nullptr)
		element->Update();
}

void Selectable::Draw()
{
	if (element != nullptr)
		element->Draw();
}

void Selectable::Select()
{
	if (isSelectable) 
	{
		isSelected = true;
		SetCurrentColor(selectedColor);
	}
}

void Selectable::Deselect()
{
	isSelected = false;
	SetCurrentColor(baseColor);
}

void Selectable::SetSelectable(const bool& isSelectable)
{
	this->isSelectable = isSelectable;
}

bool Selectable::IsSelectable()
{
	return isSelectable;
}

bool Selectable::IsSelected()
{
	return isSelected;
}

void Selectable::SetSelectedColor(const sf::Color& selectedColor)
{
	this->selectedColor = selectedColor;
}

sf::Color Selectable::GetSelectedColor()
{
	return selectedColor;
}

void Selectable::UpdatePosition()
{
	element->SetPosition(GetPosition());
}

void Selectable::UpdateScale()
{
	element->SetScale(GetScale());
}

void Selectable::UpdateSize()
{
	element->SetSize(GetSize());
}

void Selectable::UpdateColor()
{
	element->SetCurrentColor(GetCurrentColor());
}