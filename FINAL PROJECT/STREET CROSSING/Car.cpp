#include "Car.h"

Car::Car() 
{
	pcar = car;
}

Car::Car(int x, int y) : Vehicle(x, y)
{
	pcar = car;
}

Car::~Car()
{
	pcar = NULL;
}

void Car::move(int step) {
	mX += step;

	int flag = mX + pcar[0].length();
	if (flag < 0) {
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
}

/*void Car::clear() {
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
		gotoXY((mX<0)? 0:mX, mY + i);
		printSpace(length);
	}
}*/

Car** createCars(int yCar[], int lineCar, int *numCar) {
	Car** carPtr = new Car*[lineCar];
	for (int i = 0; i < lineCar; i++) {
		carPtr[i] = new Car[numCar[i]];
	}

	for (int i = 0; i < lineCar; i++) {
		int d = (X_max - car[0].length()*numCar[i]) / numCar[i];
		for (int j = 0; j < numCar[i]; j++) {
			int xCar = d / 2 + j * (d + car[0].length());
			carPtr[i][j].set(xCar, yCar[i]);
		}
	}

	return carPtr;
}