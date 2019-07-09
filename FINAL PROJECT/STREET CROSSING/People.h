#pragma once
#include "Object.h"
#include "Console.h"
#include <iostream>
#include <string>
#include <iomanip>
#define Wi 7
#define He 3
#define STEP 3
using namespace std;


class DirectionState;
enum DState {
	UP, DOWN, LEFT, RIGHT
};

class People : public Object
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

