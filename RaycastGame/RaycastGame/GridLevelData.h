#pragma once

#define MAPS_PATH "../Data/WMaps/"

class GridLevelData
{
public:
	GridLevelData(const std::string& fileName);
	~GridLevelData();

	std::string mapName;
	int tileSize;
	int width;
	int height;
	char** mapData;
};