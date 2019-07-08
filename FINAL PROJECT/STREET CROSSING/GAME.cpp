#include "GAME.h"


GAME::GAME(int level)
{
	switch (level) {
	case 1: {
		//Car
		lineCar = 2;
		int yCar[] = { 0, 11 };
		numCar = new int[lineCar]{ 2,3 };
		spdCar = new int[lineCar]{ -3,-2 };
		Cars = createCars(yCar, lineCar, numCar);
		
		//Train
		lineTrain = 1;
		int yTrain[] = { 5 };
		spdTrain = new int[lineTrain] {5};
		Trains = createTrains(yTrain, lineTrain);
		
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


GAME::~GAME(){
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
			Cars[i][j].move(spdCar[i]);
		}
	}
}

void GAME::updatePosTrains() {
	for (int i = 0; i < lineTrain; i++) {
		Trains[i].move(spdTrain[i]);
	}
}

void GAME::drawAll() {
	// draw people
	people.draw();

	// draw car
	for (int i = 0; i < lineCar; i++) {
		for (int j = 0; j < numCar[i]; j++) {
			Cars[i][j].draw();
		}
	}

	// draw train
	for (int i = 0; i < lineTrain; i++) {
		Trains[i].draw();
	}

	// draw lane, river
}


