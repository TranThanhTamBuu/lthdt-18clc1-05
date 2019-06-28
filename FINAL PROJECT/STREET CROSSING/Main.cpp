#include "People.h"
#include <conio.h>


int main() {
	People player;
	char key = ' ';

	while (true) {
		key = _getch();
		player.move(key);
	}

	system("pause");
	return 0;
}