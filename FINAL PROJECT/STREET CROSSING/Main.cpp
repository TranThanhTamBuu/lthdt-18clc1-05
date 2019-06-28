#include "People.h"

int main() {
	FixConsoleWindow();
	FixSizeWindow(WIDTH, HEIGHT);
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