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
	: Object(_x, _y), stateOnWood(state), iY(_iY) {
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

void Coin::setiX(int _iX) {
	iX = _iX;
}

int Coin::getiX() {
	return iX;
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


void Coin::moveOnRiver(int step, const Wood &wo) {
	x += step;

	int flag = x + w;
	if (flag < 0) {
		clearMove(step);
		int d = getDistanceFromWood(wo);
		x = X_max - 1 + (wood[0].length() -  d - w) + d;
	}
}

int Coin::getDistanceFromWood(const Wood &wo) {
	return ((x - (w - 1) / 2) - wo.getX());
}

void Coin::drawMove(int step) {
	wstring temp;
	int length;
	setColor(14, 0);

	if (x + w >= X_max) {
		length = X_max - x;
		for (int i = 0; i < 3; i++) {
			temp = coin[i].substr(0, length);
			gotoXY(x, y + i);
			wcout << temp;
		}
	}

	if (x < 0 && x + w >= 0) {
		length = x + w;
		for (int i = 0; i < 3; i++) {
			temp = coin[i].substr(w - length, length);
			gotoXY(0, y + i);
			wcout << temp;
		}
	}

	if (x >= 0 && x + w < X_max) {
		for (int i = 0; i < h; i++) {
			gotoXY(x, y + i);
			wcout << coin[i];
		}
	}

	setColor(7, 0);
	clearMove(step);
}

void Coin::clearMove(int step) {
	int length = abs(step);
	int _x;

	int flag = x + w;
	if (flag >= X_max) {
		return;
	}

	if (X_max - x + w < length && x + w < X_max) {
		length = X_max - x + w;
	}

	_x = x + w;
	if (_x < 0) {
		length += _x;
		_x = 0;
	}

	for (int i = 0; i < 3; i++) {
		gotoXY(_x, y + i);
		printSpace(length);
	}
}