#include "People.h"
#include "DirectionState.h"
#include "Left.h"
#include "Right.h"
#include "Up.h"
#include "Down.h"


int People::ownedModel[5] = { 1 };

People::People()
	: Object(X_max/2, 37, Wi), state(true), model(0), money(0) {
	currentDirectionState = new Down();
}

People::~People()
{
	delete currentDirectionState;
}

int People::getModel() {
	return model;
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
}

void People::clear() {
	currentDirectionState->clear(this, x, y);
}

void People::clearOnWood(DState state, unsigned step) {
	int min = step <= Wi ? step : Wi;
	switch (state) {
	case LEFT: {
		for (int i = 0; i < He; i++) {
			for (int j = 0; j < min; j++) {
				gotoXY((x + step) + (Wi - 1) / 2 - j, y - (He - 1) / 2 + i);
				wcout << " ";
			}
		}
		break;
	}

	case RIGHT: {
		for (int i = 0; i < He; i++) {
			for (int j = 0; j < min; j++) {
				gotoXY((x - step) - (Wi - 1) / 2 + j, y - (He - 1) / 2 + i);
				wcout << " ";
			}
		}
		break;
	}
	}
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
		
		gotoXY(xOri, yOri + 15);
		wcout << L"MONEY: " << money;
		gotoXY(xOri, yOri + 17);
		wcout << L"STATUS: " << (ownedModel[currentChoice] ? L"OWNED" : to_wstring(prizeModel[currentChoice]));
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
			if (ownedModel[currentChoice] == 1) {
				model = currentChoice;

				gotoXY(xOri + 20 * currentChoice - 3, yOri + 5);
				wcout << nameOpt[currentChoice];
				clrscr();
				return true;
			}
			else if (money >= prizeModel[currentChoice]) {
				money -= prizeModel[currentChoice];
				ownedModel[currentChoice] = 1;

				model = currentChoice;
				gotoXY(xOri + 20 * currentChoice - 3, yOri + 5);
				wcout << nameOpt[currentChoice];
				clrscr();
				return true;
			}
		}
		}
	}
}

void People::loadPeople(unsigned long _money, unsigned int _model, int* p) {
	money = _money;
	model = _model;
	for (int i = 0; i < 5; ++i) {
		ownedModel[i] = p[i];
	}
}

void People::displayMoney() {
	gotoXY(3, Y_max - 1);
	wcout << "Money: " << money;
}

int* People::getOwnedModel() {
	return ownedModel;
}

People& People::operator=(const People& rhs) {
	if (this != &rhs) {
		x = rhs.x;
		y = rhs.y;
		money = rhs.money;
		state = rhs.state;
		model = rhs.model;
		for (int i = 0; i < 5; ++i) {
			ownedModel[i] = rhs.ownedModel[i];
			prizeModel[i] = rhs.prizeModel[i];
		}
		DState oldState = currentDirectionState->getCurrentState();
		delete currentDirectionState;
		switch (oldState) {
		case UP: {
			currentDirectionState = new Up();
			break;
		}
		case DOWN: {
			currentDirectionState = new Down();
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
	return *this;
}