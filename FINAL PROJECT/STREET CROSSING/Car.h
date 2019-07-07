#pragma once
#include "Vehicle.h"

static wstring car[4] = {
	L"      .---;-,     ",
	L"   __/_,{)|__;._  ",
	L".*` _     :  _  `.",
	L"'--(_)------(_)--'",
};

class Car : public Vehicle
{
private:
	wstring *pcar;

public:
	Car();
	Car(int x, int y);
	~Car();
	void move(int step); // step < 0 
	void draw();
	//void clear();
};

Car** createCars(int yCar[], int lineCar, int *numCar);
