#pragma once

#include <string>

#include "Panel.h"
#include "Sprite.h"
#include "SFML\Graphics.hpp"

namespace UI
{
	class Image : public Panel
	{
	public:
		Image(const std::string& fileName);
		Image(const std::string& fileName, const sf::Vector2f& position, const sf::IntRect& textureCoordinates);
		Image(const std::string& fileName, const float& x, const float& y, const sf::IntRect& textureCoordinates);

		void SetTextureRect(const sf::IntRect& textureText);
		sf::IntRect GetTextureRect();
	};
}