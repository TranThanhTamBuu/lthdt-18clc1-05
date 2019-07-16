#pragma once
#include "People.h"
#include "Car.h"
#include "Train.h"
#include "Wood.h"
#include <vector>
#include "Console.h"

class GAME
{
private:
	Car **Cars;
	int lineCar, *numCar, *spdCar;
	Train *Trains;
	int lineTrain, *spdTrain;
	People people;
	Wood **Woods;
	int lineWood, *numWood, *spdWood;

public:
	GAME(int level);
	~GAME();
	bool chooseModel();
	void updatePosPeople(char);
	void updatePosTrains();
	void updatePosCars();
	void updatePosWoods();
	bool impactVehicle();
	int impactWoods(); //0: not same line wood | 1: on wood | -1: in river
	int sameLineWoods();
	void onWood();
	void drawAll();
	bool isEndScr();
	void screenScroll();
	vector <int> xLineWood();
};




