#pragma once
#include "Object.h"
#include "Console.h"

class Coin: public Object
{
public:
	Coin();
	Coin(int x, int y, DState);
	~Coin();

	void draw();
	void clear(unsigned step);
	void clearImage();
	void onWood(unsigned step);
	bool isImpact(int hX, int hY);
	bool isReachEdge();
	void setY(int _y);

private:
	DState stateOnWood;
	static unsigned nCoin;
	static const wchar_t image[3][3];
	unsigned h = 3, w = 3;

};

