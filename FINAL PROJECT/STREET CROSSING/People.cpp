#include "People.h"
#include "DirectionState.h"
#include "Left.h"
#include "Right.h"
#include "Up.h"
#include "Down.h"


People::People()
	: Object(), state(true), model(2)  {
	currentDirectionState = new Up();
}

People::~People()
{
	delete currentDirectionState;
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
	if (x > 0 + STEP + (Wi - 1) / 2) {
		x -= step;
	}
}

void People::goRight(int step) {
	if (x < X_max - STEP - (Wi - 1) / 2) {
		x += step;
	}
}

void People::draw() {
	currentDirectionState->draw(this, x, y, model);
	currentDirectionState->clear(this, x, y, STEP);
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
	wstring nameOpt[] = { L"MODEL 1", L"MODEL 2", L"MODEL 3", L"MODEL 4"};
	unsigned int currentChoice = 0,
		max = 4,
		xOri = 40, yOri = 20;

	while (true) {
		clrscr();
		
		for (int i = 0; i < max; i++) {
			gotoXY(xOri + 20 * i, yOri);
			currentDirectionState->draw(this, xOri + 20 * i, yOri, i);
			gotoXY(xOri + 20 * i - 3, yOri + 5);
			if (i == currentChoice) {
				setColor(13, 7);
				wcout << nameOpt[i];
				setColor(13, 0);
			}
			else {
				wcout << nameOpt[i];
			}
		}

		int key = _getch();
		switch (key) {
		case 'D': case 'd': {
			if (currentChoice < max-1) {
				++currentChoice;
			}
			break;
		}
		case 'A': case 'a': {
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