#pragma once

#include <map>
#include "State.h"

class StateHandler
{
public:
	StateHandler();
	~StateHandler();

	void Update();
	void Draw();

	void AttachState(const std::string& stateName, State* state);

	void ActivateState(const std::string& stateName);
	void DeavtivateState(const std::string& stateName);

	bool StateIsAttached(const std::string& stateName);

private:
	std::map<std::string, State*>* states;
	std::map<std::string, State*>* stateStack;

};


