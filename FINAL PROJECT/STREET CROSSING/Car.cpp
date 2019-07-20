#include "Car.h"

Car::Car()
{
	pcar = car;
}

Car::Car(wstring *pcar, int x, int y, int speed) : Vehicle(x, y, speed) {
	this->pcar = pcar;
}

Car::Car(int x, int y, int speed) : Vehicle(x, y, speed)
{
	if (speed < 0) {
		pcar = car;
		h = 4;
	}
	else {
		pcar = truck;
		h = 5;
	}
}

Car::~Car()
{
	pcar = NULL;
}

int Car::getLength() {
	return pcar[0].length();
}

void Car::setSpd(int spd) {
	speed = spd;
	h = 5;
	int random = rand() % 3;
	if (spd < 0) {
		switch (random) {
		case 0:
			pcar = car;
			break;
		case 1:
			pcar = car_0;
			break;
		case 2:
			pcar = car_1;
			break;
		}
	}
	else {
		switch (random) {
		case 0:
			pcar = truck;
			break;
		case 1:
			pcar = truck_0;
			break;
		case 2:
			pcar = truck_1;
			break;
		}
	}
}

void Car::set(int x, int y) {
	mX = x;
	mY = y;
}

void Car::move(Car &pre, int d) {
	if (speed > 0) {
		clear();
	}
	mX += speed;

	if (speed < 0) {
		int flag = mX + pcar[0].length();
		if (flag < 0) {
			clear();
			int subflag = pre.mX + pre.getLength() - X_max;
			if (subflag <= 0) {
				mX = X_max - 1;
			}
			else {
				mX = X_max - 1 + (pre.mX + pre.getLength() - X_max) + d;
			}
		}
	}
	else {
		if (mX >= X_max) {
			if ((pre.mX < 0) && (pre.mX + pre.getLength() >= 0)) {
				mX = 0 - (0 - pre.mX + d) - pcar[0].length();
			}
			else {
				mX = 0 - pcar[0].length();
			}
		}
	}
}

void Car::draw() {
	wstring temp;
	int length;

	if (speed < 0) {
		if (mX > X_max) {
			return;
		}

		if (mX + pcar[0].length() >= X_max) {
			length = X_max - mX;
			for (int i = 0; i < h; i++) {
				temp = pcar[i].substr(0, length);
				gotoXY(mX, mY + i);
				wcout << temp;
			}
		}

		if (mX < 0 && mX + pcar[0].length() >= 0) {
			length = mX + pcar[0].length();
			for (int i = 0; i < h; i++) {
				temp = pcar[i].substr(pcar[0].length() - length, length);
				gotoXY(0, mY + i);
				wcout << temp;
			}
		}
	}
	else {
		int flag = mX + pcar[0].length();
		if (flag < 0) {
			return;
		}

		if (mX < 0 && mX + pcar[0].length() >= 0) {
			length = mX + pcar[0].length();
			for (int i = 0; i < h; i++) {
				temp = pcar[i].substr(-mX, length);
				gotoXY(0, mY + i);
				wcout << temp;
			}
		}

		if (mX <= X_max && pcar[0].length() + mX >= X_max) {
			length = X_max - mX;
			for (int i = 0; i < h; i++) {
				temp = pcar[i].substr(0, length);
				gotoXY(mX, mY + i);
				wcout << temp;
			}
		}
	}

	if (mX >= 0 && mX + pcar[0].length() < X_max) {
		for (int i = 0; i < h; i++) {
			gotoXY(mX, mY + i);
			wcout << pcar[i];
		}
	}

	if (speed < 0) {
		clear();
	}
}

void Car::clear() {
	if (mY < 0) {
		return;
	}

	int length = abs(speed);
	int x;

	if (speed < 0) {
		int flag = mX + pcar[0].length();
		if (flag >= X_max || mX >= X_max) {
			return;
		}

		if (X_max - mX + pcar[0].length() < length && mX + pcar[0].length() < X_max) {
			length = X_max - mX + pcar[0].length();
		}

		x = mX + pcar[0].length();
		if (x < 0) {
			length += x;
			x = 0;
		}
	}
	else {
		x = mX;
		if (mX < 0 && mX + speed <= 0) {
			return;
		}

		if (mX < 0 && mX + speed > 0) {
			length = mX + speed;
			x = 0;
		}

		if (X_max - mX < length) {
			length = X_max - mX;
		}
	}
	

	for (int i = 0; i < h; i++) {
		gotoXY(x, mY + i);
		printSpace(length);
	}
}

bool Car::isImpact(People &people) {
	int leftX = people.getX();
	int rightX = leftX + Wi;

	if ((mY <= people.getY()) && (people.getY() <= (mY + 4))) {
		if (((mX <= leftX && (leftX <= mX + pcar[0].length())) || (mX <= rightX && rightX <= mX + pcar[0].length()))) {
			return true;
		}
	}

	return false;
}

Car** createCars(int yCar[], int lineCar, int *numCar, int *spdCar, int *&distance) {
	int *totalCarLength = new int[lineCar];
	distance = new int[lineCar];
	Car** carPtr = new Car*[lineCar];
	for (int i = 0; i < lineCar; i++) {
		carPtr[i] = new Car[numCar[i]];
		totalCarLength[i] = 0;
	}

	for (int i = 0; i < lineCar; i++) {
		for (int j = 0; j < numCar[i]; j++) {
			carPtr[i][j].setSpd(spdCar[i]);
			totalCarLength[i] += carPtr[i][j].getLength();
		}
	}

	for (int i = 0; i < lineCar; i++) {
		//int d = (X_max - (numCar[i] - 1)*car[0].length()) / (numCar[i]);
		int d = (X_max - totalCarLength[i] + carPtr[i][0].getLength()) / (numCar[i]);
		distance[i] = d;
		int xCar = (d - carPtr[i][0].getLength()) / 2;
		for (int j = 0; j < numCar[i]; j++) {
			if (j != 0) {
				xCar += d + carPtr[i][j - 1].getLength();
			}
			carPtr[i][j].set(xCar, yCar[i]);
		}
	}

	return carPtr;
}
