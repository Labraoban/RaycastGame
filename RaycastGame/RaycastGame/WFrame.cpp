#include "stdafx.h"
#include "WFrame.h"

#define DEFAULT_RES 320.0f

/* WFrame constructor
 *
 * GridLevel*		- Pointer to the level that the WFrame will draw
 * width			- width of the frame
 * height			- height of the frame
 * fieldOfView		- range of the raycast cone
 * viewDistance		-
 */
WFrame::WFrame(GridLevel* gridLevel, WObjectHandler * wObjectHandler, Player* player, const int& width, const int& height, const float& fieldOfView, const float& viewDistance)
{
	window = ServiceLocator<Window>::Get();
	input = ServiceLocator<Input>::Get();

	this->wObjectHandler = wObjectHandler;

	this->gridLevel = gridLevel;
	this->player = player;
	this->width = width;
	this->height = height;
	this->fieldOfView = fieldOfView;
	this->viewDistance = viewDistance;

	backgroundColor = sf::Color::Black;

	verticalScale = 1.0f - (DEFAULT_RES / (float)width);
	screenImage.create(width, height, sf::Color::Black);

	position = sf::Vector2f(380, 100);
}

WFrame::~WFrame()
{

}

/* Updates the WFrame
 * Currently does nothing
 */
void WFrame::Update()
{

}

/* Starts drawing the Wframe by casting rays
 */
void WFrame::Draw()
{
	float angleOffset = fieldOfView / width;
	sf::Vector2f direction = player->GetForward();

	Ray ray = Ray(player->GetGlobalPosition(), direction, viewDistance);
	direction = Vector2Utility::Rotate(direction, -(fieldOfView / 2.0f));

	for (int i = 0; i < width; ++i)
	{
		float angle = Vector2Utility::Angle(player->GetForward(), ray.GetDirection());

		CastColumn(ray, i, angle);

		direction = Vector2Utility::Rotate(direction, angleOffset);
		ray.SetDirection(direction);

	}
	Ray::DrawRay(player->GetGlobalPosition(),
		player->GetGlobalPosition() + player->GetForward() * 30.0f,
		sf::Color::Red, window->GetRenderWindow());

	DrawScreenImage();

	DrawObjects();
}

/* Casts a ray and colors a column of the frame
 *
 * Ray			- Ray that will be cast
 * column		- index of screen column
 * angle		-
 */
void WFrame::CastColumn(Ray ray, const int& column, const float& angle)
{
	sf::Color* spriteColumn = nullptr;

	RaycastHit hit;
	LevelNode* levelNode;

	Ray::DrawRay(ray, sf::Color(100, 100, 255, 30), window->GetRenderWindow());
	if (levelNode = gridLevel->Raycast(ray, hit))
	{
		Ray r2 = Ray(ray.GetPosition(), ray.GetDirection(), hit.distance);
		Ray::DrawRay(r2, sf::Color(255, 100, 100, 30), window->GetRenderWindow());
		TextureColumn(column, hit, levelNode, angle);
	}
	else
	{
		SetColumnColor(backgroundColor, column);
	}
}

/* Finally draws the frame
 */
void WFrame::DrawScreenImage()
{
	sf::Texture screenTexture;
	screenTexture.loadFromImage(screenImage);
	sf::Sprite screenSprite = sf::Sprite(screenTexture);
	//screenSprite.setPosition(sf::Vector2f(-215, -75));
	screenSprite.setPosition(position);

	window->Draw(screenSprite);
}

/* Textures the column by using the sprite owned by the
 * levelNode passed as argument
 *
 * levelNode			- A LevelNode that a ray has just collided with
 * intersectionPoint	- The intersection point between the ray and LevelNode
 * column				- the column of the frame that will be textured
 * distance				- distance from ray start to intersectionPoin
 *
 *
 */
void WFrame::TextureColumn(const int& column, const RaycastHit& raycastHt, LevelNode* levelNode, const float& angle)
{

	sf::Vector2i drawBounds = GetDrawBounds(column, raycastHt.distance, angle);
	int topHeight = drawBounds.x;
	int botHeight = drawBounds.y;

	int drawnHeight = botHeight - topHeight;

	int spriteColumnLength;
	sf::Color* spriteColumn = GetSpriteColumn(levelNode, raycastHt.intersection, &spriteColumnLength);

	for (int i = 0; i < height; ++i)
	{
		if (i > topHeight && i < botHeight)
		{

			float heightFraction = (float)(i - topHeight) / (float)drawnHeight;

			if (heightFraction > 1.0f)
				heightFraction = 1.0f;
			if (heightFraction < 0.0f)
				heightFraction = 0.0f;

			int index = floor(heightFraction * (spriteColumnLength - 1));
			sf::Color texColor = spriteColumn[index];
			sf::Color shadedColor = GetShadedColor(texColor, raycastHt.distance);

			screenImage.setPixel(column, i, shadedColor);

		}
		else
			screenImage.setPixel(column, i, backgroundColor);
	}
};

void WFrame::SetColumnColor(const sf::Color& color, const int& column)
{
	for (int i = 0; i < height; ++i)
	{
		screenImage.setPixel(column, i, sf::Color::Black);
	}
};



/*
 * sf::Vector2.x - Top Bounds
 * sf::Vector2.y - Bot Bounds
 */
sf::Vector2i WFrame::GetDrawBounds(const int& column, const float& distance, const float& angle)
{
	float halfHeight = height / 2;

	float z = distance * cos(angle);
	float wallHeight = halfHeight * (halfHeight / z) * 0.5f;

	sf::Vector2i drawBounds;
	drawBounds.x = halfHeight - wallHeight / 2 + player->GetHeadHeightOffset();
	drawBounds.y = halfHeight + wallHeight / 2 + player->GetHeadHeightOffset();

	float size = drawBounds.y - drawBounds.x;
	float scale = (1.0f - (verticalScale / 2.0f));
	drawBounds.x += size * (verticalScale / 2.0f);
	drawBounds.y -= size * (verticalScale / 2.0f);

	return drawBounds;
}

sf::Color WFrame::GetShadedColor(sf::Color color, const int& distance)
{
	sf::Color shadedColor;
	float scale = 1.0f - (distance / viewDistance);

	shadedColor.r = color.r * scale;
	shadedColor.g = color.g * scale;
	shadedColor.b = color.b * scale;

	return shadedColor;
}

sf::Color* WFrame::GetSpriteColumn(LevelNode* levelNode, const sf::Vector2f& intersectionPoint, int* outLength)
{
	sf::FloatRect rect = levelNode->GetCollider()->GetRect();

	float offset = 0.0f;
	if (floor(intersectionPoint.x) == rect.left || floor(intersectionPoint.x) == rect.left + rect.width)
	{
		offset = (intersectionPoint.y - rect.top);
	}
	else
	{
		offset = (intersectionPoint.x - rect.left);
	}

	int flooredOffset = ((float)offset >= gridLevel->GetNodeSize())
		? (float)(gridLevel->GetNodeSize() - 1) : floor(offset);

	return levelNode->GetColumnColors(flooredOffset, outLength);
}

void WFrame::DrawObjects()
{
	std::vector<WObject*> wObjects = wObjectHandler->GetWObjects();

	for (int i = 0; i < wObjects.size(); ++i)
	{
		DrawObject(wObjects[i]);
	}
}

void WFrame::DrawObject(WObject* wObject)
{
	sf::Vector2f minDir = Vector2Utility::Rotate(player->GetForward(), -(fieldOfView / 2));
	sf::Vector2f dirToObject = wObject->GetGlobalPosition() - player->GetGlobalPosition();

	float angle = fmod((360.0f + Vector2Utility::Rad2Deg(Vector2Utility::Angle(minDir, dirToObject))), 360);

	double angleFraction = width / fieldOfView;

	//Debug::WriteLine(std::to_string(angle) + " : " + std::to_string(angleFraction * angle));
	sf::Vector2f position = sf::Vector2f(angleFraction * angle, height / 2);
	position += this->position;

	//Ray ray = Ray(player->GetGlobalPosition(), minDir, viewDistance);
	//Ray::DrawRay(ray, sf::Color::Red, window->GetRenderWindow());

	//ray = Ray(player->GetGlobalPosition(), dirToObject, viewDistance);
	//Ray::DrawRay(ray, sf::Color::Red, window->GetRenderWindow());

	float distance = Vector2Utility::Distance(player->GetGlobalPosition(), wObject->GetGlobalPosition());
	float scale = (1.0f - distance / (viewDistance / 2));
	//Debug::WriteLine(std::to_string(distance / viewDistance));

	wObject->Draw(position, Math::Clampf(scale, 0.0f, 1.0f));
}