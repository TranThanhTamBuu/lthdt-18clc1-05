#pragma once

enum DState {
	UP, DOWN, LEFT, RIGHT
};

class Object
{
public:
	Object();
	Object(int _x, int _y, int _length) : x(_x), y(_y), length(_length) {}
	virtual ~Object();

	int getXC();
	int getYC();
	int getX();
	int getY();
	void setX();
	void setY();
	void setXC(int _x);
	void setYC(int _y);

protected:
	int x;
	int y;
	int length;
};

