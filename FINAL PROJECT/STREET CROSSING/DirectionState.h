#pragma once
#include "Console.h"
#include "People.h"


class DirectionState
{
public:
	virtual ~DirectionState() = default;

	virtual void draw(People *const peoplePtr, unsigned x, unsigned y, int model) = 0;
	virtual void clear(People *const peoplePtr, unsigned x, unsigned y) = 0;
	virtual DState getCurrentState() = 0;
};
