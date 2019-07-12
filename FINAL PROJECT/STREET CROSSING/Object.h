#pragma once
class Object
{
public:
	Object();
	Object(unsigned int _x, unsigned int _y) : x(_x), y(_y) {}
	virtual ~Object();

protected:
	unsigned int x;
	unsigned int y;
};

