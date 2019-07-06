#include "GAME.h"
#define STEP 1


GAME::GAME()
{
}


GAME::~GAME()
{
}

void GAME::updatePosPeople(char key) {
	switch (key) {
	case 'W': case 'w': {
		people.goUp(STEP);
		people.changeDirectionState(STAY);
		break;
	}
	case 'S': case 's': {
		people.goDown(STEP);
		people.changeDirectionState(STAY);
		break;
	}
	case 'D': case 'd': {
		people.goRight(STEP);
		people.changeDirectionState(RIGHT);
		break;
	}
	case 'A': case 'a': {
		people.goLeft(STEP);
		people.changeDirectionState(LEFT);
		break;
	}
	}
}

void GAME::drawAll() {
	people.draw();
	// draw car
	// draw train
	// draw lane, river
}


