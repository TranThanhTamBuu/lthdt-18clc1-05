#include "People.h"
#include "DirectionState.h"
#include "Left.h"
#include "Right.h"
#include "Stay.h"
#define STEP 1
#define Wi 7
#define He 3

People::People()
	: Object(), state(true), model(1)  {
	currentDirectionState = new Stay();
}

People::~People()
{
	delete currentDirectionState;
}

void People::goUp(int step) {
	if (y >= 0 + 5) {
		y -= step;
	}
}

void People::goDown(int step) {
	if (y <= Y_max - 3) {
		y += step;
	}
}

void People::goLeft(int step) {
	if (x >= 0 + STEP + (Wi-1)/2) {
		x -= step;
	}
}

void People::goRight(int step) {
	if (x <= 165) {
		x += step;
	}
}

void People::draw() {
	currentDirectionState->draw(this, x, y, model);
}

void People::clear() {
	switch (model) {
	case 0: {
		gotoXY(x, y);
		cout << "          ";
		gotoXY(x, y + 1);
		cout << "          ";
		gotoXY(x, y + 2);
		cout << "          ";
		gotoXY(x, y);
		break;
	}
	case 1:
		gotoXY(x, y);
		cout << "          ";
		gotoXY(x, y + 1);
		cout << "          ";
		gotoXY(x, y + 2);
		cout << "          ";
		gotoXY(x, y + 3);
		cout << "          ";
		gotoXY(x, y);
		break;
	}
	
}

bool People::isDead() {
	return state;
}

void People::updatePosPeople(char key) {
	switch (key) {
	case 'W': case 'w': {
		goUp(STEP);
		changeDirectionState(STAY);
		break;
	}
	case 'S': case 's': {
		goDown(STEP);
		changeDirectionState(STAY);
		break;
	}
	case 'D': case 'd': {
		goRight(STEP);
		changeDirectionState(RIGHT);
		break;
	}
	case 'A': case 'a': {
		goLeft(STEP);
		changeDirectionState(LEFT);
		break;
	}
	}
}

void People::changeDirectionState(DState dSta) {
	if (currentDirectionState->getCurrentState() != dSta) {
		delete currentDirectionState;

		switch (dSta) {
		case STAY: {
			currentDirectionState = new Stay();
			break;
		}
		case LEFT: {
			currentDirectionState = new Left();
			break;
		}
		case RIGHT: {
			currentDirectionState = new Right();
			break;
		}
		}
	}
}
