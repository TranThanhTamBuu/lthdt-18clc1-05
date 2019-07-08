#pragma once
#include "DirectionState.h"

class Right: public DirectionState {
public:
	Right() = default;
	virtual ~Right() = default;

	virtual void draw(People *const peoplePtr, unsigned int x, unsigned int y, int model) override;
	virtual void clear(People *const peoplePtr, unsigned int x, unsigned int y, unsigned int step) override;
	virtual DState getCurrentState() override;
};

