#include "People.h"
#include "Car.h"
#include "Train.h"
#include "GAME.h"
#include "Console.h"
#include "Menu.h"
#include "Wood.h"

char MOVING = ' ';


int main() {
	srand(time(NULL));
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

	
	/*GAME game(1);
	game.chooseModel();
	SubThread(game);*/

	

	//system("pause");
	Menu m;
	m.mainMenu();
	/*Wood w(90, 0, -3);
	char key = ' ';
	while (true) {
		w.move();
		w.draw();
		Sleep(50);
	}*/
	return 0;
}


