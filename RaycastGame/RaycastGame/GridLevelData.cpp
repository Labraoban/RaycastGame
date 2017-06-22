#include "stdafx.h"

#include "GridLevelData.h"
#include <fstream>

GridLevelData::GridLevelData(const std::string& fileName)
{
	std::ifstream file(MAPS_PATH + fileName);

	std::string line;

	if (file.is_open())
	{
		//mapName
		std::getline(file, line);
		mapName = line;

		//tileSize
		std::getline(file, line);
		tileSize = std::stoi(line);

		//width
		std::getline(file, line);
		width = std::stoi(line);

		//height
		std::getline(file, line);
		height = std::stoi(line);

		mapData = new char*[width];
		for(int x = 0; x < width; ++x)
			mapData[x] = new char[height];

		int yIndex = 0;
		while (std::getline(file, line) && yIndex < height)
		{
			for (int x = 0; x < width; ++x)
			{
				if (x < line.size())
					mapData[x][yIndex] = line[x];
				else
					mapData[x][yIndex] = ' ';
			}
			yIndex++;
		}
		file.close();
	}
}

GridLevelData::~GridLevelData()
{
	if (mapData != nullptr)
	{
		for (int i = 0; i < width; ++i)
		{
			if (mapData[i] != nullptr)
				delete mapData[i];
		}
		delete mapData;
	}
}
