#pragma once
#include "Console.h"
#include <string>
#include "People.h"

static time_t lapse;

class River
{
public:
	River();
	River(int x, int y, int spd);
	void set(int, int, int);
	virtual void draw() = 0;
	virtual void clear() = 0;
	virtual bool isImpact(People &people) = 0;
	int getY() const;
	int getX() const;
	void setY(int y);
	virtual ~River();
	void drawWave();
protected:
	int mX, mY, speed;
};
