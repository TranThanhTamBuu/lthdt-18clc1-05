#pragma once
#include "DirectionState.h"


class Down : public DirectionState {
public:
	Down() = default;
	virtual ~Down() = default;

	virtual void draw(People *const peoplePtr, unsigned int x, unsigned int y, int model) override;
	virtual void clear(People *const peoplePtr, unsigned int x, unsigned int y, unsigned int step) override;
	virtual DState getCurrentState() override;
};

