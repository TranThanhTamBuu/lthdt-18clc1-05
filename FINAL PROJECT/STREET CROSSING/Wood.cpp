#include "Wood.h"


Wood::Wood()
{
	pwood = wood;
}

Wood::Wood(int x, int y, int speed) : River(x, y, speed)
{
	pwood = wood;
}

Wood::~Wood()
{
	pwood = NULL;
}

void Wood::move() {
	mX += speed;

	int flag = mX + pwood[0].length();
	if (flag < 0) {
		clear();
		mX = X_max - 1;
	}
}

void Wood::draw() {
	wstring temp;
	int length;

	if (mX + pwood[0].length() >= X_max) {
		length = X_max - mX;
		for (int i = 0; i < 3; i++) {
			temp = pwood[i].substr(0, length);
			gotoXY(mX, mY + i);
			wcout << temp;
		}
	}

	if (mX < 0 && mX + pwood[0].length() >= 0) {
		length = mX + pwood[0].length();
		for (int i = 0; i < 3; i++) {
			temp = pwood[i].substr(pwood[0].length() - length, length);
			gotoXY(0, mY + i);
			wcout << temp;
		}
	}

	if (mX >= 0 && mX + pwood[0].length() < X_max) {
		for (int i = 0; i < 3; i++) {
			gotoXY(mX, mY + i);
			wcout << pwood[i];
		}
	}

	clear();
}

void Wood::clear() {
	int length = abs(speed);
	int x;

	int flag = mX + pwood[0].length();
	if (flag >= X_max) {
		return;
	}

	if (X_max - mX + pwood[0].length() < length && mX + pwood[0].length() < X_max) {
		length = X_max - mX + pwood[0].length();
	}

	x = mX + pwood[0].length();
	if (x < 0) {
		length += x;
		x = 0;
	}

	for (int i = 0; i < 3; i++) {
		gotoXY(x, mY + i);
		printSpace(length);
	}
}

bool Wood::isImpact(People &people) {
	int leftX = people.getX();
	int rightX = leftX + Wi;

	if (((mX <= leftX && (leftX <= mX + wood[0].length())) || (mX <= rightX && rightX <= mX + wood[0].length()))) {
		return true;
	}

	return false;
}

Wood** createWoods(int yWood[], int lineWood, int *numWood, int *spdWood) {
	Wood** woodPtr = new Wood*[lineWood];
	for (int i = 0; i < lineWood; i++) {
		woodPtr[i] = new Wood[numWood[i]];
	}

	for (int i = 0; i < lineWood; i++) {
		int d = (X_max - (numWood[i] - 1)*wood[0].length()) / (numWood[i]);
		for (int j = 0; j < numWood[i]; j++) {
			int xwood = (d - (int)wood[0].length()) / 2 + j * (d + (int)wood[0].length());
			woodPtr[i][j].set(xwood, yWood[i], spdWood[i]);
		}
	}

	return woodPtr;
}
