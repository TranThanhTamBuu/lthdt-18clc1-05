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
	Train **Trains;
	People people;

public:
	GAME();
	~GAME();
	void updatePosPeople(char);
	void drawAll();
};

