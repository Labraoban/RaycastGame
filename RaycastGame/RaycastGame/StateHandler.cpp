#include "stdafx.h"
#include "StateHandler.h"

StateHandler::StateHandler()
{
	states = new std::map<std::string, State*>;
	stateStack = new std::map<std::string, State*>;
}

StateHandler::~StateHandler()
{
	auto it = states->begin();
	while (it != states->end())
	{
		delete it->second;
		it++;
	}
	delete states;
	delete stateStack;
}

void StateHandler::Update()
{
	if (!stateStack->empty())
	{
		stateStack->begin()->second->Update();
	}
}

void StateHandler::Draw()
{
	if (!stateStack->empty())
	{
		stateStack->begin()->second->Draw();
	}
}

void StateHandler::AttachState(const std::string& stateName, State* state)
{
	states->insert(std::pair<std::string, State*>(stateName, state));
}

void StateHandler::ActivateState(const std::string& stateName)
{
	if (StateIsAttached(stateName))
		stateStack->insert(std::pair<std::string, State*>(stateName, states->at(stateName)));
}

void StateHandler::DeavtivateState(const std::string& stateName)
{

}

bool StateHandler::StateIsAttached(const std::string& stateName)
{
	auto it = states->begin();
	while (it != states->end())
	{
		if (it->first == stateName)
			return true;
		it++;
	}
	return false;
}