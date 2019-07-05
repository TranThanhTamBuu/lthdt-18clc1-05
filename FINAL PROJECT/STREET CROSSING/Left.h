#pragma once
#include "DirectionState.h"


class Left: public DirectionState {
public:
	Left() = default;
	virtual ~Left() = default;

	virtual void draw(People *const peoplePtr, unsigned int x, unsigned int y, int model) override;
	virtual DState getCurrentState() override;
};

