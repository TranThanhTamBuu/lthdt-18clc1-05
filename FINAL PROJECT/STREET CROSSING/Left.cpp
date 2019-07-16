#include "Left.h"

DState Left::getCurrentState() {
	return LEFT;
}

void Left::draw(People *const peoplePtr, unsigned int x, unsigned int y, int model) {
	int w = 7, h = 3;

	switch (model) {
	case 0: {
		wchar_t image[3][7] = {
			{ L' ',L'.',L'˄',L'-',L'˄',L'.',L' '},
			{ L' ',L'|',L'ϖ',L' ',L'ϖ',L' ',L'\\'},
			{ L'ɛ',L'(',L' ',L'ᴥ',L' ',L'ɛ',L')'}
		};

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++) {
				gotoXY(x - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
				if ((i == 0 & j == 2) || (i == 0 & j == 4) || (i == 2 & j == 0) || (i == 2 & j == 5)) {
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
			{ L'Ͼ',L'(',L'■',L'_',L'■',L'¬',L')'}
		};

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++) {
				gotoXY(x - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
				if ((i == 0 && j == 2) || (i == 0 && j == 4) || (i == 1 && j == 3) || (i == 2 && j == 0)) {
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
			{ L' ',L'/',L')',L'_',L'/',L')',L' ' },
			{ L'(',L'\'',L'Ɛ',L'\'',L'=',L' ',L')'},
			{ L'(',L'"',L')',L'(',L'"',L')',L'O' }
		};

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++) {
				gotoXY(x - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
				if ((i == 0 && j == 1) || (i == 0 && j == 2) || (i == 0 && j == 4) || (i == 0 && j == 5) || (i == 2 && j == 6)) {
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
			{ L' ',L'(',L'ὂ',L'<',L'ὅ',L')',L' ' },
			{ L'ʚ',L'{',L'(',L'‼',L'ʅ',L'}',L'”' }
		};

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++) {
				gotoXY(x - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
				if ((i == 2 && j == 3) || (i == 2 && j == 0) || (i == 0 && j == 2) || (i == 0 && j == 4)) {
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

	case 4: {
		wchar_t image[3][7] = {
			{ L' ',L'/',L'\\',L'*',L'/',L'\\',L' ' },
			{ L'(',L'ᴓ',L'ᴥ',L'o',L'‟',L'=',L')' },
			{ L'(',L'ṁ',L'♦',L'_',L'ṁ',L'_',L')' }
		};

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++) {
				gotoXY(x - (w - 1) / 2 + j, y - (h - 1) / 2 + i);
				if ((i == 0 && j == 3) || (i == 2 && j == 2)) {
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

void Left::clear(People *const peoplePtr, unsigned int x, unsigned int y) {
	int min = STEPRIGHTLEFT <= Wi ? STEPRIGHTLEFT : Wi;
	for (int i = 0; i < He; i++) {
		for (int j = 0; j < min; j++) {
			gotoXY((x+ STEPRIGHTLEFT) + (Wi - 1) / 2 - j, y - (He - 1) / 2 + i);
			wcout << " ";
		}
	}
}
