#include "People.h"
#include <conio.h>


int main() {
	FixConsoleWindow();
	FixSizeWindow(1280, 720);
	RemoveScrollBar();
	People player;
	char key = ' ';
	player.draw();
	while (true) {
		key = _getch();
		player.move(key);
	}
	system("pause");
	return 0;
}