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

		// Coin
		/*nCoin = 25;
		vector<int> countNCoin_temp(1, 0);
		countNCoin = countNCoin_temp;
		createCoins();*/

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
	if (key == 224) {
		key = _getch();
	}

	switch (key) {
	case 'W': case 'w': case 72: {
		if (sameLineWoods() != -1) {
			people.clearImage();
			people.goUp(STEPUPDOWN - 1);
		}
		else {
			people.goUp(STEPUPDOWN);
		}
		people.changeDirectionState(UP);
		break;
	}
	case 'S': case 's': case 80: {
		if (sameLineWoods() != -1) {
			people.clearImage();
			people.goDown(STEPUPDOWN + 1);	
		}
		else {
			people.goDown(STEPUPDOWN);
		}
		people.changeDirectionState(DOWN);
		break;
	}
	case 'D': case 'd': case 77: {
		people.goRight(STEPRIGHTLEFT);
		people.changeDirectionState(RIGHT);
		break;
	}
	case 'A': case 'a': case 75: {
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

void GAME::updatePosCoinOnWoods() {
	
}

bool GAME::impactVehicle() {
	//Ham isImpact() cua vehicle chi kiem tra khi people va vehicle da o cung line

	//Car
	for (int i = 0; i < lineCar; i++) {
		if ((Cars[i][0].getY() <= people.getY()) && (people.getY() <= (Cars[i][0].getY() + 4))) {
			for (int j = 0; j < numCar[i]; j++) {
				if (Cars[i][j].isImpact(people)) {
					return true;
				}
			}
		}
	}

	//Train
	for (int i = 0; i < lineTrain; i++) {
		if (Trains[i].isImpact(people)) {
			return true;
		}
	}

	return false;
}

int GAME::sameLineWoods() {
	for (int i = 0; i < lineWood; i++) {
		if ((Woods[i][0].getY() - 4 <= people.getY()) && (people.getY() <= (Woods[i][0].getY() + 4))) {
			return i;
		}
	}
	return -1;
}

int GAME::impactWoods() {
	int line = sameLineWoods();

	if (line == -1) {
		return 0;
	}
	
	for (int j = 0; j < numWood[line]; j++) {
		if (Woods[line][j].isImpact(people)) {
			return 1;
		}
	}

	return -1;
}

void GAME::drawAll() {

	// draw people
	people.draw();
	if (sameLineWoods() != -1) {
		people.clearImage();
	}

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

	// draw coin
	/*for (int i = 0; i < coins.size(); ++i) {
		coins[i].draw();
	}*/

	// draw coinsOnWood
<<<<<<< HEAD
	for (int i = 0; i < lineWood; ++i) {
		for (int j = 0; j < coinsOnWood[i].size(); ++j) {
			coinsOnWood[i][j].moveOnRiver(-1, Woods[i][(coinsOnWood[i][j].getiX())]); 
			coinsOnWood[i][j].drawMove(-1);
		}
	}
=======

	/*for (int i = 0; i < coinsOnWood.size(); ++i) {
		coinsOnWood[i].move(-1);
		coinsOnWood[i].drawMove(-1);
	}*/
>>>>>>> 4df2df04ab3e450fd1832de559f1710e71deaea7
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

	if (people.getY() >= 19) return;

	if (sameLineWoods() != -1 && people.getY() >= 19) return;

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

	// Coin
	/*for (int i = 0; i < coins.size(); ++i) {
		coins[i].setYC(coins[i].getYC() + 8);
	}*/

	// coinOnWood
<<<<<<< HEAD
	for (int i = 0; i < lineWood; ++i) {
		for (int j = 0; j < coinsOnWood[i].size(); ++j) {
			coinsOnWood[i][j].setYC(coinsOnWood[i][j].getYC() + 8);
		}
	}
=======
	/*for (int i = 0; i < coinsOnWood.size(); ++i) {
		coinsOnWood[i].setYC(coinsOnWood[i].getYC() + 8);
	}*/

>>>>>>> 4df2df04ab3e450fd1832de559f1710e71deaea7
}

void GAME::peopleOnWood() {
	people.setYC(Woods[sameLineWoods()][0].getY());
	people.goLeft(abs(spdWood[sameLineWoods()]));
	people.draw();
}

void GAME::createCoins() {
	unsigned totalLine = lineCar + lineTrain + lineWood,
		randLine;
	int randX, randY;

	vector<int> sampleYWood = { 4 };
	vector<vector<int>> sampleXWood;
	for (int i = 0; i < lineWood; ++i) {
		sampleXWood.push_back(xLineWoods(i));
	}
	vector<vector<int>> sampleXWood_temp = sampleXWood;

	for (int i = 0; i < lineWood; ++i) {
		int xWoodSize = sampleXWood[i].size();
		for (int j = 0; j < xWoodSize; ++j) {
			sampleXWood[i].push_back(sampleXWood[i][j] + 6);
			sampleXWood[i].push_back(sampleXWood[i][j] - 6);
		}
	}

	for (int i = 0; i < nCoin; ++i) {
		randLine = rand() % 3;
		switch (randLine) {
		//case 0: case 2: {	// Line car, train
		//	vector<int> sampleY = { 29,-11,13 };
		//	randY = sampleY[rand() % sampleY.size()];
		//	randX = ((rand() % (X_max - 2)) + 2);

		//	coins.push_back(Coin(randX, randY, LEFT));
		//	break;
		//}

		case 1: {	// Line wood
			int iY = rand() % sampleYWood.size();
			if (countNCoin[iY] > 3) {
				--i;
			}
			else {
				randY = sampleYWood[iY];
				int iX = rand() % (sampleXWood[iY].size());
				randX = sampleXWood[iY][iX];
				sampleXWood[iY].erase(sampleXWood[iY].begin() + iX);
				sampleXWood[iY].shrink_to_fit();

				coinsOnWood[iY].push_back(Coin(randX - 1, randY, LEFT, iY));
				// Count nCoin on one line
				++countNCoin[iY];
				break;
			}
		}
		}
	}

	for (int i = 0; i < lineWood; ++i) {
		for (int j = 0; j < coinsOnWood[i].size(); ++j) {
			for (int k = 0; k < numWood[i]; ++k) {
				if (coinsOnWood[i][j].getXC() == sampleXWood_temp[i][k]
					|| coinsOnWood[i][j].getXC() == sampleXWood_temp[i][k] - 6
					|| coinsOnWood[i][j].getXC() == sampleXWood_temp[i][k] + 6) {
					coinsOnWood[i][j].setiX(k);
					break;
				}
			}
		}
	}
}

void GAME::handleCoinImpact() {
	// People impact
	for (int i = 0; i < coins.size(); ++i) {
		if (coins[i].isImpact(people.getXC(), people.getYC())) {
			people.changeMoney(COINVALUE);
			coins[i].clearImage();
			coins.erase(coins.begin() + i);
			coins.shrink_to_fit();
			--i;
		}
	}

	for (int i = 0; i < lineWood; ++i) {
		for (int j = 0; j < coinsOnWood[i].size(); ++j) {
			if (coinsOnWood[i][j].isImpact(people.getXC(), people.getYC())) {
				people.changeMoney(COINVALUE);
				coinsOnWood[i][j].clearImage();
				--countNCoin[coinsOnWood[i][j].getiY()];
				coinsOnWood[i].erase(coinsOnWood[i].begin() + i);
				coinsOnWood[i].shrink_to_fit();
				--i;
			}
		}
	}

	// Reach edge when on wood
}

vector <int> GAME::xLineWoods(int line) {
	vector <int> result;

	for (int i = 0; i < numWood[line]; i++) {
		int x = Woods[line][i].getX() + 12;
		result.push_back(x);
	}

	return result;
}
