#include "Lilypad.h"



Lilypad::Lilypad() {
	ppad = lilypad;
}

Lilypad::Lilypad(int x, int y) : River(x, y, 0) {
	ppad = lilypad;
}

Lilypad::~Lilypad(){
	ppad = nullptr;
	people = false;
}

void Lilypad::draw() {
	setColor(2, 0);
	if (people) {
		if (timeLeft() > 2) {
			setColor(14, 0);
		}
		if (timeLeft() > 4) {
			setColor(12, 0);
		}
	}

	for (int i = 0; i < 3; i++) {
		gotoXY(mX, mY + i);
		wcout << ppad[i];
	}

	setColor(7, 0);
}

void Lilypad::setOn() {
	people = true;
}

bool Lilypad::getState() {
	return people;
}

void Lilypad::clear() {
	for (int i = 0; i < 3; i++) {
		gotoXY(mX, mY + i);
		printSpace(lilypad[0].length());
	}
}

bool Lilypad::isImpact(People &people) {
	int leftX = people.getX();
	int rightX = leftX + Wi - 1;

	if (((mX <= leftX && (leftX <= mX + lilypad[0].length() - 1)) || (mX <= rightX && rightX <= mX + lilypad[0].length() - 1))) {
		return true;
	}

	return false;
}

void Lilypad::startTime() {
	time(&start);
}

void Lilypad::setTime() {
	time(&now);
}

int Lilypad::timeLeft() {
	return difftime(now, start);
}

bool isUsed(int x, vector <int> usedX) {
	for (int v = 0; v < usedX.size(); v++) {
		if (x == usedX[v]) {
			return true;
		}
	}
	return false;
}
