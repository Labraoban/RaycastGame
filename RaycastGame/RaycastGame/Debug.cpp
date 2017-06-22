#include "stdafx.h"
#include "Debug.h"

#include <iostream>

void Debug::Write(const std::string& message)
{
	std::cout << message;
}

void Debug::WriteLine(const std::string& message)
{
	std::cout << message << std::endl;
}
