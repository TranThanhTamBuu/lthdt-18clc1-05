#pragma once
#include "DirectionState.h"


class Up: public DirectionState {
public:
	Up() = default;
	virtual ~Up() = default;

	virtual void draw(People *const peoplePtr, unsigned x, unsigned y, int model) override;
	virtual void clear(People *const peoplePtr, unsigned x, unsigned y) override;
	virtual DState getCurrentState() override;
};
