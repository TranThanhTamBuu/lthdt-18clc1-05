#include "Train.h"

Train::Train() {
	ptrain = train;
}

Train::Train(int x, int y, int speed) : Vehicle(x, y, speed)
{
	ptrain = train;
}

Train::~Train()
{
	ptrain = NULL;
}

void Train::move() {
	clear();
	mX += speed;

	if (mX >= X_max) {
		mX = 0 - ptrain[0].length();
	}
}

void Train::draw() {
	wstring temp;
	int length;

	if (mX < 0 && mX + ptrain[0].length() >= 0 && mX + ptrain[0].length() <= X_max) {
		length = mX + ptrain[0].length();
		for (int i = 0; i < 5; i++) {
			temp = ptrain[i].substr(-mX - 1, length);
			gotoXY(0, mY + i);
			wcout << temp;
		}
	}

	if (mX >= 0 && mX <= X_max && ptrain[0].length() + mX >= X_max) {
		length = X_max - mX;
		for (int i = 0; i < 5; i++) {
			temp = ptrain[i].substr(0, length);
			gotoXY(mX, mY + i);
			wcout << temp;
		}
	}

	if (mX < 0 && mX + ptrain[0].length() > X_max) {
		length = X_max;
		for (int i = 0; i < 5; i++) {
			temp = ptrain[i].substr(-mX - 1, length);
			gotoXY(0, mY + i);
			wcout << temp;
		}
	}
}

void Train::clear() {
	int length = speed;
	int x = mX;
	if (mX <0 && mX + speed <= 0) {
		return;
	}

	if (mX < 0 && mX + speed > 0) {
		length = mX + speed;
		x = 0;
	}

	if (X_max - mX < length) {
		length = X_max - mX;
	}

	for (int i = 0; i < 5; i++) {
		gotoXY(x, mY + i);
		printSpace(length);
	}
}

bool Train::isImpact(People &people) {
	int leftX = people.getX();
	int rightX = leftX + Wi;

	if ((mY <= people.getY()) && (people.getY() <= (mY + 5))) {
		if (((mX <= leftX && leftX <= mX + train[0].length()) || (mX <= rightX && rightX <= mX + train[0].length()))) {
			return true;
		}
	}

	return false;
}

Train *createTrains(int yTrain[], int lineTrain, int *spdTrain) {
	Train *trainPtr = new Train[lineTrain];
	for (int i = 0; i < lineTrain; i++) {
		trainPtr[i].set(X_max, yTrain[i], spdTrain[i]);
	}
	return trainPtr;
}