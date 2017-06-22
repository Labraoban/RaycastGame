#include "stdafx.h"
#include "LevelNode.h"

LevelNode::LevelNode(const int& x, const int& y, Sprite* sprite, bool hasCollider) : GridNode(x, y)
{
	window = ServiceLocator<Window>::Get();
	this->sprite = sprite;
	sprite->SetGlobalPosition(x, y);

	if (sprite != nullptr)
	{
		height = sprite->GetWidth();
		width = sprite->GetWidth();

		sf::Sprite* sfSprite = sprite->GetSFSprite();

		const sf::Texture* tex = sfSprite->getTexture();
		sf::IntRect spriteRect = sprite->GetRect();
		sf::Image image = tex->copyToImage();

		colorArray = new sf::Color*[width];
		for (int y = 0; y < width; ++y)
		{
			colorArray[y] = new sf::Color[height];
			for (int x = 0; x < height; ++x)
			{
				colorArray[y][x] = image.getPixel(spriteRect.left + y, spriteRect.top + x);
			}
		}

		if (hasCollider)
		{
			collider = new BoxCollider(sf::FloatRect(x, y, width, height));
		}
	}
}

LevelNode::~LevelNode()
{
	if (sprite != nullptr)
		delete sprite;
	if (collider != nullptr)
		delete collider;

	if (colorArray != nullptr)
	{
		for (int i = 0; i < width; ++i)
		{

			if (colorArray[i] != nullptr)
				delete colorArray[i];


		}
		delete colorArray;
	}
}

void LevelNode::Draw()
{
	if (sprite != nullptr)
		window->Draw(sprite);
}

BoxCollider* LevelNode::GetCollider()
{
	return collider;
}

void LevelNode::SetColor(sf::Color color)
{
	sprite->SetColor(color);
}

bool LevelNode::HasCollider()
{
	return collider != nullptr;
}

Sprite* LevelNode::GetSprite()
{
	return sprite;
}

//Faster than creating a sf::Image several times each frame
sf::Color* LevelNode::GetColumnColors(const int& column, int* length)
{
	*length = height;
	return colorArray[column];
}

sf::Vector2i LevelNode::GetGridPosition()
{
	return gridPosition;
}

sf::Vector2f LevelNode::GetPositionOffset()
{
	return offsetPosition;
}

void LevelNode::SetPositionOffset(const float& xOffset, const float& yOffset)
{
	SetPositionOffset(sf::Vector2f(xOffset, yOffset));
}

void LevelNode::SetPositionOffset(const sf::Vector2f& offset)
{
	offsetPosition = offset;
	void UpdatePosition();
}

void LevelNode::UpdatePosition()
{
	sprite->SetGlobalPosition(worldPosition + offsetPosition);
	collider->SetPosition(worldPosition + offsetPosition);
}