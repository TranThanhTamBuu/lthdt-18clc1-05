#include "Car.h"

Car::Car(int x, int y) : Vehicle(x, y)
{
	pcar = car;
}

Car::~Car()
{
	pcar = NULL;
}

void Car::move(int step) {
	string temp;
	int length;


	clear();
	mX += step;

	int flag = mX + pcar[0].length();
	if (flag < 0) {
		mX = X_max - 1;
	}

	if (mX + pcar[0].length() >= X_max) {
		length = X_max - mX;
		for (int i = 0; i < 4; i++) {
			temp = pcar[i].substr(0, length);
			gotoXY(mX, mY + i);
			cout << temp;
		}
	}

	if (mX < 0 && mX + pcar[0].length() >= 0) {
		length = mX + pcar[0].length();
		for (int i = 0; i < 4; i++) {
			temp = pcar[i].substr(pcar[0].length() - length, length);
			gotoXY(0, mY + i);
			cout << temp;
		}
	}

	if (mX >= 0 && mX + pcar[0].length() < X_max) {
		for (int i = 0; i < 4; i++) {
			gotoXY(mX, mY + i);
			cout << pcar[i];
		}
	}
}

void Car::clear() {
	int length;

	if (mX + pcar[0].length() >= X_max) {
		length = X_max - mX;
	}

	if (mX < 0 && mX + pcar[0].length() >= 0) {
		length = mX + pcar[0].length();
	}

	if (mX >= 0 && mX + pcar[0].length() < X_max) {
		length = pcar[0].length();
	}

	for (int i = 0; i < 4; i++) {
		gotoXY(mX, mY + i);
		printSpace(length);
	}
}