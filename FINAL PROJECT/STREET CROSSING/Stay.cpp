#include "Stay.h"


DState Stay::getCurrentState() {
	return STAY;
}

void Stay::draw(People *const peoplePtr, unsigned int x, unsigned int y, int model) {
	wchar_t image[3][7];
	int w = 7, h = 3;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			image[i][j] = ' ';
		}
	}

	switch (model) {
	case 0: {	
		image[0][2] = L'˄';
		image[0][4] = L'˄';
		image[1][0] = L'/';
		image[1][2] = L'ϖ';
		image[1][4] = L'ϖ';
		image[1][6] = L'\\';
		image[2][0] = L'(';
		image[2][1] = L'Ҧ';
		image[2][3] = L'ᴥ';
		image[2][5] = L'Ҧ';
		image[2][6] = L')';

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++) {
				gotoXY(x - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
				if ((i == 0 & j == 2) || (i == 0 & j == 4) || (i == 2 & j == 1) || (i == 2 & j == 5)) {
					randomColor(image[i][j]);
				}
				else {
					wcout << image[i][j];
				}
			}
		}
		gotoXY(x, y);
		break;
	}

	case 1: {
		image[0][2] = L'ψ';
		image[0][4] = L'ψ';
		image[0][3] = L'_';
		image[1][2] = L'(';
		image[1][3] = L'Ж';
		image[1][4] = L')';
		image[2][0] = L'~';
		image[2][1] = L'(';
		image[2][2] = L'■';
		image[2][3] = L'_';
		image[2][4] = L'■';
		image[2][5] = L')';
		image[2][6] = L'~';

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++) {
				gotoXY(x - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
				if ((i == 1 & j == 2) || (i == 1 & j == 4) || (i == 0 & j == 2) || (i == 0 & j == 4)) {
					randomColor(image[i][j]);
				}
				else {
					wcout << image[i][j];
				}
			}
		}
		gotoXY(x, y);
		break;
	}
	}
}