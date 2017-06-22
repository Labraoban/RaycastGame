#pragma once

#include "SFML\Graphics.hpp"
#include "Element.h"
#include "Window.h"
#include "FontHandler.h"

#include <string>

namespace UI
{
	class Text : public Element
	{
	public:
		Text(const std::string& fontName, const std::string& textString);
		~Text();

		void Initialize();
		void Draw();

		std::string GetTextString();
		void SetTextString(const std::string& textString);

	private:
		void UpdatePosition();
		void UpdateScale();
		void UpdateSize();
		void UpdateColor();
		
		sf::Text* text;
		
		std::string textString;
	};
}