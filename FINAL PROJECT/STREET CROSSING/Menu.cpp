#include "Menu.h"

Menu::Menu()
{
	title = u;
}

void Menu::ShowTitle()
{
	while (!_kbhit())
	{
		setColor(12, 0);

		for (int i = 0; i < 13; i++) {
			gotoXY((X_max - title[0].length()) / 2, 10 + i);
			wcout << title[i] << endl;
		}
		Sleep(300);
		gotoXY(66, 32);
		setColor(14, 0);
		wcout << "\tPRESS ENTER TO PLAY!";
		Sleep(300);

		setColor(11, 0);
		for (int i = 0; i < 13; i++) {
			gotoXY((X_max - title[0].length()) / 2, 10 + i);
			wcout << title[i] << endl;
		}
		Sleep(300);
		gotoXY(66, 32);
		setColor(11, 0);
		wcout << "\tPRESS ENTER TO PLAY!";
		Sleep(300);
	};
}

void Menu::printMenu(wstring menu[], int n)
{
	system("cls");
	setColor(14, 0);
	gotoXY(5, 6);
	wcout << "\t\t\t ____    __                        __        ____                                                         " << endl;
	wcout << "\t\t\t/\\  _`\\ /\\ \\__                    /\\ \\__    /\\  _`\\                                __                     " << endl;
	wcout << "\t\t\t\\ \\,\\L\\_\\ \\ ,_\\  _ __    __     __\\ \\ ,_\\   \\ \\ \\/\\_\\  _ __   ___     ____    ____/\\_\\    ___      __     " << endl;
	wcout << "\t\t\t \\/_\\__ \\\\ \\ \\/ /\\`'__\\/'__`\\ /'__`\\ \\ \\/    \\ \\ \\/_/_/\\`'__\\/ __`\\  /',__\\  /',__\\/\\ \\ /' _ `\\  /'_ `\\   " << endl;
	wcout << "\t\t\t   /\\ \\L\\ \\ \\ \\_\\ \\ \\//\\  __//\\  __/\\ \\ \\_    \\ \\ \\L\\ \\ \\ \\//\\ \\L\\ \\/\\__, `\\/\\__, `\\ \\ \\/\\ \\/\\ \\/\\ \\L\\ \\  " << endl;
	wcout << "\t\t\t   \\ `\\____\\ \\__\\\\ \\_\\\\ \\____\\ \\____\\\\ \\__\\    \\ \\____/\\ \\_\\\\ \\____/\\/\\____/\\/\\____/\\ \\_\\ \\_\\ \\_\\ \\____ \\ " << endl;
	wcout << "\t\t\t    \\/_____/\\/__/ \\/_/ \\/____/\\/____/ \\/__/     \\/___/  \\/_/ \\/___/  \\/___/  \\/___/  \\/_/\\/_/\\/_/\\/___L\\ \\" << endl;
	wcout << "\t\t\t                                                                                                   /\\____/" << endl;
	wcout << "\t\t\t                                                                                                   \\_/__/ " << endl;	


	gotoXY(67, 22);
	wcout << "WELCOME TO STREET CROSSING GAME!";

	setColor(11, 0);
	gotoXY(57, 27);
	wcout << "*************************************************" << endl;
	gotoXY(57, 28);
	wcout << "**                                             **" << endl;
	gotoXY(57, 29);
	wcout << "**                                             **" << endl;
	gotoXY(57, 30);
	wcout << "**                                             **" << endl;
	gotoXY(57, 31);
	wcout << "**                                             **" << endl;
	gotoXY(57, 32);
	wcout << "**                                             **" << endl;
	gotoXY(57, 33);
	wcout << "**                                             **" << endl;
	gotoXY(57, 34);
	wcout << "**                                             **" << endl;
	gotoXY(57, 35);
	wcout << "**                                             **" << endl;
	gotoXY(57, 36);
	wcout << "*************************************************" << endl;

	for (int i = 0; i < n; i++) {
		setColor(7, 0);
		gotoXY(77, 29 + i);
		wcout << menu[i] << endl;
	}
}

int Menu::Choice()
{
	char x;
	int line = 28;
	gotoXY(0, line);

	while (true) {
		if (_kbhit) {
			x = _getch();
			switch (x) {
			case 80:
			case 83:
			case 115:
			{
				gotoXY(67, line);
				wcout << "  ";
				line++;
				if (line > 34) { line = 29; }
				gotoXY(67, line);
				wcout << ">>";
				break;
			}
			case 72:
			case 87:
			case 119:
			{
				gotoXY(67, line);
				wcout << "  ";
				line--;
				if (line < 29) line = 34;
				gotoXY(67, line);
				wcout << ">>";
				break;
			}
			case 13: 
			{
				return line;
				break;
			}
			}
		}
	}
}

void Menu::Do() {
	c = Choice();
	while (true) {
		switch (c) {
		case 32:
		{
			system("cls");
			gotoXY(78, 15);
			wcout << "Use A, S, D, E to play";
			Sleep(500);
			if (_kbhit()) {
				char z = _getch();
				if (z == 27) {
					control();
				}
			}
			break;
		}
		case 33:
		{
			system("cls");
			gotoXY(78, 15);
			wcout << "group 5";
			Sleep(500);
			if (_kbhit()) {
				char z = _getch();
				if (z == 27) {
					control();
				}
			}
			break;
		}
		case 34:
		{
			system("cls");
			gotoXY(78, 15);
			wcout << "Bye";
			Sleep(500);
			if (_kbhit()) {
				char z = _getch();
				if (z == 27) {
					control();
				}
			}
			break;
		}
		}
		
	}
}

void Menu::control()
{
	printMenu(menu, 6);
	c = Choice();
}

void Menu::mainMenu() {
	Menu m;
	m.ShowTitle();
	m.control();
	m.Do();
}

Menu::~Menu()
{
	delete[]title;
}
