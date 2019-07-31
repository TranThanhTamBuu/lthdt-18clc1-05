#include "GAME.h"


GAME::GAME(int level)
{
	this->level = level;
	switch (level) {
	case 1: {
		//Car
		lineCar = 2;
		int yCar[] = { 26, 10 };
		numCar = new int[lineCar] { 3, 4 };
		spdCar = new int[lineCar] { -1, 1 };
		Cars = createCars(yCar, lineCar, numCar, spdCar, distance);

		//Train
		lineTrain = 1;
		int yTrain[] = { -6 };
		spdTrain = new int[lineTrain] { 6 };
		modeTrain = new int[lineTrain] { 0 };
		Trains = createTrains(yTrain, lineTrain, spdTrain, modeTrain);

		//Wood
		lineWood = 1;
		int yWood[] = { -37 };
		numWood = new int [lineWood] { 3 };
		spdWood = new int [lineWood] { 1 };
		Woods = createWoods(yWood, lineWood, numWood, spdWood);

		//Lilypad
		linePad = 1;
		yPad = new int [linePad] { -21 }; 
		numPad = new int [linePad] { 5 };
		createLilypads(yPad, linePad, numPad);

		// Coin
		nCoin = 10;
		vector<int> nCoinOnWood_temp(lineWood, 0);
		nCoinOnWood = nCoinOnWood_temp;
		for (int i = 0; i < lineWood; ++i) {
			vector<Coin> temp;
			coinsOnWood.push_back(temp);
		}
		sampleYWood = { -37 };
		sampleY = { 26 + H_VEHICLE - 2, 10 + H_VEHICLE - 2 , -6 + H_VEHICLE - 2};
		createCoins();
		
		break;
	}
	case 2: {
		lineCar = 3;
		int yCar[] = { 26, 18, 10 };
		numCar = new int[lineCar] { 2, 3, 4 };
		spdCar = new int[lineCar] { -4, 2, -2 };
		Cars = createCars(yCar, lineCar, numCar, spdCar, distance);

		//Train
		lineTrain = 1;
		int yTrain[] = { -6 };
		spdTrain = new int[lineTrain] { 6 };
		modeTrain = new int[lineTrain] { 1 };
		Trains = createTrains(yTrain, lineTrain, spdTrain, modeTrain);

		//Wood
		lineWood = 2;
		int yWood[] = { -21, -37 };
		numWood = new int [lineWood] { 3, 4 };
		spdWood = new int [lineWood] { 3, -2 };
		Woods = createWoods(yWood, lineWood, numWood, spdWood);

		//Lilypad
		linePad = 2;
		yPad = new int [linePad] { -29, -45 }; //27
		numPad = new int [linePad] { 8, 5 };
		createLilypads(yPad, linePad, numPad);

		// Coin
		nCoin = 15;
		vector<int> nCoinOnWood_temp(lineWood, 0);
		nCoinOnWood = nCoinOnWood_temp;
		for (int i = 0; i < lineWood; ++i) {
			vector<Coin> temp;
			coinsOnWood.push_back(temp);
		}
		sampleYWood = { -21, -37 };
		sampleY = { 26 + H_VEHICLE - 2, 18 + H_VEHICLE - 2 , 10 + H_VEHICLE - 2, -6 + H_VEHICLE - 2 };
		createCoins();
		break;
	}
	case 3: {
		//Car
		lineCar = 4;
		int yCar[] = { 26, -14, -22, -30 }; //-14, -22
		numCar = new int[lineCar] { 4, 2, 3, 4 };
		spdCar = new int[lineCar] { -3, 4, 3, 2, };
		Cars = createCars(yCar, lineCar, numCar, spdCar, distance);

		//Train
		lineTrain = 2;
		int yTrain[] = { 2, -78 };
		spdTrain = new int[lineTrain] { 8, 10 };
		modeTrain = new int[lineTrain] { 1, 1 };
		Trains = createTrains(yTrain, lineTrain, spdTrain, modeTrain);

		//Wood
		lineWood = 3;
		int yWood[] = { 19, 11, -53};
		numWood = new int [lineWood] { 4,3,1 };
		spdWood = new int [lineWood] { 2,-5,4};
		Woods = createWoods(yWood, lineWood, numWood, spdWood);

		//Lilypad
		linePad = 2;
		yPad = new int [linePad] { -45, -61};
		numPad = new int [linePad] { 8, 8};
		createLilypads(yPad, linePad, numPad);

		// Coin
		nCoin = 15;
		vector<int> nCoinOnWood_temp(lineWood, 0);
		nCoinOnWood = nCoinOnWood_temp;
		for (int i = 0; i < lineWood; ++i) {
			vector<Coin> temp;
			coinsOnWood.push_back(temp);
		}
		sampleYWood = { 19, 11, -53 };
		sampleY = { 26 + H_VEHICLE - 2, -14 + H_VEHICLE - 2 ,-22 + H_VEHICLE - 2, -30 + H_VEHICLE - 2,-78 + H_VEHICLE - 2 };
		createCoins();
		break;
	}
	case 4: {
		//Car
		lineCar = 4;
		int yCar[] = { -30, -38, -54, - 117 }; //-14, -22
		numCar = new int[lineCar] { 4, 2, 4,3 };
		spdCar = new int[lineCar] { -1, 4, -2, -4 };
		Cars = createCars(yCar, lineCar, numCar, spdCar, distance);

		//Train
		lineTrain = 4;
		int yTrain[] = { -46, -62, -86, -102 };
		spdTrain = new int[lineTrain] { 8, 10, 6, 10};
		modeTrain = new int[lineTrain] { 0, 0, 0, 1};
		Trains = createTrains(yTrain, lineTrain, spdTrain, modeTrain);

		//Wood
		lineWood = 7;
		int yWood[] = { 27, 19, 11, 3,-5,-13, -109 };
		numWood = new int [lineWood] { 2,3,1,2,1,3,4 };
		spdWood = new int [lineWood] { 5,-2,3,-3,2,-5,4 };
		Woods = createWoods(yWood, lineWood, numWood, spdWood);

		//Lilypad
		linePad = 2;
		yPad = new int [linePad] { -77,-93 };
		numPad = new int [linePad] { 5, 3 };
		createLilypads(yPad, linePad, numPad);

		// Coin
		nCoin = 30;
		vector<int> nCoinOnWood_temp(lineWood, 0);
		nCoinOnWood = nCoinOnWood_temp;
		for (int i = 0; i < lineWood; ++i) {
			vector<Coin> temp;
			coinsOnWood.push_back(temp);
		}
		sampleYWood = { 27, 19, 11, 3,-5,-13, -109 };
		sampleY = { -30 + H_VEHICLE - 2, -38 + H_VEHICLE - 2 ,-54 + H_VEHICLE - 2, -117 + H_VEHICLE - 2,
			-46 + H_VEHICLE - 2, -62 + H_VEHICLE - 2 ,-86 + H_VEHICLE - 2, -102 + H_VEHICLE - 2 };
		createCoins();

		break;
	}
	case 5: {
		lineCar = 6;
		int yCar[] = { 26, 10,-62,-70,-78, -126 }; //-14, -22
		numCar = new int[lineCar] { 4, 4,1,1,1,3 };
		spdCar = new int[lineCar] { -1, 1,8,-8,8,-6 };
		Cars = createCars(yCar, lineCar, numCar, spdCar, distance);

		//Train
		lineTrain = 3;
		int yTrain[] = { -30, -38,- 46 };
		spdTrain = new int[lineTrain] { 6, 12, 10 };
		modeTrain = new int[lineTrain] { 0, 0, 1 };
		Trains = createTrains(yTrain, lineTrain, spdTrain, modeTrain);

		//Wood
		lineWood = 6;
		int yWood[] = { 19,3,-13,-101,-109,-117 };
		numWood = new int [lineWood] { 3,2,1,1,4,1 };
		spdWood = new int [lineWood] { 3,-4,5,8,-1, 6 };
		Woods = createWoods(yWood, lineWood, numWood, spdWood);

		//Lilypad
		linePad = 3;
		yPad = new int [linePad] { -5,-21,-93 }; //27
		numPad = new int [linePad] { 5,5,8 };
		createLilypads(yPad, linePad, numPad);

		// Coin
		nCoin = 40;
		vector<int> nCoinOnWood_temp(lineWood, 0);
		nCoinOnWood = nCoinOnWood_temp;
		for (int i = 0; i < lineWood; ++i) {
			vector<Coin> temp;
			coinsOnWood.push_back(temp);
		}
		sampleYWood = { 19,3,-13,-101,-109,-117 };
		sampleY = { 26 + H_VEHICLE - 2, 10 + H_VEHICLE - 2 ,-62 + H_VEHICLE - 2, -70 + H_VEHICLE - 2,
			-78 + H_VEHICLE - 2, -126 + H_VEHICLE - 2 ,-30 + H_VEHICLE - 2, -38 + H_VEHICLE - 2, -46 + H_VEHICLE - 2 };
		createCoins();

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
		if (Trains[i].getY() >= Y_max) continue;
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
		int speed = Woods[i][0].getSpd();
		for (int j = 0; j < coinsOnWood[i].size(); ++j) {
			if (coinsOnWood[i][0].getY() > Y_max) break;
			coinsOnWood[i][j].moveOnRiver(speed, Woods[i][(coinsOnWood[i][j].getiX())]);
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
			int speed = Woods[i][0].getSpd();
			for (int j = 0; j < coinsOnWood[i].size(); ++j) {
				coinsOnWood[i][j].drawMove(speed);
			}
		}
	}

	// draw people
	people.draw();
	people.displayMoney();
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

void GAME::peopleOnWood() {
	people.setYC(Woods[sameLineWoods()][0].getY());
	int speed = Woods[sameLineWoods()][0].getSpd();
	
	if (speed < 0) {
		people.goLeft(abs(spdWood[sameLineWoods()]));
		people.draw();
		people.clearOnWood(LEFT, abs(spdWood[sameLineWoods()]));
	}
	else {
		people.goRight(abs(spdWood[sameLineWoods()]));
		people.draw();
		people.clearOnWood(RIGHT, abs(spdWood[sameLineWoods()]));
	}
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
			if (nCoinOnWood[iY] > 5) {
				--i;
			}
			else {
				randY = sampleYWood[iY];
				int iX = rand() % (sampleXWood[iY].size());
				randX = sampleXWood[iY][iX];
				sampleXWood[iY].erase(sampleXWood[iY].begin() + iX);
				sampleXWood[iY].shrink_to_fit();

				int speed = Woods[iY][0].getSpd();
				if (speed > 0) {
					coinsOnWood[iY].push_back(Coin(randX - 3, randY - 1, RIGHT, iY));
				}
				else {
					coinsOnWood[iY].push_back(Coin(randX - 3, randY - 1, LEFT, iY));
				}
				// Count nCoin on one line	
				++nCoinOnWood[iY];
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
				--nCoinOnWood[coinsOnWood[i][j].getiY()];
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

void GAME::save(bool saveAs) {
	SaveLoad saveStruct;
	wstring fileName = L"save.sr";

	if (saveAs) {
		// enter file save name
		gotoXY(X_max / 2, Y_max / 2);
		wcout << "Enter file save name: ";
		wcin >> fileName;
	}

	ofstream outFile(fileName, ios::binary);
	if (!outFile) {
		wcout << "Can not open file to save" << endl;
		return;
	}

	saveStruct.level = level;
	saveStruct.people.model = people.getModel();
	saveStruct.people.money = people.getMoney();
	int* p = people.getOwnedModel();
	for (int i = 0; i < 5; i++) {
		saveStruct.people.ownedModel[i] = p[i];
	}
	saveStruct.people.people.x = people.getXC();
	saveStruct.people.people.y = people.getYC();
	outFile.write(reinterpret_cast<char*>(&saveStruct), sizeof(saveStruct.level) + sizeof(saveStruct.people));

	// Car
	saveStruct.cars.lineCar = lineCar;
	saveStruct.cars.numCar = new int32_t[lineCar];
	saveStruct.cars.spdCar = new int32_t[lineCar];
	saveStruct.cars.distance = new int32_t[lineCar];
	saveStruct.cars.Cars = new Point*[lineCar];
	for (int i = 0; i < lineCar; ++i) {
		saveStruct.cars.numCar[i] = numCar[i];
		saveStruct.cars.spdCar[i] = spdCar[i];
		saveStruct.cars.distance[i] = distance[i];
		
		saveStruct.cars.Cars[i] = new Point[numCar[i]];
		for (int j = 0; j < numCar[i]; ++j) {
			Point temp1;
			saveStruct.cars.Cars[i][j].x = Cars[i][j].getX();
			saveStruct.cars.Cars[i][j].y = Cars[i][j].getY();
		}
	}
	outFile.write(reinterpret_cast<char*>(&saveStruct.cars.lineCar), sizeof(saveStruct.cars.lineCar));
	outFile.write(reinterpret_cast<char*>(saveStruct.cars.numCar), lineCar*sizeof(int32_t));
	outFile.write(reinterpret_cast<char*>(saveStruct.cars.spdCar), lineCar * sizeof(int32_t));
	outFile.write(reinterpret_cast<char*>(saveStruct.cars.distance), lineCar * sizeof(int32_t));
	for (int i = 0; i < lineCar; ++i) {
		outFile.write(reinterpret_cast<char*>(saveStruct.cars.Cars[i]), numCar[i]*sizeof(Point));
	}

	// Train
	saveStruct.trains.lineTrain = lineTrain;
	saveStruct.trains.spdTrain = new int32_t[lineTrain];
	saveStruct.trains.modeTrain = new int32_t[lineTrain];
	saveStruct.trains.Trains = new Point[lineTrain];
	for (int i = 0; i < lineTrain; ++i) {
		saveStruct.trains.spdTrain[i] = spdTrain[i];
		saveStruct.trains.modeTrain[i] = modeTrain[i];		
		saveStruct.trains.Trains[i].x = Trains[i].getX();
		saveStruct.trains.Trains[i].y = Trains[i].getY();
	}
	outFile.write(reinterpret_cast<char*>(&saveStruct.trains.lineTrain), sizeof(saveStruct.trains.lineTrain));
	outFile.write(reinterpret_cast<char*>(saveStruct.trains.spdTrain), lineTrain*sizeof(int32_t));
	outFile.write(reinterpret_cast<char*>(saveStruct.trains.modeTrain), lineTrain * sizeof(int32_t));
	outFile.write(reinterpret_cast<char*>(saveStruct.trains.Trains), lineTrain * sizeof(Point));


	// Wood
	saveStruct.woods.lineWood = lineWood;
	saveStruct.woods.numWood = new int32_t[lineWood];
	saveStruct.woods.spdWood = new int32_t[lineWood];
	saveStruct.woods.Woods = new Point*[lineWood];
	for (int i = 0; i < lineWood; ++i) {
		saveStruct.woods.numWood[i]= numWood[i];
		saveStruct.woods.spdWood[i] = spdWood[i];

		saveStruct.woods.Woods[i] = new Point[numWood[i]];
		for (int j = 0; j < numWood[i]; ++j) {
			saveStruct.woods.Woods[i][j].x = Woods[i][j].getX();
			saveStruct.woods.Woods[i][j].y = Woods[i][j].getY();
		}
	}
	outFile.write(reinterpret_cast<char*>(&saveStruct.woods.lineWood), sizeof(saveStruct.woods.lineWood));
	outFile.write(reinterpret_cast<char*>(saveStruct.woods.numWood), lineWood * sizeof(int32_t));
	outFile.write(reinterpret_cast<char*>(saveStruct.woods.spdWood), lineWood * sizeof(int32_t));
	for (int i = 0; i < lineWood; ++i) {
		outFile.write(reinterpret_cast<char*>(saveStruct.woods.Woods[i]), numWood[i] * sizeof(Point));
	}

	// Lilypad
	saveStruct.pads.linePad = linePad;
	saveStruct.pads.yPad = new int32_t[linePad];
	saveStruct.pads.numPad = new int32_t[linePad];
	saveStruct.pads.Pads = new Point*[linePad];
	for (int i = 0; i < linePad; ++i) {
		saveStruct.pads.yPad[i] = yPad[i];
		saveStruct.pads.numPad[i] = numPad[i];

		saveStruct.pads.Pads[i] = new Point[numPad[i]];
		for (int j = 0; j < numPad[i]; ++j) {
			saveStruct.pads.Pads[i][j].x = Pads[i][j].getX();
			saveStruct.pads.Pads[i][j].y = Pads[i][j].getY();
		}
	}
	outFile.write(reinterpret_cast<char*>(&saveStruct.pads.linePad), sizeof(saveStruct.pads.linePad));
	outFile.write(reinterpret_cast<char*>(saveStruct.pads.yPad), linePad * sizeof(int32_t));
	outFile.write(reinterpret_cast<char*>(saveStruct.pads.numPad), linePad * sizeof(int32_t));
	for (int i = 0; i < linePad; ++i) {
		outFile.write(reinterpret_cast<char*>(saveStruct.pads.Pads[i]), numPad[i] * sizeof(Point));
	}

	// Coin
	saveStruct.coins.nCoinOnStreet = coins.size();
	saveStruct.coins.Coins = new Point[saveStruct.coins.nCoinOnStreet];
	for (int i = 0; i < coins.size(); ++i)  {
		saveStruct.coins.Coins[i].x = coins[i].getXC();
		saveStruct.coins.Coins[i].y = coins[i].getYC();
	}
	outFile.write(reinterpret_cast<char*>(&saveStruct.coins.nCoinOnStreet), sizeof(saveStruct.coins.nCoinOnStreet));
	outFile.write(reinterpret_cast<char*>(saveStruct.coins.Coins), coins.size()*sizeof(Point));

	// Coin on wood
	saveStruct.coinsOnWood.nCoinOnWood = new int32_t[lineWood];
	saveStruct.coinsOnWood.CoinsOnWood = new Point*[lineWood];
	saveStruct.coinsOnWood.iLineNum = new Point*[lineWood];

	for (int i = 0; i < lineWood; ++i) {
		saveStruct.coinsOnWood.nCoinOnWood[i] = nCoinOnWood[i];
		saveStruct.coinsOnWood.CoinsOnWood[i] = new Point[nCoinOnWood[i]];
		saveStruct.coinsOnWood.iLineNum[i] = new Point[nCoinOnWood[i]];

		for (int j = 0; j < nCoinOnWood[i]; ++j) {
			saveStruct.coinsOnWood.CoinsOnWood[i][j].x = coinsOnWood[i][j].getXC();
			saveStruct.coinsOnWood.CoinsOnWood[i][j].y = coinsOnWood[i][j].getYC();

			
			saveStruct.coinsOnWood.iLineNum[i][j].x = coinsOnWood[i][j].getiX();
			saveStruct.coinsOnWood.iLineNum[i][j].y = coinsOnWood[i][j].getiY();
		}
	}
	outFile.write(reinterpret_cast<char*>(saveStruct.coinsOnWood.nCoinOnWood), lineWood*sizeof(int32_t));
	for (int i = 0; i < lineWood; ++i) {
		outFile.write(reinterpret_cast<char*>(saveStruct.coinsOnWood.CoinsOnWood[i]), nCoinOnWood[i] * sizeof(Point));
	}
	for (int i = 0; i < lineWood; ++i) {
		outFile.write(reinterpret_cast<char*>(saveStruct.coinsOnWood.iLineNum[i]), nCoinOnWood[i] * sizeof(Point));
	}

	outFile.close();

	delete[] saveStruct.cars.numCar;
	delete[] saveStruct.cars.spdCar;
	delete[] saveStruct.trains.spdTrain;
	delete[] saveStruct.trains.modeTrain;
	delete[] saveStruct.trains.Trains;
	delete[] saveStruct.woods.numWood;
	delete[] saveStruct.woods.spdWood;
	delete[] saveStruct.pads.numPad;
	delete[] saveStruct.pads.yPad;
	delete[] saveStruct.coins.Coins;
	delete[] saveStruct.coinsOnWood.nCoinOnWood;

	for (int i = 0; i < lineCar; ++i) {
		delete[] saveStruct.cars.Cars[i];
	}
	for (int i = 0; i < lineWood; ++i) {
		delete[] saveStruct.woods.Woods[i];
	}
	for (int i = 0; i < linePad; ++i) {
		delete saveStruct.pads.Pads[i];
	}
	for (int i = 0; i < lineWood; ++i) {
		delete[] saveStruct.coinsOnWood.CoinsOnWood[i];
		delete[] saveStruct.coinsOnWood.iLineNum[i];
	}
}

void GAME::load(bool loadFrom) {
	SaveLoad loadStruct;
	wstring fileName = L"save.sr";

	if (loadFrom) {
		// enter file load name
		gotoXY(X_max / 2, Y_max / 2);
		wcout << "Enter file load name: ";
		wcin >> fileName;
	}

	ifstream inFile(fileName.c_str(), ios::binary);
	if (!inFile) {
		wcout << "Can not open file to load" << endl;
		return;
	}

	inFile.read(reinterpret_cast<char*>(&loadStruct), sizeof(loadStruct.level) + sizeof(loadStruct.people));
	inFile.read(reinterpret_cast<char*>(&loadStruct.cars.lineCar), sizeof(loadStruct.cars.lineCar));
	// Car
	loadStruct.cars.numCar = new int32_t[loadStruct.cars.lineCar];
	loadStruct.cars.spdCar = new int32_t[loadStruct.cars.lineCar];
	loadStruct.cars.distance = new int32_t[loadStruct.cars.lineCar];
	loadStruct.cars.Cars = new Point*[loadStruct.cars.lineCar];

	inFile.read(reinterpret_cast<char*>(loadStruct.cars.numCar), loadStruct.cars.lineCar * sizeof(int32_t));
	inFile.read(reinterpret_cast<char*>(loadStruct.cars.spdCar), loadStruct.cars.lineCar * sizeof(int32_t));
	inFile.read(reinterpret_cast<char*>(loadStruct.cars.distance), loadStruct.cars.lineCar * sizeof(int32_t));
	for (int i = 0; i < loadStruct.cars.lineCar; ++i) {
		loadStruct.cars.Cars[i] = new Point[loadStruct.cars.numCar[i]];
		inFile.read(reinterpret_cast<char*>(loadStruct.cars.Cars[i]), loadStruct.cars.numCar[i] * sizeof(Point));
	}

	// Train
	inFile.read(reinterpret_cast<char*>(&loadStruct.trains.lineTrain), sizeof(int32_t));
	loadStruct.trains.spdTrain = new int32_t[loadStruct.trains.lineTrain];
	loadStruct.trains.modeTrain = new int32_t[loadStruct.trains.lineTrain];
	loadStruct.trains.Trains = new Point[loadStruct.trains.lineTrain];

	inFile.read(reinterpret_cast<char*>(loadStruct.trains.spdTrain), loadStruct.trains.lineTrain * sizeof(int32_t));
	inFile.read(reinterpret_cast<char*>(loadStruct.trains.modeTrain), loadStruct.trains.lineTrain * sizeof(int32_t));
	inFile.read(reinterpret_cast<char*>(loadStruct.trains.Trains), loadStruct.trains.lineTrain * sizeof(Point));
	
	// Wood
	inFile.read(reinterpret_cast<char*>(&loadStruct.woods.lineWood), sizeof(int32_t));
	loadStruct.woods.numWood = new int32_t[loadStruct.woods.lineWood];
	loadStruct.woods.spdWood = new int32_t[loadStruct.woods.lineWood];
	loadStruct.woods.Woods = new Point*[loadStruct.woods.lineWood];

	inFile.read(reinterpret_cast<char*>(loadStruct.woods.numWood), loadStruct.woods.lineWood * sizeof(int32_t));
	inFile.read(reinterpret_cast<char*>(loadStruct.woods.spdWood), loadStruct.woods.lineWood * sizeof(int32_t));
	for (int i = 0; i < loadStruct.woods.lineWood; ++i) {
		loadStruct.woods.Woods[i] = new Point[loadStruct.woods.numWood[i]];
		inFile.read(reinterpret_cast<char*>(loadStruct.woods.Woods[i]), loadStruct.woods.numWood[i] * sizeof(Point));
	}

	// Lilypad
	inFile.read(reinterpret_cast<char*>(&loadStruct.pads.linePad), sizeof(int32_t));
	loadStruct.pads.yPad = new int32_t[loadStruct.pads.linePad];
	loadStruct.pads.numPad = new int32_t[loadStruct.pads.linePad];
	loadStruct.pads.Pads = new Point*[loadStruct.pads.linePad];

	inFile.read(reinterpret_cast<char*>(loadStruct.pads.yPad), loadStruct.pads.linePad * sizeof(int32_t));
	inFile.read(reinterpret_cast<char*>(loadStruct.pads.numPad), loadStruct.pads.linePad * sizeof(int32_t));
	for (int i = 0; i < loadStruct.pads.linePad; ++i) {
		loadStruct.pads.Pads[i] = new Point[loadStruct.pads.numPad[i]];
		inFile.read(reinterpret_cast<char*>(loadStruct.pads.Pads[i]), loadStruct.pads.numPad[i] * sizeof(Point));
	}

	// Coin
	inFile.read(reinterpret_cast<char*>(&loadStruct.coins.nCoinOnStreet), sizeof(int32_t));
	loadStruct.coins.Coins = new Point[loadStruct.coins.nCoinOnStreet];
	inFile.read(reinterpret_cast<char*>(loadStruct.coins.Coins), loadStruct.coins.nCoinOnStreet * sizeof(Point));

	// Coin on wood
	loadStruct.coinsOnWood.nCoinOnWood = new int32_t[loadStruct.woods.lineWood];
	loadStruct.coinsOnWood.CoinsOnWood = new Point*[loadStruct.woods.lineWood];
	loadStruct.coinsOnWood.iLineNum = new Point*[loadStruct.woods.lineWood];
	
	inFile.read(reinterpret_cast<char*>(loadStruct.coinsOnWood.nCoinOnWood), loadStruct.woods.lineWood * sizeof(int32_t));
	for (int i = 0; i < loadStruct.woods.lineWood; ++i) {
		loadStruct.coinsOnWood.CoinsOnWood[i] = new Point[loadStruct.coinsOnWood.nCoinOnWood[i]];
		inFile.read(reinterpret_cast<char*>(loadStruct.coinsOnWood.CoinsOnWood[i]), loadStruct.coinsOnWood.nCoinOnWood[i] * sizeof(Point));
	}
	for (int i = 0; i < loadStruct.woods.lineWood; ++i) {
		loadStruct.coinsOnWood.iLineNum[i] = new Point[loadStruct.coinsOnWood.nCoinOnWood[i]];
		inFile.read(reinterpret_cast<char*>(loadStruct.coinsOnWood.iLineNum[i]), loadStruct.coinsOnWood.nCoinOnWood[i] * sizeof(Point));
	}

	inFile.close();

	// LOAD
	delete[] numCar;
	delete[] spdCar;
	delete[] distance;
	delete[] Trains;
	delete[]spdTrain;
	delete[] modeTrain;
	for (int i = 0; i < lineWood; ++i) {
		delete[] Woods[i];
	}
	delete[] numWood;
	delete[] spdWood;
	delete[] numPad;
	delete[] yPad;

	// Car
	lineCar = loadStruct.cars.lineCar;
	Cars = new Car*[lineCar];
	numCar = new int[lineCar];
	spdCar = new int[lineCar];
	distance = new int[lineCar];
	for (int i = 0; i < lineCar; ++i) {
		numCar[i] = loadStruct.cars.numCar[i];
		spdCar[i] = loadStruct.cars.spdCar[i];
		distance[i] = loadStruct.cars.distance[i];
		Cars[i] = new Car[numCar[i]];

		for (int j = 0; j < numCar[i]; ++j) {
			Cars[i][j].set(loadStruct.cars.Cars[i][j].x,loadStruct.cars.Cars[i][j].y);
			Cars[i][j].setSpd(spdCar[i]);
		}
	}
	
	// Train
	lineTrain = loadStruct.trains.lineTrain;
	Trains = new Train[lineTrain];
	spdTrain = new int[lineTrain];
	modeTrain = new int[lineTrain];
	for (int i = 0; i < lineTrain; ++i) {
		spdTrain[i] = loadStruct.trains.spdTrain[i];
		modeTrain[i] = loadStruct.trains.modeTrain[i];
		Trains[i].set(loadStruct.trains.Trains[i].x, loadStruct.trains.Trains[i].y, spdTrain[i],modeTrain[i]);
	}
	
	// Wood
	lineWood = loadStruct.woods.lineWood;
	Woods = new Wood*[lineWood];
	numWood = new int[lineWood];
	spdWood = new int[lineWood];
	for (int i = 0; i < lineWood; ++i) {
		numWood[i] = loadStruct.woods.numWood[i];
		spdWood[i] = loadStruct.woods.spdWood[i];
		Woods[i] = new Wood[numWood[i]];

		for (int j = 0; j < numWood[i]; ++j) {
			Woods[i][j].set(loadStruct.woods.Woods[i][j].x, loadStruct.woods.Woods[i][j].y, loadStruct.woods.spdWood[i]);
		}
	}

	// Lilypad
	Pads.clear();
	linePad = loadStruct.pads.linePad;
	numPad = new int[linePad];
	yPad = new int[linePad];
	for (int i = 0; i < linePad; ++i) {
		numPad[i] = loadStruct.pads.numPad[i];
		yPad[i] = loadStruct.pads.yPad[i];
		vector<Lilypad> temp;

		for (int j = 0; j < numPad[i]; ++j) {
			Lilypad temp1;
			temp1.set(loadStruct.pads.Pads[i][j].x, loadStruct.pads.Pads[i][j].y, 0);
			temp.push_back(temp1);
		}
		Pads.push_back(temp);
	}

	// Coin on wood
	coinsOnWood.clear();
	nCoinOnWood.clear();
	for (int i = 0; i < lineWood; ++i) {
		int temp2 = loadStruct.coinsOnWood.nCoinOnWood[i];
		nCoinOnWood.push_back(temp2);
		vector<Coin> temp;

		for (int j = 0; j < nCoinOnWood[i]; ++j) {
			Coin temp1;
			temp1.setXC(loadStruct.coinsOnWood.CoinsOnWood[i][j].x);
			temp1.setYC(loadStruct.coinsOnWood.CoinsOnWood[i][j].y);
			temp1.setiX(loadStruct.coinsOnWood.iLineNum[i][j].x);
			temp1.setiY(loadStruct.coinsOnWood.iLineNum[i][j].y);

			temp.push_back(temp1);
		}
		coinsOnWood.push_back(temp);
	}

	// Coin
	coins.clear();
	int count = 0;
	for (int i = 0; i < lineWood; ++i) {
		count += loadStruct.coinsOnWood.nCoinOnWood[i];
	}
	nCoin = count + loadStruct.coins.nCoinOnStreet;
	for (int i = 0; i < loadStruct.coins.nCoinOnStreet; ++i) {
		Coin temp;
		temp.setXC(loadStruct.coins.Coins[i].x);
		temp.setYC(loadStruct.coins.Coins[i].y);
		coins.push_back(temp);
	}

	// People
	people.setXC(loadStruct.people.people.x);
	people.setYC(loadStruct.people.people.y);
	people.loadPeople(loadStruct.people.money, loadStruct.people.model, loadStruct.people.ownedModel);

	// Game
	level = loadStruct.level;
	
	delete[] loadStruct.cars.numCar;
	delete[] loadStruct.cars.spdCar;
	delete[] loadStruct.cars.distance;
	delete[] loadStruct.trains.spdTrain;
	delete[] loadStruct.trains.modeTrain;
	delete[] loadStruct.trains.Trains;
	delete[] loadStruct.woods.numWood;
	delete[] loadStruct.woods.spdWood;
	delete[] loadStruct.pads.numPad;
	delete[] loadStruct.pads.yPad;
	delete[] loadStruct.coins.Coins;
	delete[] loadStruct.coinsOnWood.nCoinOnWood;

	for (int i = 0; i < lineCar; ++i) {
		delete[] loadStruct.cars.Cars[i];
	}
	for (int i = 0; i < lineWood; ++i) {
		delete[] loadStruct.woods.Woods[i];
	}
	for (int i = 0; i < linePad; ++i) {
		delete loadStruct.pads.Pads[i];
	}
	for (int i = 0; i < lineWood; ++i) {
		delete[] loadStruct.coinsOnWood.CoinsOnWood[i];
		delete[] loadStruct.coinsOnWood.iLineNum[i];
	}
}

GAME& GAME::operator=(const GAME& rhs) {
	if (this != &rhs) {
		for (int i = 0; i < lineCar; ++i) {
			delete[] Cars[i];
		}
		delete[] numCar;
		delete[] spdCar;
		delete[] distance;
		delete[] Trains;
		delete[]spdTrain;
		delete[] modeTrain;
		for (int i = 0; i < lineWood; ++i) {
			delete[] Woods[i];
		}
		delete[] numWood;
		delete[] spdWood;
		delete[] numPad;
		delete[] yPad;

		level = rhs.level;
		// Car
		lineCar = rhs.lineCar;
		numCar = new int[lineCar];
		spdCar = new int[lineCar];
		distance = new int[lineCar];
		Cars = new Car*[rhs.lineCar];
		for (int i = 0; i < lineCar; ++i) {
			numCar[i] = rhs.numCar[i];
			spdCar[i] = rhs.spdCar[i];
			distance[i] = rhs.distance[i];

			Cars[i] = new Car[numCar[i]];
		}
		for (int i = 0; i < lineCar; ++i) {
			for (int j = 0; j < numCar[i]; ++j) {
				Cars[i][j] = rhs.Cars[i][j];
			}
		}

		// Train
		lineTrain = rhs.lineTrain;
		spdTrain = new int[lineTrain];
		modeTrain = new int[lineTrain];
		Trains = new Train[lineTrain];
		for (int i = 0; i < lineTrain; ++i) {
			spdTrain[i] = rhs.spdTrain[i];
			modeTrain[i] = rhs.modeTrain[i];
			Trains[i] = rhs.Trains[i];
		}

		// People
		int oldMoney = people.getMoney();
		people = rhs.people;
		people.changeMoney(oldMoney);

		// Wood
		lineWood = rhs.lineWood;
		numWood = new int[lineWood];
		spdWood = new int[lineWood];
		Woods = new Wood*[rhs.lineWood];
		for (int i = 0; i < lineWood; ++i) {
			numWood[i] = rhs.numWood[i];
			spdWood[i] = rhs.spdWood[i];

			Woods[i] = new Wood[numWood[i]];
		}
		for (int i = 0; i < lineWood; ++i) {
			for (int j = 0; j < numWood[i]; ++j) {
				Woods[i][j] = rhs.Woods[i][j];
			}
		}

		// Coin
		nCoin = rhs.nCoin;
		coins = rhs.coins;
		coinsOnWood = rhs.coinsOnWood;
		nCoinOnWood = rhs.nCoinOnWood;
		sampleY = rhs.sampleY;
		sampleYWood = rhs.sampleYWood;

		// Pad
		linePad = rhs.linePad;
		numPad = new int[linePad];
		yPad = new int[linePad];
		Pads = rhs.Pads;
		for (int i = 0; i < linePad; ++i) {
			numPad[i] = rhs.numPad[i];
			yPad[i] = rhs.yPad[i];
		}
	}
	return *this;
}

void GAME::levelUp() {
	GAME up(this->level + 1);
	*this = up;
}

int GAME::getLevel() {
	return level;
}

bool GAME::isEndLevel() {
	if (people.getY() == 4) {
		return true;
	}
	else {
		return false;
	}
}