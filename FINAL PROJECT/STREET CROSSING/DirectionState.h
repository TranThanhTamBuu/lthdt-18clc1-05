#pragma once
#include "Console.h"
#include "People.h"


class DirectionState
{
public:
	virtual ~DirectionState() = default;

	virtual void draw(People *const peoplePtr, unsigned int x, unsigned int y, int model) = 0;
	virtual void clear(People *const peoplePtr, unsigned int x, unsigned int y, unsigned int step) = 0;
	virtual DState getCurrentState() = 0;
	void randomColor(const wchar_t &ch) {
		srand(time(NULL));
		int z = rand() % 15 + 1;

		setColor(z, 0);
		wcout << ch;
		setColor(7, 0);
	}
};

