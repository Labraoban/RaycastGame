#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "vld.h"

#include "Engine.h"
#include <conio.h>
#include <iostream>

class Base
{
protected:
	virtual void Print()
	{
		std::cout << "Base Print" << std::endl;
	}
};

class Derived : public Base
{
public:
	void Print()
	{
		Base::Print();
		std::cout << "Derived Print" << std::endl;
	}
};

int main()
{

	Derived derived;
	derived.Print();

	Engine* engine = new Engine();
	engine->Run();

	delete engine;
	return 0;
}