#include "River.h"


River::River(){
}

River::River(int x, int y, int spd) : mX(x), mY(y), speed(spd) {}

River::~River()
{
}

void River::set(int x, int y, int spd) {
	mX = x;
	mY = y;
	speed = spd;
}

int River::getY() {
	return mY;
}

void River::setY(int y) {
	mY = y;
}