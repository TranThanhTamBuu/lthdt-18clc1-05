#pragma once
#include "Coin.h"
#include <vector>

class CoinMachine
{
public:
	CoinMachine();
	~CoinMachine();
	unsigned* randomPos();
	void createCoins();

private:
	vector<Coin> coins;
};

