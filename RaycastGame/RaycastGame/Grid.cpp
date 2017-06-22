#include "stdafx.h"

#include "Grid.h"

Grid::Grid(const int& width, const int& height)
{
	this->width = width;
	this->height = height;

	gridNodes = new GridNode**[width];
	for (int x = 0; x < width; ++x)
	{
		gridNodes[x] = new GridNode*[height];
	}
}

Grid::~Grid()
{
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
		{
			if (gridNodes[i][j] != nullptr)
				delete gridNodes[i][j];
		}
		delete gridNodes[i];
	}
	delete gridNodes;
}

void Grid::SetGridNode(const int& x, const int& y, GridNode* gridNode)
{
	if (IsInsideGrid(x, y))
		gridNodes[x][y] = gridNode;
}

void Grid::SetGridNode(const sf::Vector2i& position, GridNode* gridNode)
{
	SetGridNode(position.x, position.y, gridNode);
}

GridNode* Grid::GetGridNode(const int& x, const int& y)
{
	if (IsInsideGrid(x, y))
		return gridNodes[x][y];
}

GridNode* Grid::GetGridNode(const sf::Vector2i& position)
{
	return GetGridNode(position.x, position.y);
}

bool Grid::HasGridNode(const int& x, const int& y)
{
	return GetGridNode(x, y) != nullptr;
};
bool Grid::HasGridNode(const sf::Vector2i& position)
{
	return HasGridNode(position.x, position.y);
};

bool Grid::IsInsideGrid(const int& x, const int& y)
{
	return (x >= 0 && x < width && y >= 0 && y < height);
}

bool Grid::IsInsideGrid(const sf::Vector2i& position)
{
	return IsInsideGrid(position.x, position.y);
}

int Grid::GetWidth()
{
	return width;
}

int Grid::GetHeight()
{
	return height;
}

sf::Vector2i Grid::GetSize()
{
	return sf::Vector2i(width, height);
}