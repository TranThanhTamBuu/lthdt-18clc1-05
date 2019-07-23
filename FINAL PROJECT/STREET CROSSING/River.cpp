#include "River.h"


River::River() {
	time(&lapse);
}

River::River(int x, int y, int spd) : mX(x), mY(y), speed(spd) {
}

River::~River()
{
}

void River::set(int x, int y, int spd) {
	mX = x;
	mY = y;
	speed = spd;
}

int River::getY() const {
	return mY;
}

void River::setY(int y) {
	mY = y;
}

int River::getX() const {
	return mX;
}

void River::drawWave(int distance) {
	int y = mY + distance;
	if (y < 0 || y > Y_max) {
		return;
	}
	time_t now;
	time(&now);

	if (difftime(now, lapse) > 0.5) {
		gotoXY(0, y);
		setColor(11, 0);
		wcout << "  .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   ";
		gotoXY(0, y + 1);
		setColor(1, 0);
		wcout << "-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'";
	}
	else {
		setColor(1, 0);
		gotoXY(0, y);
		wcout << "  .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   ";
		gotoXY(0, y + 1);
		setColor(11, 0);
		wcout << "-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'   '-'";
	}

	if (difftime(now, lapse) > 1) {
		time(&lapse);
	}
	setColor(7, 0);
}