#include "Train.h"

Train::Train() {
	ptrain = train;
	traffic = trafficlight;
	time(&start);
	stop = false;
}

Train::Train(int x, int y, int speed, int mode) : Vehicle(x, y, speed), mode(mode), coreSpd(speed)
{
	ptrain = train;
	traffic = trafficlight;

}

Train::~Train()
{
	ptrain = NULL;
	traffic = NULL;
}

void Train::move() {
	int flag = updateTraffic();

	if (mode == 0) {
		speed = coreSpd;

		switch (flag) {
		case TRF_GREEN:
			speed = speed;
			break;
		case TRF_YELLOW:
			speed /= 2;
			break;
		case TRF_RED:
			speed = 0;
			break;
		}

		if (!stop) {
			clear();
		}
	}
	else {
		stop = false;
		speed = coreSpd;

		switch (flag) {
		case TRF_GREEN:
			speed = speed;
			break;
		case TRF_YELLOW:
			speed *= 1.5;
			break;
		case TRF_RED:
			speed *= 2;
			break;
		}

		clear();
	}

	mX += speed;

	if (mX >= X_max) {
		mX = 0 - ptrain[0].length();
	}
}

void Train::draw() {
	/*if (stop) {
		return;
	}*/

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
	if (mY < 0) {
		return;
	}

	int length = speed;
	int x = mX;
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

	for (int i = 0; i < 5; i++) {
		gotoXY(x, mY + i);
		printSpace(length);
	}
}

bool Train::isImpact(People &people) {
	int leftX = people.getX();
	int rightX = leftX + Wi - 1;
	int flag = mX + train[0].length() - 1;

	if ((mY <= people.getY()) && (people.getY() <= (mY + 5))) {
		if ((((mX <= leftX) && (leftX <= flag)) || ((mX <= rightX) && (rightX <= flag)))) {
			return true;
		}
	}

	return false;
}

void Train::set(int x, int y, int spd, int mode) {
	Vehicle::set(x, y, spd);
	coreSpd = spd;
	this->mode = mode;
}

Train *createTrains(int yTrain[], int lineTrain, int *spdTrain, int *modeTrain) {
	Train *trainPtr = new Train[lineTrain];
	for (int i = 0; i < lineTrain; i++) {
		trainPtr[i].set(X_max, yTrain[i], spdTrain[i], modeTrain[i]);
	}
	return trainPtr;
}

void Train::drawTraffic(int color) {
	if (mY < 0 || mY > Y_max) {
		return;
	}

	gotoXY((X_max - traffic[0].length()) / 2 - 1, mY - 1);
	for (int i = 0; i < traffic[0].length(); i++) {
		if (traffic[0][i] == '[' || traffic[0][i] == '#' || traffic[0][i] == ']') {
			setColor(color, 0);
			wcout << traffic[0][i];
			setColor(7, 0);
		}
		else {
			wcout << traffic[0][i];
		}
	}
}

int Train::updateTraffic() {
	time(&end);
	double diff = difftime(end, start);

	if (diff > 15) {
		time(&start);
		time(&end);
		diff = difftime(end, start);
	}

	if (diff <= 5) {
		if (mY >= 0) {
			drawTraffic(10); // Green
		}
		stop = false;
		return TRF_GREEN;
	}

	if (diff <= 10) {
		if (mY >= 0) {
			drawTraffic(14); // Yellow
		}
		stop = false;
		return TRF_YELLOW;
	}

	if (diff <= 15) {
		if (mY >= 0) {
			drawTraffic(12); // Red
		}
		stop = true;
		return TRF_RED;
	}
}
