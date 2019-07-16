#include "People.h"
#include "Car.h"
#include "Train.h"
#include "GAME.h"
#include "Console.h"
#include "Menu.h"
#include "Wood.h"

char MOVING = ' ';

void SubThread(GAME &game);

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	FixConsoleWindow();
	FixSizeWindow(WIDTH, HEIGHT);
	RemoveScrollBar();
	ShowConsoleCursor(false);


	/*Car c(0, 0, -2);
	char key = ' ';
	while (true) {
		c.move();
		c.draw();
		Sleep(50);
	}*/

	/*Train t(-2, 0);
	char key = ' ';
	while (true) {
		t.move(2);
		t.draw();
		Sleep(50);
	}*/

	
	GAME game(1);
	game.chooseModel();
	SubThread(game);

	

	system("pause");
	//Menu m;
	//m.mainMenu();
	/*Wood w(90, 0, -3);
	char key = ' ';
	while (true) {
		w.move();
		w.draw();
		Sleep(50);
	}*/
	return 0;
}

void SubThread(GAME &game)
{
	while (true) {
		
		if (game.impactVehicle()) {
			exit(0);
		}

		switch (game.impactWoods()) {
		case 0: // not same line wood
			break;
		case 1: // on wood
			game.onWood();
			break;
		case -1: // in river
			exit(0);
			break;
		}

		char key = ' ';
		if (_kbhit())
		{
			int key = _getch();
			
			game.updatePosPeople(key);

		}

		game.updatePosCars();
		game.updatePosTrains();
		game.updatePosWoods();

		// game.updatePos...
		game.screenScroll();
		game.drawAll();
		Sleep(0);
		
		
	}
}

