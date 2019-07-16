#include "Coin.h"
#define W 3
#define H 3


unsigned Coin::nCoin = 0;
const wchar_t Coin::image[3][3] = {
	{ L'✶',L'✶',L'✶' },
	{ L'✶',L'$',L'✶' },
	{ L'✶',L'✶',L'✶' }
};

Coin::Coin()
	: stateOnWood(LEFT) {
	++nCoin;
}

Coin::Coin(int _x, int _y, DState state)
	: Object(_x,_y), stateOnWood(state) {
	++nCoin;
}

Coin::~Coin() {
	--nCoin;
}

void Coin::draw() {
	if (x < 0 || y < 0 || x > X_max || y > Y_max) return;
	
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			gotoXY(x - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
			if ((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 0 && j == 2) || (i == 1 && j == 0) || (i == 1 && j == 2) || (i == 2 && j == 0) || (i == 2 && j == 1) || (i == 2 && j == 2)) {
				int z = rand() % 15 + 1;

				setColor(z, 0);
				wcout << image[i][j];
				setColor(7, 0);
			}
			else {
				wcout << image[i][j];
			}
		}
	}
	gotoXY(x, y);
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
	if (abs(x - hX) < 5 && abs(y - hY) < 3) return true;
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