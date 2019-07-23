#pragma once
#include "Vehicle.h"
#define TRF_GREEN 0
#define TRF_YELLOW 1
#define TRF_RED 2

static wstring train[5] = {
	L"                  _________                                              _____                  _________                                              _____       . . . . . o o o o o o O O O O     ",
	L"  ___=====__T__  |         |     _____     _______________ ___________ __|[_]|___ ___________  |         |     _____     _______________ ___________ __|[_]|___ ___________ _______    ____      o   ",
	L" _|   |_|     |  |_________|  __||___||__  |   | .x. |   | [] [] [] [] |[] [] []| [] [] [] []  |_________|  __||___||__  |   | .x. |   | [] [] [] [] |[] [] []| [] [] [] [] [_____(__  ][]]_n_n__][. ",
	L"|_|___________|_|_00______Y__|___________|_|___|_x.x_|___|_[_________]_|________|_[_________]_|_00______Y__|___________|_|___|_x.x_|___|_[_________]_|________|_[_________]_[________]_|__|________)<",
	L"   oo       oo ' oo      oo '  oo      oo ' oo         oo ' oo     oo ' oo    oo ' oo     oo ' oo      oo '  oo      oo ' oo         oo ' oo     oo ' oo    oo ' oo     oo ' oo    oo 'oo 0000---ooz_",
};

static wstring trafficlight[1] = {
	L"--|_[#]_[#]_[#]_|--",
};

class Train : public Vehicle
{
private:
	wstring *ptrain;
	time_t start;
	time_t end;
	wstring *traffic;
	bool stop;
	int coreSpd;
	int mode; // 0: normal 1:crazy
	// speed > 2 && step%2 == 0

public:
	Train();
	Train(int x, int y, int speed, int mode);
	~Train();
	void set(int x, int y, int spd, int mode);
	void move();
	void draw();
	void clear();
	bool isImpact(People &people);
	void drawTraffic(int color);
	int updateTraffic();
};

Train *createTrains(int yTrain[], int lineTrain, int *spdTrain, int *modeTrain);

