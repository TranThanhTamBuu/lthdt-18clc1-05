﻿#pragma once
#include <string>
#include "Wood.h"
#include "Object.h"
#include "Console.h"

class Wood;

static wstring coin[3] = {
	L" _☼_ ",
	L".\\$/.",
	L"(]$[)",
};

class Coin: public Object
{
public:
	Coin();
	Coin(int x, int y, DState, int _iY = 0);
	~Coin();

	void draw();
	void clear(unsigned step);
	void clearImage();
	void clearImageOnWood();
	void onWood(unsigned step);
	bool isImpact(int hX, int hY);
	bool isImpactOnWood(int hX, int hY);
	bool isReachEdge();
	void setY(int _y);
	void setiY(int _iY);
	void setiX(int _iX);
	int getiX();
	int getiY();
	// static unsigned getNCoin();
	int getDistanceFromWood(const Wood &wo);
	void moveOnRiver(int step, const Wood &wo); // step < 0
	void drawMove(int step);
	void clearMove(int step);
	int getX();
	int getY();
	void setX(int _x);

private:
	DState stateOnWood;
	static unsigned nCoin;
	static const wchar_t image[3][5];
	unsigned h = 3, w = 5;
	int iY;
	int iX;
};
