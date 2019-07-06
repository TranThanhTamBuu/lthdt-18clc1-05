#include "People.h"
#include "Car.h"
#include "Train.h"
#include "GAME.h"
#include "Console.h"

char MOVING = ' ';

void SubThread();

int main() {
	FixConsoleWindow();
	FixSizeWindow(WIDTH, HEIGHT);
	RemoveScrollBar();
	ShowConsoleCursor(false);
	
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
	/*_setmode(_fileno(stdout), _O_U16TEXT);
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
	}*/

	SubThread();

	system("pause");
	return 0;
}

void SubThread()
{
	People p;
	Train t(158, 0);
	Car c(-20, 7);

	while (true) {

		//Viet cai di chuyen cua People vao day di dai

		MOVING = ' ';
		c.move(-1);
		t.move(1);
		Sleep(50);
	}
}