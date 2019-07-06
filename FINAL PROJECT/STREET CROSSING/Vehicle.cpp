#include "Vehicle.h"


Vehicle::Vehicle() {
}

Vehicle::Vehicle(int x, int y)
{
	mX = x;
	mY = y;
}

Vehicle::~Vehicle()
{
}

void Vehicle::set(int x, int y) {
	mX = x;
	mY = y;
}