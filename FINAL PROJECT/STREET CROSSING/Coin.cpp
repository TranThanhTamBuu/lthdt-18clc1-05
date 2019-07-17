#include "Coin.h"
#define W 3
#define H 3


unsigned Coin::nCoin = 0;
const wchar_t Coin::image[3][5] = {
	{ L' ',L'_',L'☼',L'_',L' ' },
	{ L'.',L'\\',L'$',L'/',L'.' },
	{ L'(',L']',L'$',L'[',L')' }
};

Coin::Coin()
	: stateOnWood(LEFT), iY(0) {
	++nCoin;
}

Coin::Coin(int _x, int _y, DState state, int _iY)
	: Object(_x,_y), stateOnWood(state), iY(_iY) {
	++nCoin;
}

Coin::~Coin() {
	--nCoin;
}

int Coin::getiY() {
	return iY;
}

void Coin::setiY(int _iY) {
	iY = _iY;
}

void Coin::draw() {
	if (x < 0 || y < 0 || x > X_max || y > Y_max) return;

	setColor(14, 0);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			gotoXY(x - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
			wcout << image[i][j];
		}
	}
	gotoXY(x, y);
	setColor(7, 0);
}

void Coin::clear(unsigned step) {
	switch (stateOnWood) {
	case LEFT: {
		int min = step <= w ? step : w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < min; j++) {
				gotoXY((x + step) + (w - 1) / 2 - j, y - (h - 1) / 2 + i);
				wcout << " ";
			}
		}
		break;
	}
	case RIGHT: {
		int min = step <= w ? step : w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < min; j++) {
				gotoXY((x - step) - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
				wcout << " ";
			}
		}
		break;
	}
	}
}

void Coin::onWood(unsigned step) {
	switch (stateOnWood) {
	case LEFT: {
		x -= step;
		draw();
		clear(step);
		break;
	}
	case RIGHT: {
		x += step;
		draw();
		clear(step);
		break;
	}
	}
}

bool Coin::isImpact(int hX, int hY) {
	if (abs(x - hX) < 6 && abs(y - hY) < 3) return true;
	return false;
}

bool Coin::isReachEdge() {
	switch (stateOnWood) {
	case LEFT: {
		if (x < 0) return true;
		break;
	}
	case RIGHT: {
		if (x > X_max) return true;
		break;
	}
	}

	return false;
}

void Coin::setY(int _y) {
	y = _y;
}

void Coin::clearImage() {
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			gotoXY(x - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
			wcout << ' ';
		}
	}
	gotoXY(x, y);
}
