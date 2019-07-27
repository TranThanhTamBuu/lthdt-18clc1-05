#include "GAME.h"


GAME::GAME(int level)
{
	this->level = level;
	switch (level) {
	case 1: {
		//Car
		lineCar = 2;
		int yCar[] = { -14, -22 }; //-14, -22
		numCar = new int[lineCar] { 4, 4 };
		spdCar = new int[lineCar] { -1, 1 };
		Cars = createCars(yCar, lineCar, numCar, spdCar, distance);

		//Train
		lineTrain = 2;
		int yTrain[] = { 10, -30 };
		spdTrain = new int[lineTrain] { 6, 6 };
		modeTrain = new int[lineTrain] { 0, 1 };
		Trains = createTrains(yTrain, lineTrain, spdTrain, modeTrain);

		//Wood
		lineWood = 1;
		int yWood[] = { -5 };
		numWood = new int [lineWood] { 4 };
		spdWood = new int [lineWood] { 1 };
		Woods = createWoods(yWood, lineWood, numWood, spdWood);

		//Lilypad
		linePad = 1;
		yPad = new int [linePad] { 27 }; //27
		numPad = new int [linePad] { 5 };
		createLilypads(yPad, linePad, numPad);

		// Coin
		nCoin = 5;
		vector<int> countNCoin_temp(1, 0);
		countNCoin = countNCoin_temp;
		for (int i = 0; i < lineWood; ++i) {
			vector<Coin> temp;
			coinsOnWood.push_back(temp);
		}
		sampleYWood = { -5 };
		sampleY = { 10 + H_VEHICLE-2, -30 + H_VEHICLE - 2 ,-14 + H_VEHICLE - 2, -22 + H_VEHICLE - 2 };
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
		if (sameLineWoods() != -1 || sameLinePads() != -1) {
			people.clearImage();
			people.goUp(STEPUPDOWN - 2);
		}
		else {
			people.goUp(STEPUPDOWN);
		}
		people.changeDirectionState(UP);
		people.clear();
		break;
	}
	case 'S': case 's': case 80: {
		if (sameLineWoods() != -1 || sameLinePads() != -1) {
			people.clearImage();
			people.goDown(STEPUPDOWN + 2);
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
			if (Cars[i][0].getY() > Y_max) break;
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
		if (Trains[i].getY() > Y_max) continue;
		Trains[i].move();
	}
}

void GAME::updatePosWoods() {
	for (int i = 0; i < lineWood; i++) {
		for (int j = 0; j < numWood[i]; j++) {
			if (Woods[i][0].getY() > Y_max) break;
			Woods[i][j].move();
		}
	}
}

void GAME::updatePosCoinOnWoods() {
	for (int i = 0; i < lineWood; ++i) {
		for (int j = 0; j < coinsOnWood[i].size(); ++j) {
			if (coinsOnWood[i][0].getY() > Y_max) break;
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
				if (Cars[i][0].getY() < 0 || Cars[i][0].getY() > Y_max) break;
				if (Cars[i][j].isImpact(people)) {
					return true;
				}
			}
		}
	}

	//Train
	for (int i = 0; i < lineTrain; i++) {
		if (Trains[i].getY() < Y_max  && Trains[i].getY() > 0) {
			if (Trains[i].isImpact(people)) {
				return true;
			}
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
			Woods[i][0].drawWave();
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

	//draw lilypad
	for (int i = 0; i < linePad; i++) {
		if (numPad[i] != 0) {
			if (Pads[i][0].getY() >= 0 && Pads[i][0].getY() < Y_max) {
				Pads[i][0].drawWave();
				for (int j = 0; j < numPad[i]; j++) {
					Pads[i][j].draw();
				}
			}
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
}

bool GAME::isEndScr() {

	//Car
	for (int i = 0; i < lineCar; i++) {
		if (Cars[i][0].getY() < 8) {
			return false;
		}
	}

	//Train
	for (int i = 0; i < lineTrain; i++) {
		if (Trains[i].getY() < 8) {
			return false;
		}
	}

	//Wood
	for (int i = 0; i < lineWood; i++) {
		if (Woods[i][0].getY() < 8) {
			return false;
		}
	}

	//Lilypad
	for (int i = 0; i < linePad; i++) {
		if (Pads[i][0].getY() < 8) {
			return false;
		}
	}

	return true;
}

void GAME::screenScroll() {
	if (isEndScr() && (people.getY() <= 12) && sameLineWoods() == -1) return;

	if (people.getY() >= 18) return;

	if (sameLineWoods() != -1 && people.getY() >= 18) return;

	people.setY(20);

	clrscr();

	for (int i = 0; i <= 5; i++) {
		gotoXY(0, 0 + 8 * i);	printLine(WIDTH);
	}

	//Car
	for (int i = 0; i < lineCar; i++) {
		for (int j = 0; j < numCar[i]; j++) {
			if (Cars[i][0].getY() > Y_max) break;
			Cars[i][j].setY(Cars[i][j].getY() + 8);
		}
	}

	//Train
	for (int i = 0; i < lineTrain; i++) {
		if (Trains[i].getY() > Y_max) continue;
		Trains[i].setY(Trains[i].getY() + 8);
	}

	//Wood
	for (int i = 0; i < lineWood; i++) {
		for (int j = 0; j < numWood[i]; j++) {
			if (Woods[i][0].getY() > Y_max) break;
			Woods[i][j].setY(Woods[i][j].getY() + 8);
		}
	}
	if (sameLineWoods() != -1) people.setYC(Woods[sameLineWoods()][0].getY());

	//Lilypad
	for (int i = 0; i < linePad; i++) {
		for (int j = 0; j < numPad[i]; j++) {
			if (Pads[i][0].getY() > Y_max) break;
			Pads[i][j].setY(Pads[i][j].getY() + 8);
		}
	}

	// Coin
	for (int i = 0; i < coins.size(); ++i) {
		coins[i].setYC(coins[i].getYC() + 8);
	}

	// coinOnWood
	for (int i = 0; i < lineWood; ++i) {
		for (int j = 0; j < coinsOnWood[i].size(); ++j) {
			if (coinsOnWood[i][0].getY() > Y_max) break;
			coinsOnWood[i][j].setYC(coinsOnWood[i][j].getYC() + 8);
		}
	}

}

void GAME::peopleOnPad() {
	people.setYC(Pads[sameLinePads()][0].getY());
}

void GAME::peopleOnWood(DState dst) {
	people.setYC(Woods[sameLineWoods()][0].getY());
	switch (dst) {
	case LEFT: {
		people.goLeft(abs(spdWood[sameLineWoods()]));
		break;
	}
	case RIGHT: {
		people.goRight(abs(spdWood[sameLineWoods()]));
		break;
	}
	}

	people.draw();
	people.clearOnWood(dst, 1);
}

void GAME::createCoins() {
	unsigned totalLine = lineCar + lineTrain + lineWood,
		randLine;
	int randX, randY;

	// coin
	vector<vector<int>> sampleX;
	vector<int> sampleX_temp;
	int a = 0;
	for (int i = 0; i < X_max / 6 - 1; ++i) {
		a += 6;
		sampleX_temp.push_back(a);
	}
	for (int i = 0; i < sampleY.size(); ++i) {
		sampleX.push_back(sampleX_temp);
	}

	// coins on wood 
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

				coinsOnWood[iY].push_back(Coin(randX - 3, randY - 1, LEFT, iY));
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

	// coins on wood
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

void GAME::createLilypads(int yPad[], int linePad, int *numPad) {
	vector <int> usedX;
	int slot = 152 / (lilypad[0].length());
	int randX;
	bool flag = true;

	for (int i = 0; i < linePad; i++) {
		vector <Lilypad> sample;
		for (int j = 0; j < numPad[i]; j++) {
			do {
				randX = rand() % slot;
				flag = isUsed(randX, usedX);
				if (flag == false) {
					usedX.push_back(randX);
				}
			} while (flag);
			sample.push_back(Lilypad(3 + randX * lilypad[0].length(), yPad[i]));
			//Pads[i][j].set(3 + randX * lilypad[0].length(), yPad[i], 0);
		}
		usedX.clear();
		Pads.push_back(sample);
	}
}

int GAME::sameLinePads() {
	for (int i = 0; i < linePad; i++) {
		if (numPad[i] != 0) {
			if ((Pads[i][0].getY() - 4 <= people.getY()) && (people.getY() <= (Pads[i][0].getY() + 4))) {
				return i;
			}
		}
		else {
			if ((yPad[i] - 4 <= people.getY()) && (people.getY() <= (yPad[i] + 4))) {
				return i;
			}
		}
	}
	return -1;
}

int GAME::impactPads() {
	int line = sameLinePads();

	if (line == -1) {
		return 0;
	}

	for (int j = 0; j < numPad[line]; j++) {
		if (Pads[line][j].isImpact(people)) {
			if (!Pads[line][j].getState()) {
				Pads[line][j].startTime();
				Pads[line][j].setOn();
			}
			return 1;
		}
	}

	return -1;
}

void GAME::updatePads() {
	for (int i = 0; i < linePad; i++) {
		if (numPad[i] != 0) {
			for (int j = 0; j < numPad[i]; j++) {
				if (Pads[i][j].getY() > Y_max) break;
				if (Pads[i][j].getState()) {
					Pads[i][j].setTime();
					if (Pads[i][j].timeLeft() > 5) {
						Pads[i][j].clear();
						Pads[i][j].drawWave();
						Pads[i].erase(Pads[i].begin() + j);
						Pads[i].shrink_to_fit();
						numPad[i] -= 1;
					}
				}
			}
		}
	}
}