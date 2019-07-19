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

	


	GAME game(1);
	SubThread(game);

	
	
	//system("pause");



	// menu work
	/*GAME game(1);
	Menu m;
	m.ShowTitle();
	int key = 1;
	while (key != 0) {
		m.control();
		key = m.Do(game);
	}*/

}


