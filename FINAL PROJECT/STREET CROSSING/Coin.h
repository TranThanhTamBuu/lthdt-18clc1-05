#pragma once
#include "Object.h"


class Coin: public Object
{
public:
	Coin();
	~Coin();

	void draw();

private:
	static unsigned nCoin;
};

