#include "People.h"
#include "Car.h"
#include "Train.h"


int main() {
	FixConsoleWindow();
	FixSizeWindow(WIDTH, HEIGHT);
	RemoveScrollBar();

	/*People player;
	char key = ' ';
	player.draw();
	while (true) {
		key = _getch();
		player.move(key);
	}
	system("pause");
	return 0;*/

	/*Car c(-20, 0);
	char key = ' ';
	while (true) {
		c.move(-1);
		Sleep(50);
	}*/

	Train t(158, 0);
	char key = ' ';
	while (true) {
		t.move(1);
		Sleep(50);
	}
}