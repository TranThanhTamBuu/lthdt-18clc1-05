#pragma once
#include "DirectionState.h"


class Stay: public DirectionState {
public:
	Stay() = default;
	virtual ~Stay() = default;

	virtual void draw(People *const peoplePtr, unsigned int x, unsigned int y, int model) override;
	virtual DState getCurrentState() override;
};

