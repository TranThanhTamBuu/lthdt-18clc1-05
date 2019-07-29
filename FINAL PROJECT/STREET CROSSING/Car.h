#pragma once
#include "Vehicle.h"

static wstring car[5] = {
	L"                  ",
	L"      .---;-,     ",
	L"   __/_,{)|__;._  ",
	L".*` _     :  _  `.",
	L"'--(o)------(o)--'",
};

static wstring car_0[5] = {
	L"   ____________________________ ",
	L"  /    | |     |     |     |   |",
	L" /____ |_|_____|_____|_____|___|",
	L"[___.=._______________.====.___|",
	L"'--'(o)'-------------'(o)(o)'--'",
};

static wstring car_1[5] = {
	L"           ",
	L"    _      ",
	L"  D/_      ",
	L"  /(_`._,-.",
	L"(o) `--'(o)",
};

static wstring truck_0[5] = {
	L" _,..=xxxxxxxxxxxx,    ",
	L"/L_Y.-“”“”“”“””`,--n.  ",
	L"|--'[=======]|L]J: []\\ ",
	L"|/ _ ''_ “ ” ||[ -_ 4 |",
	L"'-(o)-(o)----'v'-(o)--'",
};

static wstring truck[5] = {
	L" _______________________         ",
	L"|                       |h_ __   ",
	L"|                       ||=|##L_ ",
	L"|_.====._________.====._||_|_.=.]",
	L" '(o)(o)'       '(o)(o)'””='=(o) ",
};

static wstring truck_1[5] = {
	L"                 ",
	L".--------.__     ",
	L"|::::::::|[_I___,",
	L"|_.=.____I__.-~;|",
	L" '(o)'------'(o)'",
};

static wstring ambulance[7] = {
	L"                 \\|/         ",
	L"     _____________[\\_        ",
	L"    /  _|_    .--..--\\       ",
	L"    |)  |     [__][___\\___   ",
	L"    |        |   -|-   __ `\\ ",
	L"  _(  .----. |    |   /  \\ [)",
	L"  `'---\\__/-----------\\__/--'",
};


class Car : public Vehicle
{
private:
	wstring *pcar;
	int h;

public:
	Car();
	Car(wstring *pcar, int x, int y, int speed);
	Car(int x, int y, int speed);
	~Car();
	void setSpd(int spd);
	void set(int x, int y);
	int getLength();
	void move(Car &pre, int d);
	void moveLose();
	void movelevel();
	void draw();
	void clear();
	bool isImpact(People &people);
};

Car** createCars(int yCar[], int lineCar, int *numCar, int *spdCar, int *&distance);

