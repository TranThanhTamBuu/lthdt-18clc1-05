#pragma once
#include "DirectionState.h"


class Up: public DirectionState {
public:
	Up() = default;
	virtual ~Up() = default;

	virtual void draw(People *const peoplePtr, unsigned int x, unsigned int y, int model) override;
	virtual void clear(People *const peoplePtr, unsigned int x, unsigned int y, unsigned int step) override;
	virtual DState getCurrentState() override;
};

