#pragma once

#include "SFML\Graphics.hpp"
#include <vector>

class GridNode
{
protected:
	GridNode(const int& x, const int& y);

public:
	virtual ~GridNode();

	int GetX();
	int GetY();
	sf::Vector2i GetPosition();

	void SetNeighbours(std::vector<GridNode*>* neighbours);
	std::vector<GridNode*>* GetNeighbours();

	void AddNeighbour(GridNode* neighbour);
	void RemoveNeighbour(GridNode* neighbour);

private:
	int x;
	int y;

	std::vector<GridNode*>* neighbours;
};