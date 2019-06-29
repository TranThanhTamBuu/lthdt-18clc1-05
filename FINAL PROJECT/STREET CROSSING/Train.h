#pragma once
#include "Vehicle.h"

static string train[5] = {
	"                  _________                                              _____                 . . . . . o o o o o      ",
	"  ___=====__T__  |         |     _____     _______________ ___________ __|[_]|___ ___________ _______    ____      o    ",
	" _|   |_|     |  |_________|  __||___||__  |   | .x. |   | [] [] [] [] |[] [] []| [] [] [] [] [_____(__  ][]]_n_n__][.  ",
	"|_|___________|_|_00______Y__|___________|_|___|_x.x_|___|_[_________]_|________|_[_________]_[________]_|__|________)< ",
	"   oo       oo ' oo       oo ' oo      oo ' oo         oo ' oo     oo ' oo    oo ' oo     oo ' oo    oo 'oo 0000---ooz_ ",
};

class Train : public Vehicle
{
private:
	string *ptrain;

public:
	Train(int x, int y);
	~Train();
	void move(int step); //step > 0
	void clear();
};

