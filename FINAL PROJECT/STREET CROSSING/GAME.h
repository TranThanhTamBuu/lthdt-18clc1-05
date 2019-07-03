#pragma once
#include "People.h"
#include "Car.h"
#include "Train.h"

class GAME
{
private:
	Car *Cars;
	Train *Trains;
	People people;

public:
	GAME();
	~GAME();
};

