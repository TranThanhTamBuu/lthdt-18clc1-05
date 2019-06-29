#pragma once
#include "Vehicle.h"

static string car[4] = {
	"       .---;-,      ",
	"    __/_,{)|__;._   ",
	" .*` _     :  _  `. " ,
	" '--(_)------(_)--' ",
};

class Car : public Vehicle
{
private:
	string *pcar;

public:
	Car(int x, int y);
	~Car();
	void move(int step); // step < 0 
	void clear();
};

