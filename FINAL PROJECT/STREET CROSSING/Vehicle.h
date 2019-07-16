#pragma once
#include "Console.h"
#include <string>
#include "People.h"


class Vehicle
{
protected:
	int mX, mY, speed;

public:
	Vehicle();
	Vehicle(int x, int y, int spd);
	virtual ~Vehicle();
	void set(int, int, int);
	virtual void move() = 0;
	virtual void draw() = 0;
	virtual void clear() = 0;
	virtual bool isImpact(People &people) = 0;
	int getY();
	void setY(int y);
};

