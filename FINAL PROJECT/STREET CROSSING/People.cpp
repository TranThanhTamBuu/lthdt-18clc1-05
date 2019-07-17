#include "People.h"
#include "DirectionState.h"
#include "Left.h"
#include "Right.h"
#include "Up.h"
#include "Down.h"


People::People()
	: Object(X_max/2, 37), state(true), model(2), money(0)  {
	currentDirectionState = new Down();
}

People::~People()
{
	delete currentDirectionState;
}

unsigned int People::getX() {
	return x - (Wi-1)/2;
}



unsigned int People::getY() {
	return y - (He-1)/2;
}

unsigned long People::getMoney() {
	return money;
}

void People::changeMoney(int amount) {
	money += amount;
}

void People::setY(unsigned int _y) {
	y = _y + (He - 1) / 2;
}

void People::goUp(int step) {
	if (y > 0 + step + (He - 1) / 2) {
		y -= step;
	}
}

void People::goDown(int step) {
	if (y < Y_max - step - (He-1)/2) {
		y += step;
	}
}

void People::goLeft(int step) {
	if (x > 0 + STEPRIGHTLEFT + (Wi - 1) / 2) {
		x -= step;
	}
}

void People::goRight(int step) {
	if (x < X_max - STEPRIGHTLEFT - (Wi - 1) / 2) {
		x += step;
	}
}

void People::draw() {
	currentDirectionState->draw(this, x, y, model);
	currentDirectionState->clear(this, x, y);
}

void People::clearImage() {
	for (int i = 0; i < He; ++i) {
		for (int j = 0; j < Wi; ++j) {
			gotoXY(x - (Wi - 1) / 2 + j, y - (He - 1) / 2 + i);
			wcout << ' ';
		}
	}
	gotoXY(x, y);
}

bool People::isDead() {
	return state;
}

void People::changeDirectionState(DState dSta) {
	if (currentDirectionState->getCurrentState() != dSta) {
		delete currentDirectionState;

		switch (dSta) {
		case UP: {
			currentDirectionState = new Up();
			break;
		}
		case DOWN: {
			currentDirectionState = new Down();
			break;
		}
		case RIGHT: {
			currentDirectionState = new Right();
			break;
		}
		case LEFT: {
			currentDirectionState = new Left();
			break;
		}		
		}
	}
}

bool People::chooseModel() {
	wstring nameOpt[] = { L"MODEL 1", L"MODEL 2", L"MODEL 3", L"MODEL 4", L"MODEL 5"};
	unsigned int currentChoice = 0,
		max = 5,
		xOri = 35, yOri = 20;

	while (true) {
		clrscr();
		
		for (int i = 0; i < max; i++) {
			gotoXY(xOri + 20 * i, yOri);
			currentDirectionState->draw(this, xOri + 20 * i, yOri, i);
			gotoXY(xOri + 20 * i - 3, yOri + 5);
			if (i == currentChoice) {
				setColor(12, 7);
				wcout << nameOpt[i];
				setColor(7, 0);
			}
			else {
				wcout << nameOpt[i];
			}
		}

		int key = _getch();
		if (key == 224) {
			key = _getch();
		}
		switch (key) {
		case 'D': case 'd': case 77: {
			if (currentChoice < max-1) {
				++currentChoice;
			}
			break;
		}
		case 'A': case 'a': case 75: {
			if (currentChoice > 0) {
				--currentChoice;
			}
			break;
		}
		case 13: {
			model = currentChoice;

			gotoXY(xOri + 20 * currentChoice - 3, yOri + 5);
			wcout << nameOpt[currentChoice];
			clrscr();
			return true;
		}
		}
	}
}
