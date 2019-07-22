#include "GAME.h"


GAME::GAME(int level)
{
	switch (level) {
	case 1: {
		//Car
		lineCar = 2;
		int yCar[] = { -14, 26 };
		numCar = new int[lineCar] { 4, 4 };
		spdCar = new int[lineCar] { -1, 1 };
		Cars = createCars(yCar, lineCar, numCar, spdCar, distance);

		//Train
		lineTrain = 2;
		int yTrain[] = { 10, - 30 };
		spdTrain = new int[lineTrain] { 6, 6 };
		modeTrain = new int[lineTrain] { 0, 1 };
		Trains = createTrains(yTrain, lineTrain, spdTrain, modeTrain);

		//Wood
		lineWood = 1;
		int yWood[] = { -4 };
		numWood = new int [lineWood] { 4 };
		spdWood = new int [lineWood] { 1 };
		Woods = createWoods(yWood, lineWood, numWood, spdWood);

		// Coin
		nCoin = 5;
		vector<int> countNCoin_temp(1, 0);
		countNCoin = countNCoin_temp;
		for (int i = 0; i < lineWood; ++i) {
			vector<Coin> temp;
			coinsOnWood.push_back(temp);
		}
		createCoins();

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
		people.clear();
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
		people.clear();
		break;
	}
	case 'D': case 'd': case 77: {
		people.goRight(STEPRIGHTLEFT);
		people.changeDirectionState(RIGHT);
		people.clear();
		break;
	}
	case 'A': case 'a': case 75: {
		people.goLeft(STEPRIGHTLEFT);
		people.changeDirectionState(LEFT);
		people.clear();
		break;
	}
	}
}

void GAME::peopleClear() {
	people.clear();
}

void GAME::updatePosCars() {
	int pre;
	for (int i = 0; i < lineCar; i++) {
		for (int j = 0; j < numCar[i]; j++) {
			if (spdCar[i] < 0) {
				pre = j - 1;
				if (pre == -1) pre = numCar[i] - 1;
			}
			else {
				pre = j + 1;
				if (pre == numCar[i]) pre = 0;
			}
			Cars[i][j].move(Cars[i][pre], distance[i]);
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
	for (int i = 0; i < lineWood; ++i) {
		for (int j = 0; j < coinsOnWood[i].size(); ++j) {
			coinsOnWood[i][j].moveOnRiver(1, Woods[i][(coinsOnWood[i][j].getiX())]);
		}
	}
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

	// draw wood
	for (int i = 0; i < lineWood; i++) {
		if (Woods[i][0].getY() >= 0 && Woods[i][0].getY() < Y_max) {
			for (int j = 0; j < numWood[i]; j++) {
				Woods[i][j].draw();
			}
		}
	}

	// draw car
	for (int i = 0; i < lineCar; i++) {
		if (Cars[i][0].getY() >= 0 && Cars[i][0].getY() < Y_max) {
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

	// draw coin
	for (int i = 0; i < coins.size(); ++i) {
		coins[i].draw();
	}

	// draw coinsOnWood
	for (int i = 0; i < lineWood; ++i) {
		if (Woods[i][0].getY() >= 0 && Woods[i][0].getY() < Y_max) {
			for (int j = 0; j < coinsOnWood[i].size(); ++j) {
				coinsOnWood[i][j].drawMove(1);
			}
		}
	}

	// draw people
	people.draw();
	/*if (sameLineWoods() != -1) {
		people.clearImage();
	}*/

	/*for (int i = 0; i < coinsOnWood.size(); ++i) {
		coinsOnWood[i].move(-1);
		coinsOnWood[i].drawMove(-1);
	}*/
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
	if (isEndScr() && (people.getY() <= 12) && sameLineWoods() == -1) return;

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
	if (sameLineWoods() != -1) people.setYC(Woods[sameLineWoods()][0].getY());

	// Coin
	for (int i = 0; i < coins.size(); ++i) {
		coins[i].setYC(coins[i].getYC() + 8);
	}

	// coinOnWood
	for (int i = 0; i < lineWood; ++i) {
		for (int j = 0; j < coinsOnWood[i].size(); ++j) {
			coinsOnWood[i][j].setYC(coinsOnWood[i][j].getYC() + 8);
		}
	}
	/*for (int i = 0; i < coinsOnWood.size(); ++i) {
		coinsOnWood[i].setYC(coinsOnWood[i].getYC() + 8);
	}*/

}

void GAME::peopleOnWood() {
	people.setYC(Woods[sameLineWoods()][0].getY());
	people.goLeft(abs(spdWood[sameLineWoods()]));
	people.draw();
	people.clearOnWood(LEFT, 1);
}

void GAME::createCoins() {
	unsigned totalLine = lineCar + lineTrain + lineWood,
		randLine;
	int randX, randY;

	// coin
	vector<int> sampleY = { 29,-11,13 };
	vector<vector<int>> sampleX;
	vector<int> sampleX_temp;
	int a=0;
	for (int i = 0; i < X_max / 6-1; ++i) {
		a += 6;
		sampleX_temp.push_back(a);
	}
	for (int i = 0; i < sampleY.size(); ++i) {
		sampleX.push_back(sampleX_temp);
	}

	// coins on wood 
	vector<int> sampleYWood = { -4 };
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
		case 0: case 2: {	// Line car, train
			int iY = rand() % sampleY.size();
			randY = sampleY[iY];
			randX = sampleX[iY][rand() % sampleX[iY].size()];
			for (int i = 0; i < sampleX[iY].size(); ++i) {
				if (sampleX[iY][i] == randX) {
					sampleX[iY].erase(sampleX[iY].begin() + i);
					sampleX[iY].shrink_to_fit();
					break;
				}
			}

			coins.push_back(Coin(randX, randY, LEFT));
			break;
		}

		case 1: {	// Line wood
			int iY = rand() % sampleYWood.size();
			if (countNCoin[iY] > 5) {
				--i;
			}
			else {
				randY = sampleYWood[iY];
				int iX = rand() % (sampleXWood[iY].size());
				randX = sampleXWood[iY][iX];
				sampleXWood[iY].erase(sampleXWood[iY].begin() + iX);
				sampleXWood[iY].shrink_to_fit();

				coinsOnWood[iY].push_back(Coin(randX - 3, randY-1, LEFT, iY));
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
				if (coinsOnWood[i][j].getXC() + 3 == sampleXWood_temp[i][k]
					|| coinsOnWood[i][j].getXC() + 3 == sampleXWood_temp[i][k] - 6
					|| coinsOnWood[i][j].getXC() + 3 == sampleXWood_temp[i][k] + 6) {
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
		if (coins[i].getYC() < 0 || coins[i].getYC() > Y_max) {}
		else {
			if (coins[i].isImpact(people.getXC(), people.getYC())) {
				people.changeMoney(COINVALUE);
				coins[i].clearImage();
				coins.erase(coins.begin() + i);
				coins.shrink_to_fit();
				--i;
			}
		}
	}

	for (int i = 0; i < lineWood; ++i) {
		for (int j = 0; j < coinsOnWood[i].size(); ++j) {
			if (coinsOnWood[i][0].getYC() < 0 || coinsOnWood[i][0].getYC() > Y_max) break;
			if (coinsOnWood[i][j].isImpactOnWood(people.getXC(), people.getYC())) {
				people.changeMoney(COINVALUE);
				coinsOnWood[i][j].clearImageOnWood();
				--countNCoin[coinsOnWood[i][j].getiY()];
				coinsOnWood[i].erase(coinsOnWood[i].begin() + j);
				coinsOnWood[i].shrink_to_fit();
				--j;
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
