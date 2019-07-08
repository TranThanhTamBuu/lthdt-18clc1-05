#include "People.h"
#include "Car.h"
#include "Train.h"
#include "GAME.h"
#include "Console.h"

char MOVING = ' ';

void SubThread(GAME &game);

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	FixConsoleWindow();
	FixSizeWindow(WIDTH, HEIGHT);
	RemoveScrollBar();
	ShowConsoleCursor(false);


	/*Car c(1, 0, -5);
	char key = ' ';
	while (true) {
		c.move();
		c.draw();
		Sleep(50);
	}*/

	/*Train t(-5, 0, 1);
	char key = ' ';
	while (true) {
		t.move();
		t.draw();
		Sleep(50);
	}*/

	
	GAME game(1);
	SubThread(game);

	

	system("pause");
	return 0;
}

void SubThread(GAME &game)
{
	while (true) {
		//clrscr();
		char key = ' ';
		if (_kbhit())
		{
			int key = _getch();
			
			game.updatePosPeople(key);

		}
		game.updatePosCars();
		game.updatePosTrains();
		// game.updatePos...
		game.drawAll();
		Sleep(50);
		// Ông mở cái này ra chạy chung với cái di chuyển của tui ở trên là bị lỗi,
		
		/*MOVING = ' ';
		c.move(-1);
		t.move(1);
		Sleep(50);*/


		// tại phải xài wcout hết mới được, string thì wstring, cin thì wcin, char thì wchar_t
		// ví dụ, phải thêm chữ L ngoài trước
		// wstring str;
		// str = L"Test";
		// wcout << str << endl;
	}
}

