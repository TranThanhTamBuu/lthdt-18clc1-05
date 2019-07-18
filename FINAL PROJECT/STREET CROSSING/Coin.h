#pragma once
#include "Object.h"
#include "Console.h"
#include <string>

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
	void onWood(unsigned step);
	bool isImpact(int hX, int hY);
	bool isReachEdge();
	void setY(int _y);
	void setiY(int _iY);
	int getiY();
	static unsigned getNCoin();

	void move(int step); // step < 0
	void drawMove(int step);
	void clearMove(int step);

private:
	DState stateOnWood;
	static unsigned nCoin;
	static const wchar_t image[3][5];
	unsigned h = 3, w = 5;
	int iY;
	
};
