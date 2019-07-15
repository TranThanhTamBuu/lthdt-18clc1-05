#pragma once
#include "River.h"

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
	~Wood();

private:
	wstring *pwood;
};

Wood** createWoods(int yWood[], int lineWood, int *numWood, int *spdWood);