#include "Right.h"


DState Right::getCurrentState() {
	return RIGHT;
}

void Right::draw(People *const peoplePtr, unsigned int x, unsigned int y, int model) {
	switch (model) {
	case 1: {
		wchar_t image[3][7];
		int w = 7, h = 3;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				image[i][j] = ' ';
			}
		}

		image[0][2] = L'˄';
		image[0][4] = L'˄';
		image[1][0] = L'/';
		image[1][2] = L'ϖ';
		image[1][4] = L'ϖ';
		image[1][5] = L'|';
		image[2][0] = L'(';
		image[2][1] = L'ɜ';
		image[2][3] = L'ᴥ';
		image[2][5] = L')';
		image[2][6] = L'ɜ';

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++) {
				gotoXY(x - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
				if ((i == 0 & j == 2) || (i == 0 & j == 4) || (i == 2 & j == 1) || (i == 2 & j == 6)) {
					randomColor(image[i][j]);
				}
				else {
					wcout << image[i][j];
				}
			}
		}
		break;
	}
	}
}