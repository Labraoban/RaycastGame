#pragma once

#include "Grid.h"
#include "GridLevelData.h"
#include "Player.h"
#include "Ray.h"
#include "LevelNode.h"

class GridLevel
{
public:
	GridLevel(GridLevelData gridLevelData);
	~GridLevel();

	void Update();

	void DrawTopDown();

	LevelNode* Raycast(Ray ray, RaycastHit& hit);

	int GetNodeSize();

private:
	void GetAllGridPositions(std::vector<sf::Vector2i>* positions);

	Grid* grid;

	int width;
	int height;
	int nodeSize;
};
