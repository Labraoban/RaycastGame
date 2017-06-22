#include "stdafx.h"

#include "GridNode.h"

GridNode::GridNode(const int& x, const int& y)
{
	this->x = x;
	this->y = y;
}

GridNode::~GridNode()
{
	if (neighbours != nullptr)
		delete neighbours;
}

int GridNode::GetX()
{
	return x;
}
int GridNode::GetY()
{
	return y;
}

sf::Vector2i GridNode::GetPosition()
{
	return sf::Vector2i(x, y);
}

void GridNode::SetNeighbours(std::vector<GridNode*>* neighbours)
{
	if (this->neighbours != nullptr)
		delete this->neighbours;

	this->neighbours = neighbours;
}

std::vector<GridNode*>* GridNode::GetNeighbours()
{
	return neighbours;
}

void GridNode::AddNeighbour(GridNode* neighbour)
{
	neighbours->push_back(neighbour);
}

void GridNode::RemoveNeighbour(GridNode* neighbour)
{
	for (int i = 0; i < neighbours->size(); ++i)
	{
		if (neighbours->at(i) == neighbour)
		{
			neighbours->erase(neighbours->begin() + i);
			break;
		}
	}
}