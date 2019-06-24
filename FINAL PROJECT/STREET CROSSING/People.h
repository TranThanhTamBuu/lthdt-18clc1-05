#pragma once
#include "Object.h"
#include "Console.h"
#include <iostream>
using namespace std;


class People: public Object
{
public:
	People();
	virtual ~People();

	void goUp(int step);
	void goDown(int step);
	void goLeft(int step);
	void goRight(int step);
	bool isImpact(const Object* &obj);
	bool isDead();
	bool isFinish();
	void draw();
	void clear();
	void move(char key);

private:
	bool state;
	unsigned int model;
};

