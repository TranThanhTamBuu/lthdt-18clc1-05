#include "People.h"
#define STEP 2

People::People()
	: Object(), state(true), model(1)  {
}

People::~People()
{
}

void People::goUp(int step) {
	clear();
	y -= step;
	gotoXY(x, y);
	draw();
}

void People::goDown(int step) {
	clear();
	y += step;
	gotoXY(x, y);
	draw();
}

void People::goLeft(int step) {
	clear();
	x -= step;
	gotoXY(x, y);
	draw();
}

void People::goRight(int step) {
	clear();
	x += step;
	gotoXY(x, y);
	draw();
}

void People::draw() {
	switch (model) {
	case 0: {
		cout << " () ";
		gotoXY(x, y + 1);
		cout << "/||\\";
		gotoXY(x, y + 2);
		cout << " /\\ ";
		break;
	}
	case 1: {
		cout << "  {~} ";
		gotoXY(x, y + 1);
		cout << " /###\\";
		gotoXY(x, y + 2);
		cout << "/ === \\";
		gotoXY(x, y + 3);
		cout << " || ||";
		break;
	}
	}
	
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

void People::move(char key) {
	switch (key) {
	case 'W': case 'w': {
		goUp(STEP);
		break;
	}
	case 'S': case 's': {
		goDown(STEP);
		break;
	}
	case 'D': case 'd': {
		goRight(STEP);
		break;
	}
	case 'A': case 'a': {
		goLeft(STEP);
		break;
	}
	}
}
