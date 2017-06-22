#include "stdafx.h"
#include "GridLevel.h"
#include "LevelNode.h"
#include <math.h>
#include <limits>

GridLevel::GridLevel(GridLevelData gridLevelData)
{
	width = gridLevelData.width;
	height = gridLevelData.height;
	nodeSize = gridLevelData.tileSize;

	grid = new Grid(width, height);

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			Sprite* sprite = nullptr;
			if (gridLevelData.mapData[x][y] == '#')
			{
				sprite = new Sprite(gridLevelData.mapName, sf::IntRect(nodeSize * 5, nodeSize * 6, nodeSize, nodeSize));
				grid->SetGridNode(x, y, new LevelNode(x * nodeSize, y * nodeSize, sprite, true));
			}
			else
			{
				sprite = new Sprite(gridLevelData.mapName, sf::IntRect(0, 0, nodeSize, nodeSize));
				grid->SetGridNode(x, y, new LevelNode(x * nodeSize, y * nodeSize, sprite, false));
			}
		}
	}
}

GridLevel::~GridLevel()
{
	if (grid != nullptr)
		delete grid;
}

void GridLevel::Update()
{

}

void GridLevel::DrawTopDown()
{
	std::vector<sf::Vector2i> positions;

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			if (grid->HasGridNode(x, y))
			{
				LevelNode* levelNode = nullptr;
				levelNode = static_cast<LevelNode*>(grid->GetGridNode(x, y));

				if (!levelNode)
					continue;
				levelNode->Draw();
			}
		}
	}
}



LevelNode* GridLevel::Raycast(Ray ray, RaycastHit& hit)
{
	hit.distance = std::numeric_limits<float>::max();
	LevelNode* hitNode = nullptr;

	std::vector<sf::Vector2i> positions;
	
	//OPTIMIZATION TODO:
	//	Implement GetPossibleIntersectionPositions
	//	and remove GetAllGridPositions
	//
	//	GetPossibleIntersectionPositions(ray, &positions);

	GetAllGridPositions(&positions);

	for (int i = 0; i < positions.size(); ++i)
	{
		int x = positions[i].x;
		int y = positions[i].y;

		if (grid->HasGridNode(x, y))
		{
			LevelNode* levelNode = nullptr;
			levelNode = static_cast<LevelNode*>(grid->GetGridNode(x, y));

			if (levelNode == nullptr || !levelNode->HasCollider())
				continue;

			Collider* collider = levelNode->GetCollider();
			RaycastHit colliderHit;

			if (collider->Raycast(ray, colliderHit))
			{
				if (colliderHit.distance < hit.distance)
				{
					hit.intersection = colliderHit.intersection;
					hit.distance = colliderHit.distance;
					hitNode = levelNode;
				}
			}
		}
	}
	return hitNode;
}

void GridLevel::GetAllGridPositions(std::vector<sf::Vector2i>* positions)
{
	for (int i = 0; i < grid->GetWidth(); ++i)
	{
		for (int y = 0; y < grid->GetHeight(); ++y)
		{
			positions->push_back(sf::Vector2i(i, y));
		}
	}
};



int GridLevel::GetNodeSize()
{
	return nodeSize;
}
