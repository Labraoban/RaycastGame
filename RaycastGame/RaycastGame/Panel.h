#pragma once

#include "Element.h"

#include "SFML\Graphics.hpp"
#include "Window.h"

namespace UI
{
	class Panel : public Element
	{
	public:
		Panel(const sf::Vector2f& position, const sf::Vector2f& size);
		Panel(const float& left, const float& top, const float& width, const float& height);
		Panel(const float& left, const float& top, const float& width, const float& height, const sf::Color& baseColor);

		virtual ~Panel();

		virtual void Initialize();
		virtual void Draw();

	protected:
		void UpdatePosition();
		void UpdateScale();
		void UpdateSize();
		void UpdateColor();

		sf::RectangleShape* rectangleShape;

	};
}