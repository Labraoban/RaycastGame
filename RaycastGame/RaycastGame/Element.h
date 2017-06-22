#pragma once

#include "SFML\System\Vector2.hpp"
#include "Window.h"

namespace UI
{
	class Element
	{
	public:
		Element();
		virtual ~Element() {};

		virtual void Initialize() = 0;
		virtual void Update() {};
		virtual void Draw() {};

		virtual sf::FloatRect GetBounds();

		int GetDepthLayer() const;
		void SetDepthLayer(const int& depthLayer);

		sf::Vector2f GetPosition();
		void SetPosition(const sf::Vector2f& position);
		void SetPosition(const float& x, const float& y);

		float GetScale();
		void SetScale(const float& scale);

		void SetSize(const sf::Vector2f& size);
		void SetSize(const float& width, const float& height);
		sf::Vector2f GetSize();

		void SetCurrentColor(const sf::Color& currentColor);
		sf::Color GetCurrentColor();

		void SetBaseColor(const sf::Color& baseColor);
		sf::Color GetBaseColor();

	protected:
		virtual void UpdatePosition() = 0;
		virtual void UpdateScale() = 0;
		virtual void UpdateSize() = 0;
		virtual void UpdateColor() = 0;
		

		sf::Vector2f position;
		sf::Vector2f size;
		sf::Color baseColor;
		sf::Color currentColor;

		float scale;

		int depthLayer;

		Window* window;
	};




}