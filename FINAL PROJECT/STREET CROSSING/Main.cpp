#include "People.h"
#include "Car.h"
#include "Train.h"
#include "GAME.h"
#include "Console.h"


char MOVING = ' ';

void SubThread(GAME &game);

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

	
	GAME game;
	SubThread(game);

	system("pause");
	return 0;
}

void SubThread(GAME &game)
{
	Train t(158, 0);
	Car c(-20, 7);

	while (true) {

		//Viet cai di chuyen cua People vao day di dai
		// Test character movement
		_setmode(_fileno(stdout), _O_U16TEXT);
		char key;
		if (_kbhit())
		{
			int key = _getch();
			clrscr();
			game.updatePosPeople(key);
			// game.updatePos...
			// game.updatePos...
			game.drawAll();
		}

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