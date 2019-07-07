#pragma once
#include "Vehicle.h"

static wstring train[5] = {
	L"                  _________                                              _____                 . . . . . o o o o o     ",
	L"  ___=====__T__  |         |     _____     _______________ ___________ __|[_]|___ ___________ _______    ____      o   ",
	L" _|   |_|     |  |_________|  __||___||__  |   | .x. |   | [] [] [] [] |[] [] []| [] [] [] [] [_____(__  ][]]_n_n__][. ",
	L"|_|___________|_|_00______Y__|___________|_|___|_x.x_|___|_[_________]_|________|_[_________]_[________]_|__|________)<",
	L"   oo       oo ' oo       oo ' oo      oo ' oo         oo ' oo     oo ' oo    oo ' oo     oo ' oo    oo 'oo 0000---ooz_",
};

class Train : public Vehicle
{
private:
	wstring *ptrain;

public:
	Train();
	Train(int x, int y);
	~Train();
	void move(int step); //step > 0
	void draw();
	//void clear();
};

Train *createTrains(int yTrain[], int lineTrain);
