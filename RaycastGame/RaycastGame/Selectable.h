#pragma once

#include "Element.h"

namespace UI
{
	class Selectable : public Element
	{
	public:
		Selectable(Element* element, const sf::Color& selectedColor);
		~Selectable();

		void Initialize();
		void Update();
		void Draw();

		void Select();
		void Deselect();

		void SetSelectable(const bool& isSelectable);
		bool IsSelectable();
		bool IsSelected();

		void SetSelectedColor(const sf::Color& selectedColor);
		sf::Color GetSelectedColor();

	private:
		void UpdatePosition();
		void UpdateScale();
		void UpdateSize();
		void UpdateColor();

		Element* element;
		bool isSelectable;

		bool isSelected;

		sf::Color selectedColor;
	};
}