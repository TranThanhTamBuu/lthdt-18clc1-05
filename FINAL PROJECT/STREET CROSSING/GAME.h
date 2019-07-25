#pragma once
#include "People.h"
#include "Car.h"
#include "Train.h"
#include "Wood.h"
#include "Lilypad.h";
#include "Console.h"
#include "Coin.h"
#define COINVALUE 150
#define H_VEHICLE 5


class GAME
{
private:
	Car **Cars;
	int lineCar, *numCar, *spdCar, *distance;

	Train *Trains;
	int lineTrain, *spdTrain, *modeTrain;
	// speed >=2 && speed%2=0 | mode 0: normal, 1:crazy

	People people;

	Wood **Woods;
	int lineWood, *numWood, *spdWood;

	vector<Coin> coins;
	vector<vector<Coin>> coinsOnWood;
	unsigned nCoin;
	vector<int> countNCoin;
	vector<int> sampleY;
	vector<int> sampleYWood;

	vector<vector<Lilypad>> Pads;
	int *yPad, linePad, *numPad;

public:
	GAME(int level);
	~GAME();
	bool chooseModel();
	void updatePosPeople(char);
	void peopleClear();
	void updatePosTrains();
	void updatePosCars();
	void updatePosWoods();
	void updatePosCoinOnWoods();
	bool impactVehicle();
	int impactWoods(); //0: not same line wood | 1: on wood | -1: in river
	int sameLineWoods();

	int impactPads(); //0: not same line wood | 1: on wood | -1: in river
	int sameLinePads();
	void updatePads();

	vector <int> xLineWoods(int line);
	void peopleOnWood(DState dst);
	void peopleOnPad();
	void drawAll();
	bool isEndScr();
	void screenScroll();

	//Coin machine
	void createCoins();
	void handleCoinImpact();

	void createLilypads(int yPad[], int linePad, int *numPad);
};

