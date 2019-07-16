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
	// speed < 0 

public:
	Car();
	Car(int x, int y, int speed);
	~Car();
	void move(); 
	void draw();
	void clear();
	bool isImpact(People &people);
};

Car** createCars(int yCar[], int lineCar, int *numCar, int *spdCar);

