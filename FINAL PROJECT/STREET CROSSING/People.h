#pragma once
#include "Object.h"
#include "Console.h"
#include <iostream>
#include <string>
using namespace std;


class DirectionState;
enum DState {
	STAY, LEFT, RIGHT
};

class People: public Object
{
public:
	People();
	virtual ~People();

	void changeDirectionState(DState);
	void goUp(int step);
	void goDown(int step);
	void goLeft(int step);
	void goRight(int step);
	bool isImpact(const Object* &obj);
	bool isDead();
	bool isFinish();
	void draw();
	void clear();
	bool chooseModel();

private:
	bool state;
	unsigned int model;
	DirectionState *currentDirectionState;
};

