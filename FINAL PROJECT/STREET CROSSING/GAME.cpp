#include "GAME.h"


GAME::GAME(int level)
{
	switch (level) {
	case 1: {
		//Car
		lineCar = 2;
		int yCar[] = { 3, 35 };
		numCar = new int[lineCar] { 2, 3 };
		spdCar = new int[lineCar] { -3, -2 };
		Cars = createCars(yCar, lineCar, numCar, spdCar);

		//Train
		lineTrain = 1;
		int yTrain[] = { 18 };
		spdTrain = new int[lineTrain] {5};
		Trains = createTrains(yTrain, lineTrain, spdTrain);

		//.....

		break;
	}
	case 2: {

		break;
	}
	case 3: {

		break;
	}
	case 4: {

		break;
	}
	case 5: {

		break;
	}
	}
}


GAME::~GAME() {
	//Car 
	for (int i = 0; i < lineCar; i++) {
		delete[]Cars[i];
	}
	delete[]Cars;

	//Train
	delete[]Trains;

	//........

}

bool GAME::chooseModel() {
	return people.chooseModel();
}

void GAME::updatePosPeople(char key) {
	switch (key) {
	case 'W': case 'w': {
		people.goUp(STEP);
		people.changeDirectionState(UP);
		break;
	}
	case 'S': case 's': {
		people.goDown(STEP);
		people.changeDirectionState(DOWN);
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

void GAME::updatePosCars() {
	for (int i = 0; i < lineCar; i++) {
		for (int j = 0; j < numCar[i]; j++) {
			Cars[i][j].move();
		}
	}
}

void GAME::updatePosTrains() {
	for (int i = 0; i < lineTrain; i++) {
		Trains[i].move();
	}
}

void GAME::drawAll() {
	// draw people
	people.draw();

	// draw car
	for (int i = 0; i < lineCar; i++) {
		if(Cars[i][0].getY() >=0 && Cars[i][0].getY() < Y_max) {
			for (int j = 0; j < numCar[i]; j++) {
				Cars[i][j].draw();
			}
		}
	}

	// draw train
	for (int i = 0; i < lineTrain; i++) {
		if (Trains[i].getY() >= 0 && Trains[i].getY() < Y_max) {
			Trains[i].draw();
		}
	}

	// draw lane, river
}

void GAME::screenScroll() {
	clrscr();

	for (int i = 0; i <= 5; i++) {
		gotoXY(0, 0 + 8*i);	printLine(WIDTH);
	}



}

