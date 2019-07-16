#include "Coin.h"


unsigned Coin::nCoin = 0;

Coin::Coin() {
	++nCoin;
}


Coin::~Coin() {
	--nCoin;
}
