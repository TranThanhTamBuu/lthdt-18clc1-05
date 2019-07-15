#include "GAME.h"


GAME::GAME(int level)
{
	switch (level) {
	case 1: {
		//Car
		lineCar = 2;
		int yCar[] = { 27, -13 };
		numCar = new int[lineCar] { 2, 3 };
		spdCar = new int[lineCar] { -3, -2 };
		Cars = createCars(yCar, lineCar, numCar, spdCar);

		//Train
		lineTrain = 1;
		int yTrain[] = { 10 };
		spdTrain = new int[lineTrain] {5};
		Trains = createTrains(yTrain, lineTrain, spdTrain);

		//Wood
		lineWood = 1;
		int yWood[] = { 4 };
		numWood = new int [lineWood] { 4 };
		spdWood = new int [lineWood] { -1 };
		Woods = createWoods(yWood, lineWood, numWood, spdWood);

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

	//Wood
	for (int i = 0; i < lineWood; i++) {
		delete[]Woods[i];
	}
	delete[]Woods;

}

bool GAME::chooseModel() {
	return people.chooseModel();
}

void GAME::updatePosPeople(char key) {
	switch (key) {
	case 'W': case 'w': {
		people.goUp(STEPUPDOWN);
		people.changeDirectionState(UP);
		break;
	}
	case 'S': case 's': {
		people.goDown(STEPUPDOWN);
		people.changeDirectionState(DOWN);
		break;
	}
	case 'D': case 'd': {
		people.goRight(STEPRIGHTLEFT);
		people.changeDirectionState(RIGHT);
		break;
	}
	case 'A': case 'a': {
		people.goLeft(STEPRIGHTLEFT);
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

void GAME::updatePosWoods() {
	for (int i = 0; i < lineWood; i++) {
		for (int j = 0; j < numWood[i]; j++) {
			Woods[i][j].move();
		}
	}
}

void GAME::drawAll() {
	//draw line
	for (int i = 0; i <= 5; i++) {
		gotoXY(0, 0 + 8 * i);	printLine(WIDTH);
	}

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

	// draw wood
	for (int i = 0; i < lineWood; i++) {
		if (Woods[i][0].getY() >= 0 && Woods[i][0].getY() < Y_max) {
			for (int j = 0; j < numWood[i]; j++) {
				Woods[i][j].draw();
			}
		}
	}
}

bool GAME::isEndScr() {
	int count = 0;
	
	//Car
	for (int i = 0; i < lineCar; i++) {
		if (Cars[i][0].getY() < 8) {
			count++;
		}
	}

	//Train
	for (int i = 0; i < lineTrain; i++) {
		if (Trains[i].getY() < 8) {
			count++;
		}
	}

	//Wood
	for (int i = 0; i < lineWood; i++) {
		if (Woods[i][0].getY() < 8) {
			count++;
		}
	}

	return (count == 0);
}

void GAME::screenScroll() {
	if (isEndScr() && (people.getY() <= 12)) return;

	if (people.getY() >= 20) return;

	people.setY(20);

	clrscr();

	for (int i = 0; i <= 5; i++) {
		gotoXY(0, 0 + 8*i);	printLine(WIDTH);
	}

	//Car
	for (int i = 0; i < lineCar; i++) {
		for (int j = 0; j < numCar[i]; j++) {
			Cars[i][j].setY(Cars[i][j].getY() + 8);
		}
	}

	//Train
	for (int i = 0; i < lineTrain; i++) {
		Trains[i].setY(Trains[i].getY() + 8);
	}

	//Wood
	for (int i = 0; i < lineWood; i++) {
		for (int j = 0; j < numWood[i]; j++) {
			Woods[i][j].setY(Woods[i][j].getY() + 8);
		}
	}

}

