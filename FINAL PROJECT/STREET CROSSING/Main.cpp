#include "People.h"
#include "Car.h"
#include "Train.h"
#include "GAME.h"
#include "Console.h"
#include "Menu.h"
#include "Wood.h"
#include "Lilypad.h"

char MOVING = ' ';


int main() {
	srand(time(NULL));
	_setmode(_fileno(stdout), _O_U16TEXT);
	FixConsoleWindow();
	FixSizeWindow(WIDTH, HEIGHT);
	RemoveScrollBar();
	ShowConsoleCursor(false);


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


<<<<<<< HEAD
	/*GAME game(1);
	SubThread(game);*/
=======
	GAME game(4);
	SubThread(game);
>>>>>>> 3c62e0496fa5b23d00a59f0ed2dbe7a7926ed8ad

	//system("pause");



	// menu work
	GAME game(1);
	Menu m;
	m.ShowTitle();
	int key = 1;
	while (key != 0) {
		m.control();
		key = m.Do(game);
	}

}


