#include "Train.h"

Train::Train() {
	ptrain = train;
}

Train::Train(int x, int y) : Vehicle(x,y)
{
	ptrain = train;
}

Train::~Train()
{
	ptrain = NULL;
}

void Train::move(int step) {
	mX += step;

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
		length = X_max - 1;
		for (int i = 0; i < 5; i++) {
			temp = ptrain[i].substr(-mX - 1, length);
			gotoXY(0, mY + i);
			wcout << temp;
		}
	}
}

/*void Train::clear() {
	int length;
	int test = ptrain[0].length();

	if (mX <= 0 && mX + ptrain[0].length() >= 0) {
		length = mX + ptrain[0].length();
	}

	if (mX <= X_max && ptrain[0].length() + mX >= X_max) {
		length = X_max - mX;
	}

	if (mX > 0 && mX + ptrain[0].length() < X_max) {
		length = ptrain[0].length();
	}

	for (int i = 0; i < 5; i++) {
		gotoXY(mX, mY + i);
		printSpace(length);
	}
}*/

Train *createTrains(int yTrain[], int lineTrain) {
	Train *trainPtr = new Train[lineTrain];
	for (int i = 0; i < lineTrain; i++) {
		trainPtr[i].set(X_max, yTrain[i]);
	}
	return trainPtr;
}