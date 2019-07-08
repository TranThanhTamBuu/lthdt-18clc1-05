#pragma once
#include "Console.h"
#include <string>


class Vehicle
{
protected:
	int mX, mY;

public:
	Vehicle();
	Vehicle(int x, int y);
	virtual ~Vehicle();
	void set(int x, int y);
	virtual void move(int) = 0;
	virtual void draw() = 0;
	//virtual void clear() = 0;
};



