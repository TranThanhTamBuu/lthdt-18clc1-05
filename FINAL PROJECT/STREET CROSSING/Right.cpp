#include "Right.h"


DState Right::getCurrentState() {
	return RIGHT;
}

void Right::draw(People *const peoplePtr, unsigned int x, unsigned int y, int model) {
	int w = 7, h = 3;

	switch (model) {
	case 0: {
		wchar_t image[3][7] = {
			{ L' ',L'.',L'˄',L'-',L'˄',L'.',L' ' },
			{ L'/',L' ',L'ϖ',L' ',L'ϖ',L'|',L' ' },
			{ L'(',L'ɜ',L' ',L'ᴥ',L' ',L')',L'ɜ' }
		};

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
		gotoXY(x, y);
		break;
	}

	case 1: {
		wchar_t image[3][7] = {
			{ L' ',L' ',L'ψ',L'_',L'ψ',L' ',L' '},
			{ L' ',L'_',L'(',L'Ж',L')',L'_',L' '},
			{ L'(',L'⌐',L'■',L'_',L'■',L')',L'Ͽ'}
		};

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++) {
				gotoXY(x - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
				if ((i == 0 && j == 2) || (i == 0 && j == 4) || (i == 1 && j == 3) || (i == 2 && j == 6)) {
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
			{ L' ',L'(',L'\\',L'_',L'(',L'\\',L' '},
			{ L'(',L' ',L'=',L'\'',L'3',L'\'',L')'},
			{ L'O',L'(',L'"',L')',L'(',L'"',L')'  }
		};

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++) {
				gotoXY(x - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
				if ((i == 0 && j == 1) || (i == 0 && j == 2) || (i == 0 && j == 4) || (i == 0 && j == 5) || (i == 2 && j == 0)) {
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

	case 3: {
		wchar_t image[3][7] = {
			{ L' ',L' ',L',',L'_',L',',L' ',L' ' },
			{ L' ',L'(',L'ὂ',L'˃',L'ὅ',L')',L' ' },
			{ L'‟',L'{',L'ʃ',L'‼',L')',L'}',L'ɞ' }
		};

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++) {
				gotoXY(x - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
				if ((i == 2 && j == 3) || (i == 2 && j == 6) || (i == 0 && j == 2) || (i == 0 && j == 4)) {
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

void Right::clear(People *const peoplePtr, unsigned int x, unsigned int y, unsigned int step) {
	int min = step <= Wi ? step : Wi;
	for (int i = 0; i < He; i++) {
		for (int j = 0; j < min; j++) {
			gotoXY((x-step) - (Wi - 1) / 2 + j, y - (He - 1) / 2 + i);
			wcout << " ";
		}
	}
}