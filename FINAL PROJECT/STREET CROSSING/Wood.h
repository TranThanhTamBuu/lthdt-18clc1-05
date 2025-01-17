#pragma once
#include "River.h"
#include "Coin.h"

static wstring wood[3] = {
	L" _____________________ ",
	L"/_____________________\\",
	L"[_____________________]"
};


class Wood : public River
{
public:
	Wood();
	Wood(int x, int y, int speed);
	void move();
	void draw();
	void clear();
	bool isImpact(People &people);
	~Wood();

private:
	wstring *pwood;
};

Wood** createWoods(int yWood[], int lineWood, int *numWood, int *spdWood);
