#pragma once

#include "Element.h"
#include "Panel.h"
#include "Image.h"
#include "Text.h"
#include "Selectable.h"

#include <string>
#include <map>
#include <vector>

namespace UI
{
	class UserInterface
	{
	public:
		UserInterface(const int& width, const int& height);
		~UserInterface();

		void Update();
		void Draw();

		Element* GetElement(const std::string identifier);
		void AddElement(Element* element, const bool& autoUpdate);
		void AddElement(const std::string& identifier, Element* element, const bool& active);

	private:
		std::vector<Element*> elements;
		std::vector<Element*> autoUpdateElements;
		std::map<std::string, Element*> identifiableElements;

		int width;
		int height;
	};
}