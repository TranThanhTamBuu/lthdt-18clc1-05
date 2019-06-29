#pragma once
#include "Console.h"
#include <string>





class Vehicle
{
protected:
	int mX, mY;
public:
	Vehicle(int x, int y);
	~Vehicle();
	void move(int step);
};

