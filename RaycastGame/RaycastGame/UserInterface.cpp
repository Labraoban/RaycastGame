#include "stdafx.h"
#include "UserInterface.h"
#include <algorithm>

using namespace UI;

UserInterface::UserInterface(const int& width, const int& height)
{
	this->width = width;
	this->height = height;
}

UserInterface::~UserInterface()
{

}

void UserInterface::Update()
{

}

void UserInterface::Draw()
{
	for (int i = 0; i < elements.size(); ++i)
	{
		elements[i]->Draw();
	}
}

Element* UserInterface::GetElement(const std::string identifier)
{
	return identifiableElements[identifier];
}

void UserInterface::AddElement(Element* element, const bool& autoUpdate)
{
	element->Initialize();
	elements.push_back(element);

	if (autoUpdate)
		autoUpdateElements.push_back(element);

	auto compare = [](const Element* e1, const Element* e2) -> bool
	{
		return e1->GetDepthLayer() < e2->GetDepthLayer();
	};

	std::sort(elements.begin(), elements.end(), compare);
}

void UserInterface::AddElement(const std::string& identifier, Element* element, const bool& active)
{
	AddElement(element, active);
	identifiableElements.insert(std::pair<std::string, Element*>(identifier, element));
}
