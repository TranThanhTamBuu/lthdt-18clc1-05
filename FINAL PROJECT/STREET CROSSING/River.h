#pragma once
#include "Console.h"
#include <string>

class River
{
public:
	River();
	River(int x, int y, int spd); 
	void set(int, int, int);
	virtual void draw() = 0;
	virtual void clear() = 0;
	int getY();
	void setY(int y);
	virtual ~River();
protected:
	int mX, mY, speed;
};

