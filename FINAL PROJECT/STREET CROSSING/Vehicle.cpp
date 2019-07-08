#include "Vehicle.h"


Vehicle::Vehicle() {
}

Vehicle::Vehicle(int x, int y, int spd) : mX(x), mY(y), speed(spd) {}

Vehicle::~Vehicle()
{
}

void Vehicle::set(int x, int y, int spd) {
	mX = x;
	mY = y;
	speed = spd;
}