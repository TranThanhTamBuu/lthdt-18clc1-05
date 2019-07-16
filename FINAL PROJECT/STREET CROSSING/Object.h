#pragma once

enum DState {
	UP, DOWN, LEFT, RIGHT
};

class Object
{
public:
	Object();
	Object(int _x, int _y) : x(_x), y(_y) {}
	virtual ~Object();

	unsigned int getXC();
	unsigned int getYC();
	void setXC(int _x);
	void setYC(int _y);

protected:
	int x;
	int y;
};

