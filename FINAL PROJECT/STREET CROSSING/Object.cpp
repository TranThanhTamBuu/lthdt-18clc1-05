#include "Object.h"


Object::Object()
	: x(70), y(20) {
}

Object::~Object()
{
}

int Object::getXC() {
	return x;
}

int Object::getYC() {
	return y;
}

void Object::setXC(int _x) {
	x = _x;
}

void Object::setYC(int _y) {
	y = _y;
}