#include "People.h"
#include "Car.h"
#include "Train.h"
#include "GAME.h"
#include "Console.h"

int main() {
	FixConsoleWindow();
	FixSizeWindow(WIDTH, HEIGHT);
	RemoveScrollBar();

	/*Car c(-20, 0);
	char key = ' ';
	while (true) {
		c.move(-1);
		Sleep(50);
	}*/

	/*Train t(158, 0);
	char key = ' ';
	while (true) {
		t.move(1);
		Sleep(50);
	}*/

	// Test character movement
	_setmode(_fileno(stdout), _O_U16TEXT);
	People p;
	while (true) {
		char key;
		if (_kbhit())
		{
			int key = _getch();
			clrscr();
			p.updatePosPeople(key);
			p.draw();
		}
	}

	system("pause");
	return 0;
}