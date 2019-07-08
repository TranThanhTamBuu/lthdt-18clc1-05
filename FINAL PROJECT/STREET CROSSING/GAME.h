#pragma once
#include "People.h"
#include "Car.h"
#include "Train.h"
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

public:
	GAME(int level);
	~GAME();
	void updatePosPeople(char);
	void updatePosTrains();
	void updatePosCars();
	void drawAll();
};



