#pragma once

#include <string>
#include "Input.h"

class State
{
protected:
	State(const std::string& sceneName, Input* input) 
	{ 
		Debug::WriteLine("State Created: " + sceneName);
		this->sceneName = sceneName; 
		this->input = input;
	}

public:
	virtual ~State() {};

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;



protected:
	Input* input;

private:
	std::string sceneName;

};
