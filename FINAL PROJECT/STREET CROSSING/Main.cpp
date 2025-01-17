﻿#include "People.h"
#include "Car.h"
#include "Train.h"
#include "GAME.h"
#include "Console.h"
#include "Menu.h"
#include "Wood.h"
#include "Lilypad.h"

#pragma comment (lib, "winmm.lib")

char MOVING = ' ';


int main() {
	srand(time(NULL));
	_setmode(_fileno(stdout), _O_U16TEXT);
	FixConsoleWindow();
	FixSizeWindow(WIDTH, HEIGHT);
	RemoveScrollBar();
	ShowConsoleCursor(false);

	PlaySound("Menu.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);


	/*Car c(-10, 0, 1);
	char key = ' ';
	while (true) {
		c.move();
		c.draw();
		Sleep(50);
	}*/

	/*Train t(158, 1, 4, 0);
	char key = ' ';
	while (true) {
		t.move();
		t.draw();
		Sleep(50);
	}*/

	/*GAME game(1);
	SubThread(game);*/

	/*GAME game(5);
	SubThread(game);*/

	//system("pause");



	// menu work
	GAME game(1);
	Menu m;
	m.ShowTitle();
	bool flagTitle = true;
	int key = 1;
	while (key != 0) {
		m.control();
		key = m.Do(game);
	}
}


