#pragma once
#include "Object.h"
#include "Console.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#define Wi 7
#define He 3
#define STEPUPDOWN 8
#define STEPRIGHTLEFT 3
using namespace std;


class DirectionState;

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
	void clearOnWood(DState, unsigned step);
	void clearImage();
	bool chooseModel();
	unsigned int getX();
	unsigned int getY();
	unsigned long getMoney();
	void changeMoney(int amount);
	void setY(unsigned int _y);
	int getModel();
	void loadPeople(unsigned long money, unsigned int model, int* owned);
	void displayMoney();
	int* getOwnedModel();
	People& operator=(const People& rhs);

private:
	unsigned long money;
	bool state;
	unsigned int model;
	int ownedModel[5] = { 1 };
	int prizeModel[5] = { 1500, 1800, 2500, 3200 ,4200 };
	DirectionState *currentDirectionState;
};
