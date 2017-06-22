#pragma once

#include "GridNode.h"
#include "Sprite.h"
#include "Window.h"
#include "BoxCollider.h"


class LevelNode : public GridNode
{
public:
	LevelNode(const int& x, const int& y, Sprite* sprite, bool hasCollider);
	~LevelNode();

	BoxCollider* GetCollider();
	void Draw();

	void SetColor(sf::Color color);
	bool HasCollider();

	Sprite* GetSprite();
	sf::Color* GetColumnColors(const int& column, int* length);


	sf::Vector2i GetGridPosition();
	sf::Vector2f GetPositionOffset();
	
	void SetPositionOffset(const float& xOffset, const float& yOffset);
	void SetPositionOffset(const sf::Vector2f& offset);

private:
	void UpdatePosition();

	Window* window;

	BoxCollider* collider;
	Sprite* sprite;
	sf::Color** colorArray;

	sf::Vector2i gridPosition;
	sf::Vector2f worldPosition;
	sf::Vector2f offsetPosition;

	int height;
	int width;

};

