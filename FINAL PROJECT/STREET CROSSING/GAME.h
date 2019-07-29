#pragma once
#include "People.h"
#include "Car.h"
#include "Train.h"
#include "Wood.h"
#include "Lilypad.h";
#include "Console.h"
#include "Coin.h"
#include <stdint.h>
#include <fstream>
#define COINVALUE 150
#define H_VEHICLE 5


class GAME
{
private:
	int level;

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
	int nCoin;
	vector<int> nCoinOnWood;
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
	void peopleOnWood();
	void peopleOnPad();
	void drawAll();
	bool isEndScr();
	void screenScroll();

	//Coin machine
	void createCoins();
	void handleCoinImpact();

	// Lilypad
	void createLilypads(int yPad[], int linePad, int *numPad);

	// Save and Load
	void save(bool saveAs = false);
	void load(bool loadFrom = false);

	// Operator
	GAME& operator=(const GAME& rhs);
	void levelUp();

	int getLevel();
	bool isEndLevel();
};


// For save and load game
struct Point {
	int32_t x;
	int32_t y;
};

struct StructCar {
	int32_t lineCar;
	int32_t* numCar;
	int32_t* spdCar;
	int32_t *distance;
	Point** Cars;
};

struct StructTrain {
	int32_t lineTrain;
	int32_t* spdTrain;
	int32_t* modeTrain;
	Point* Trains;
};

struct StructWood {
	int32_t lineWood;
	int32_t* numWood;
	int32_t*spdWood;
	Point** Woods;
};

struct StructPad {
	int32_t linePad;
	int32_t* yPad;
	int32_t* numPad;
	Point** Pads;
};

struct StructCoin {
	int32_t nCoinOnStreet;
	Point* Coins;
};

struct StructCoinOnWood {
	int32_t* nCoinOnWood;
	Point** CoinsOnWood;
	Point** iLineNum;
};

struct StructPeople {
	int32_t money;
	int32_t model;
	int32_t ownedModel[5];
	Point people;
};

struct SaveLoad {
	int32_t level;
	StructPeople people;
	StructCar cars;
	StructTrain trains;
	StructWood woods;
	StructPad pads;
	StructCoin coins;
	StructCoinOnWood coinsOnWood;
};
