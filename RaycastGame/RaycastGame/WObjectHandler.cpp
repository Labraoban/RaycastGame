#include "stdafx.h"
#include "WObjectHandler.h"

WObjectHandler::WObjectHandler()
{

}

WObjectHandler::~WObjectHandler()
{
	for (int i = 0; i < wObjects.size(); ++i)
		delete wObjects[i];
}

void WObjectHandler::Add(WObject* wObject, const bool& autoUpdate)
{
	wObjects.push_back(wObject);
	if (autoUpdate)
		autoUpdateWObjects.push_back(wObject);
}

void WObjectHandler::Add(const std::string& identifier, WObject* wObject, const bool& autoUpdate)
{
	Add(wObject, autoUpdate);
	identifiableWObjects.insert(std::pair<std::string, WObject*>(identifier, wObject));
}

WObject* WObjectHandler::GetWObject(const std::string& identifier)
{
	return identifiableWObjects[identifier];
}

void WObjectHandler::Update()
{
	for (int i = 0; i < autoUpdateWObjects.size(); ++i)
	{
		autoUpdateWObjects[i]->Update();
	}

}

void WObjectHandler::DrawTopDown()
{

}

std::vector<WObject*> WObjectHandler::GetWObjects()
{
	return wObjects;
}