#pragma once
#include "Vehicle.h"

static wstring car[4] = {
	L"      .---;-,     ",
	L"   __/_,{)|__;._  ",
	L".*` _     :  _  `.",
	L"'--(_)------(_)--'",
};

static wstring truck[5] = {
	L" _______________________         ",
	L"|                       |h_ __   ",
	L"|                       ||=|##L_ ",
	L"|_.====._________.====._||_|_.=.]",
	L" '(_)(_)'       '(_)(_)'””='=(_) ",
};

class Car : public Vehicle
{
private:
	wstring *pcar;
	int h;
	// speed < 0 

public:
	Car();
	Car(wstring *pcar, int x, int y, int speed);
	Car(int x, int y, int speed);
	~Car();
	void set(int x, int y, int spd);
	void move(); 
	void draw();
	void clear();
	bool isImpact(People &people);
};

Car** createCars(int yCar[], int lineCar, int *numCar, int *spdCar);

