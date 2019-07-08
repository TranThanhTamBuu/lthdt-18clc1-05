#include "Down.h"


DState Down::getCurrentState() {
	return DOWN;
}

void Down::draw(People *const peoplePtr, unsigned int x, unsigned int y, int model) {
	int w = 7, h = 3;

	switch (model) {
	case 0: {
		wchar_t image[3][7] = {
			{ L' ',L' ',L'˄',L'-',L'˄',L' ',L' ' },
			{ L' ',L'/',L'ϖ',L' ',L'ϖ',L'\\',L' ' },
			{ L'(',L'Ҧ',L' ',L'ᴥ',L' ',L'Ҧ',L')' }
		};

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
		wchar_t image[3][7] = {
			{ L' ',L' ',L'ψ',L'_',L'ψ',L' ',L' ' },
			{ L' ',L'_',L'(',L'Ж',L')',L'_',L' ' },
			{ L'(',L'⌐',L'■',L'_',L'■',L'¬',L')' }
		};

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++) {
				gotoXY(x - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
				if ((i == 2 && j == 1) || (i == 2 && j == 5) || (i == 1 && j == 2) || (i == 1 && j == 4) || (i == 0 && j == 2) || (i == 0 && j == 4)) {
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

	case 2: {
		wchar_t image[3][7] = {
			{ L' ',L'(',L'\\',L'_',L'/',L')',L' ' },
			{ L'(',L'=',L'\'',L'ɷ',L'\'',L'=',L')' },
			{ L'(',L'"',L')',L'¨',L'(',L'"',L')' }
		};

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++) {
				gotoXY(x - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
				if ((i == 0 && j == 1) || (i == 0 && j == 2) || (i == 0 && j == 3) || (i == 0 && j == 4) || (i == 1 && j == 1) || (i == 1 && j == 5)) {
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

void Down::clear(People *const peoplePtr, unsigned int x, unsigned int y, unsigned int step) {
	int min = step <= He ? step : He;
	for (int i = 0; i < min; i++) {
		for (int j = 0; j < Wi; j++) {
			gotoXY(x - (Wi - 1) / 2 + j, (y-step) - (He - 1) / 2 + i);
			wcout << " ";
		}
	}
}