#pragma once
#include "People.h"
#include "Car.h"
#include "Train.h"
#include "Wood.h"
#include <vector>
#include "Console.h"
#include "Coin.h"
#define COINVALUE 150


class GAME
{
private:
	Car **Cars;
	int lineCar, *numCar, *spdCar, *distance;

	Train *Trains;
	int lineTrain, *spdTrain;

	People people;

	Wood **Woods;
	int lineWood, *numWood, *spdWood;

	vector<Coin> coins;
	vector<vector<Coin>> coinsOnWood;
	unsigned nCoin;
	vector<int> countNCoin;

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
	vector <int> xLineWoods(int line);
	void peopleOnWood();
	void drawAll();
	bool isEndScr();
	void screenScroll();

	//Coin machine
	void createCoins();
	void handleCoinImpact();

};

