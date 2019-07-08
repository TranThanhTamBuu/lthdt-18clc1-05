#include "Car.h"

Car::Car() 
{
	pcar = car;
}

Car::Car(int x, int y, int speed) : Vehicle(x, y, speed)
{
	pcar = car;
}

Car::~Car()
{
	pcar = NULL;
}

void Car::move() {
	mX += speed;

	int flag = mX + pcar[0].length();
	if (flag < 0) {
		clear();
		mX = X_max - 1;
	}
}

void Car::draw() {
	wstring temp;
	int length;

	if (mX + pcar[0].length() >= X_max) {
		length = X_max - mX;
		for (int i = 0; i < 4; i++) {
			temp = pcar[i].substr(0, length);
			gotoXY(mX, mY + i);
			wcout << temp;
		}
	}

	if (mX < 0 && mX + pcar[0].length() >= 0) {
		length = mX + pcar[0].length();
		for (int i = 0; i < 4; i++) {
			temp = pcar[i].substr(pcar[0].length() - length, length);
			gotoXY(0, mY + i);
			wcout << temp;
		}
	}

	if (mX >= 0 && mX + pcar[0].length() < X_max) {
		for (int i = 0; i < 4; i++) {
			gotoXY(mX, mY + i);
			wcout << pcar[i];
		}
	}

	clear();
}

void Car::clear() {
	int length = abs(speed);
	int x;

	int flag = mX + pcar[0].length();
	if (flag >= X_max) {
		return;
	}
	
	if (X_max - mX + pcar[0].length()  < length && mX + pcar[0].length() < X_max) {
		length = X_max - mX + pcar[0].length();
	}

	x = mX + pcar[0].length();
	if (x < 0) {
		length += x;
		x = 0;
	}

	for (int i = 0; i < 4; i++) {
		gotoXY(x, mY + i);
		printSpace(length);
	}
}

Car** createCars(int yCar[], int lineCar, int *numCar, int *spdCar) {
	Car** carPtr = new Car*[lineCar];
	for (int i = 0; i < lineCar; i++) {
		carPtr[i] = new Car[numCar[i]];
	}

	for (int i = 0; i < lineCar; i++) {
		int d = (X_max - car[0].length()*numCar[i]) / numCar[i];
		for (int j = 0; j < numCar[i]; j++) {
			int xCar = d / 2 + j * (d + car[0].length());
			carPtr[i][j].set(xCar, yCar[i], spdCar[i]);
		}
	}

	return carPtr;
}