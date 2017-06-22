#pragma once

#include "SFML\Graphics.hpp"
#include "Window.h"
#include "GridLevel.h"
#include "Input.h"
#include "WObjectHandler.h"

class WFrame
{
public:
	WFrame(GridLevel* gridLevel, WObjectHandler * wObjectHandler, Player* player, const int& width, const int& height, const float& fieldOfView, const float& viewDistance);
	~WFrame();

	void Update();
	void Draw();

private:

	void CastColumn(Ray ray, const int& column, const float& angle);
	void DrawScreenImage();

	void TextureColumn(const int& column, const RaycastHit& raycastHt, LevelNode* levelNode, const float& angle);
	void SetColumnColor(const sf::Color& color, const int& column);

	sf::Vector2i GetDrawBounds(const int& column, const float& distance, const float& angle);
	sf::Color GetShadedColor(sf::Color color, const int& distance);
	sf::Color* GetSpriteColumn(LevelNode* levelNode, const sf::Vector2f& intersectionPoint, int* outLength);

	void DrawObjects();
	void DrawObject(WObject* wObject);

private:
	Window* window;
	Input* input;

	WObjectHandler* wObjectHandler;
	GridLevel* gridLevel;
	Player* player;

	sf::Vector2f position;

	sf::Color fogColor;
	sf::Color backgroundColor;

	int width;
	int height;

	float verticalScale;
	float fieldOfView;
	float viewDistance;

	sf::Image screenImage;
	sf::Sprite screenSprite;
};

