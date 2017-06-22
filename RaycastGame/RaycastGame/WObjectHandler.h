#pragma once

#include "WObject.h"
#include <vector>
#include <map>

class WObjectHandler
{
public:
	WObjectHandler();
	~WObjectHandler();

	void Add(WObject* wObject, const bool& autoUpdate);
	void Add(const std::string& identifier, WObject* wObject, const bool& autoUpdate);

	WObject* GetWObject(const std::string& identifier);

	void Update();

	void DrawTopDown();
	std::vector<WObject*> GetWObjects();

private:
	std::vector<WObject*> wObjects;
	std::vector<WObject*> autoUpdateWObjects;
	std::map<std::string, WObject*> identifiableWObjects;

};