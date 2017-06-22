#pragma once

#include <vector>

#include "GridNode.h"

class Grid
{
public:
	Grid(const int& width, const int& height);
	~Grid();

	void SetGridNode(const int& x, const int& y, GridNode* gridNode);
	void SetGridNode(const sf::Vector2i& position, GridNode* gridNode);

	GridNode* GetGridNode(const int& x, const int& y);
	GridNode* GetGridNode(const sf::Vector2i& position);

	bool HasGridNode(const int& x, const int& y);
	bool HasGridNode(const sf::Vector2i& position);

	bool IsInsideGrid(const int& x, const int& y);
	bool IsInsideGrid(const sf::Vector2i& position);

	int GetWidth();
	int GetHeight();
	sf::Vector2i GetSize();
	
private:
	int width;
	int height;

	GridNode*** gridNodes;
};