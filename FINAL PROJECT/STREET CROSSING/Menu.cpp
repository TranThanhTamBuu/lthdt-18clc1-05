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
		wcout << "\tPRESS ANY KEY TO START!";
		Sleep(300);

		setColor(11, 0);
		for (int i = 0; i < 13; i++) {
			gotoXY((X_max - title[0].length()) / 2, 10 + i);
			wcout << title[i] << endl;
		}
		Sleep(300);
		gotoXY(66, 32);
		setColor(11, 0);
		wcout << "\tPRESS ANY KEY TO START!";
		Sleep(300);

	};

	int key = _getch();
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

int Menu::Do(GAME &game) {
	char key = ' ';
	switch (c) {
	case 29: case 30: {
		bool flag = true;
		system("cls");
		if (c == 30) {
			game.load();
		}
		while (flag) {
			flag = SubThread(game);
			if (flag) {
				if (game.getLevel() != 5) {
					game.levelUp();
				}
				else {
					break;
				}
			}
		}
		
		if (flag) {
			//victory
			
		}
		else {
			lose();
			GAME reset(1);
			game = reset;
			return 1;
		}

		break;
	}

	case 31: {
		//setting
		system("cls");
		game.chooseModel();
		key = 27;
		break;
	}

	case 32: {
		system("cls");
		gotoXY(78, 15);
		wcout << "Use A, S, D, E to play";
		Sleep(500);
		break;
	}
	case 33:
	{
		system("cls");
		gotoXY(78, 15);
		wcout << "group 5";
		Sleep(500);
		break;
	}

	case 34: {
		system("cls");
		gotoXY(78, 15);
		wcout << "Bye";
		Sleep(500);
		return 0;
		break;
	}

	}

	while (key != 27) {
		if (_kbhit()) {
			key = _getch();
		}
	}
	return 1;
}

bool SubThread(GAME &game)
{
	switch (game.getLevel()) {
	case 1:
		level_1();
		break;
	case 2:
		level_2();
		break;
	case 3:
		level_3();
		break;
	case 4:
		level_4();
		break;
	case 5:
		level_5();
		break;
	}

	setColor(7, 0);

	system("cls");

	//draw line
	for (int i = 0; i <= 5; i++) {
		gotoXY(0, 0 + 8 * i);	printLine(X_max);
	}

	while (true) {
		game.handleCoinImpact();
		if (game.impactVehicle()) {
			/*game.~GAME();
			exit(0);*/
			return false;
		}

		switch (game.impactWoods()) {
		case 0: // not same line wood
			break;
		case 1: // on wood
			game.peopleOnWood();
			break;
		case -1: // in river
			/*game.~GAME();
			exit(0);*/
			return false;
			break;
		}

		switch (game.impactPads()) {
		case 0: // not same line wood
			break;
		case 1: // on wood

			game.peopleOnPad();
			//game.peopleOnWood(RIGHT); // lam cai on Lilipad
			break;
		case -1: // in river
			/*game.~GAME();
			exit(0);*/
			return false;
			break;
		}

		char key = ' ';
		if (_kbhit())
		{
			int key = _getch();

			if (key != 27) {
				game.updatePosPeople(key);
			}
			else {
				system("cls");
				saveScr(game);
				system("cls");
				//draw line
				for (int i = 0; i <= 5; i++) {
					gotoXY(0, 0 + 8 * i);	printLine(X_max);
				}
			}

		}

		game.updatePosCars();
		game.updatePosTrains();
		game.updatePosCoinOnWoods();
		game.updatePosWoods();
		game.updatePads();

		// game.updatePos...
		game.screenScroll();
		game.drawAll();

		Sleep(25);

		if (game.isEndLevel()) {
			return true;
		}
		//game.save();
	}
}

void Menu::control()
{
	printMenu(menu, 6);
	c = Choice();
}

void lose()
{
	system("cls");
	setColor(14, 0);
	gotoXY(5, 6);
	wcout << "                                                                                                                                       _____   " << endl;
	wcout << "\t\t ______   _____         ____      ______   _____             _____                    ____                  _____      _____\\    \\ " << endl;
	wcout << "\t\t|\\     \\ |     |    ____\\_  \\__   \\     \\  \\    \\           |\\    \\               ____\\_  \\__          _____\\    \\    /    / |    | " << endl;
	wcout << "\t\t\\ \\     \\|     |   /     /     \\   \\    |  |    |            \\\\    \\             /     /     \\        /    / \\    |  /    /  /___/| " << endl;
	wcout << "\t\t \\ \\           |  /     /\\      |   |   |  |    |             \\\\    \\           /     /\\      |      |    |  /___/| |    |__ |___|/ " << endl;
	wcout << "\t\t  \\ \\____      | |     |  |     |   |    \\_/   /|              \\|    | ______  |     |  |     |   ____\\    \\ |   || |       \\       " << endl;
	wcout << "\t\t   \\|___/     /| |     |  |     |   |\\         \\|               |    |/      \\ |     |  |     |  /    /\\    \\|___|/ |     __/ __    " << endl;
	wcout << "\t\t       /     / | |     | /     /|   | \\         \\__             /            | |     | /     /| |    |/ \\    \\      |\\    \\  /  \\   " << endl;
	wcout << "\t\t      /_____/  / |\\     \\_____/ |    \\ \\_____/\\    \\           /_____/\\_____/| |\\     \\_____/ | |\\____\\ /____/|     | \\____\\/    |  " << endl;
	wcout << "\t\t      |     | /  | \\_____\\   | /      \\ |    |/___/|          |      | |    || | \\_____\\   | /  | |   ||    | |     | |    |____/|  " << endl;
	wcout << "\t\t      |_____|/    \\ |    |___|/        \\|____|   | |          |______|/|____|/  \\ |    |___|/    \\|___||____|/       \\|____|   | |  " << endl;
	wcout << "\t\t                   \\|____|                   |___|/                              \\|____|                                   |___|/   " << endl;
	Sleep(300);
	gotoXY(66, 24);
	setColor(14, 0);
	wcout << "\tPRESS ANY KEY TO CONTINUE!";
	Sleep(300);

	PlaySound("ambulance.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	Car c(ambulance, -15, 30, 2);
	while (!_kbhit()) {
		c.moveLose();
		c.draw();
		Sleep(50);

	};
	int key = _getch();
}

void win(){
	system("cls");
	PlaySound("applause3.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	while (!_kbhit()) {
		setColor(14, 0);
		gotoXY(5, 15);
		wcout << "\t\t\t\t      ___           ___           ___                    ___                       ___     " << endl;
		wcout << "\t\t\t\t     |\\__\\         /\\  \\         /\\__\\                  /\\__\\          ___        /\\__\\    " << endl;
		wcout << "\t\t\t\t     |:|  |       /::\\  \\       /:/  /                 /:/ _/_        /\\  \\      /::|  |   " << endl;
		wcout << "\t\t\t\t     |:|  |      /:/\\:\\  \\     /:/  /                 /:/ /\\__\\       \\:\\  \\    /:|:|  |   " << endl;
		wcout << "\t\t\t\t     |:|__|__   /:/  \\:\\  \\   /:/  /  ___            /:/ /:/ _/_      /::\\__\\  /:/|:|  |__ " << endl;
		wcout << "\t\t\t\t     /::::\\__\\ /:/__/ \\:\\__\\ /:/__/  /\\__\\          /:/_/:/ /\\__\\  __/:/\\/__/ /:/ |:| /\\__\\" << endl;
		wcout << "\t\t\t\t    /:/~~/~    \\:\\  \\ /:/  / \\:\\  \\ /:/  /          \\:\\/:/ /:/  / /\\/:/  /    \\/__|:|/:/  /" << endl;
		wcout << "\t\t\t\t   /:/  /       \\:\\  /:/  /   \\:\\  /:/  /            \\::/_/:/  /  \\::/__/         |:/:/  / " << endl;
		wcout << "\t\t\t\t   \\/__/         \\:\\/:/  /     \\:\\/:/  /              \\:\\/:/  /    \\:\\__\\         |::/  /  " << endl;
		wcout << "\t\t\t\t                  \\::/  /       \\::/  /                \\::/  /      \\/__/         /:/  /   " << endl;
		wcout << "\t\t\t\t                   \\/__/         \\/__/                  \\/__/                     \\/__/    " << endl;

		Sleep(300);
		gotoXY(64, 35);
		wcout << "\tPRESS ANY KEY TO CONTINUE!";
		Sleep(300);


		setColor(4, 0);
		gotoXY(5, 15);
		wcout << "\t\t\t\t                    ___           ___                    ___                       ___     " << endl;
		wcout << "\t\t\t\t                   /\\  \\         /\\  \\                  /\\  \\                     /\\  \\    " << endl;
		wcout << "\t\t\t\t        ___       /::\\  \\        \\:\\  \\                _\\:\\  \\       ___          \\:\\  \\   " << endl;
		wcout << "\t\t\t\t       /|  |     /:/\\:\\  \\        \\:\\  \\              /\\ \\:\\  \\     /\\__\\          \\:\\  \\  " << endl;
		wcout << "\t\t\t\t      |:|  |    /:/  \\:\\  \\   ___  \\:\\  \\            _\\:\\ \\:\\  \\   /:/__/      _____\\:\\  \\ " << endl;
		wcout << "\t\t\t\t      |:|  |   /:/__/ \\:\\__\\ /\\  \\  \\:\\__\\          /\\ \\:\\ \\:\\__\\ /::\\  \\     /::::::::\\__\\" << endl;
		wcout << "\t\t\t\t    __|:|__|   \\:\\  \\ /:/  / \\:\\  \\ /:/  /          \\:\\ \\:\\/:/  / \\/\\:\\  \\__  \\:\\~~\\~~\\/__/" << endl;
		wcout << "\t\t\t\t   /::::\\  \\    \\:\\  /:/  /   \\:\\  /:/  /            \\:\\ \\::/  /   ~~\\:\\/\\__\\  \\:\\  \\      " << endl;
		wcout << "\t\t\t\t   ~~~~\\:\\  \\    \\:\\/:/  /     \\:\\/:/  /              \\:\\/:/  /       \\::/  /   \\:\\  \\     " << endl;
		wcout << "\t\t\t\t        \\:\\__\\    \\::/  /       \\::/  /                \\::/  /        /:/  /     \\:\\__\\    " << endl;
		wcout << "\t\t\t\t         \\/__/     \\/__/         \\/__/                  \\/__/         \\/__/       \\/__/    " << endl;

		Sleep(300);
		gotoXY(64, 35);
		wcout << "\tPRESS ANY KEY TO CONTINUE!";
		Sleep(300);
	}
}

void level_1() {

	system("cls");
	int i = 0;
	while (i < 5) {
		setColor(14, 0);

		for (int i = 0; i < 9; i++) {
			gotoXY((X_max - level1[0].length()) / 2, 15 + i);
			wcout << level1[i] << endl;
		}
		Sleep(300);

		setColor(11, 0);
		for (int i = 0; i < 9; i++) {
			gotoXY((X_max - level1[0].length()) / 2, 15 + i);
			wcout << level1[i] << endl;
		}
		Sleep(300);
		
		i++;
	};

}

void level_2() {
	system("cls");
	int i = 0;
	while (i < 5){ 

		setColor(11, 0);
		for (int i = 0; i < 8; i++) {
			gotoXY((X_max - level2[0].length()) / 2, 15 + i);
			wcout << level2[i] << endl;
		}
		Sleep(300);

		setColor(14, 0);
		gotoXY(120, 4);
		wcout << "       .''.      .       " << endl;
		gotoXY(120, 5);
		wcout << "      :_\\/_:   _\\(/_  .:." << endl;
		gotoXY(120, 6);
		wcout << "  .''.: /\\ :   ./)\\   ':'" << endl;
		gotoXY(120, 7);
		wcout << " :_\\/_:'.:::.    ' *''*  " << endl;
		gotoXY(120, 8);
		wcout << " : /\\ : :::::     *_\\/_* " << endl;
		gotoXY(120, 9);
		wcout << "  '..'  ':::'     * /\\ * " << endl;
		gotoXY(120, 10);
		wcout << "                   *..*   " << endl;
		Sleep(300);

		gotoXY(5, 4);
		wcout << "          .''.           " << endl;
		gotoXY(5, 5);
		wcout << " *''*    :_\\/_:     .    " << endl;
		gotoXY(5, 6);
		wcout << "*_\\/_*   : /\\ :  .'.:.'. " << endl;
		gotoXY(5, 7);
		wcout << "* /\\ * :  '..'.  -=:o:=- " << endl;
		gotoXY(5, 8);
		wcout << "  * '.\\'/.' _\\(/_'.':'.' " << endl;
		gotoXY(5, 9);
		wcout << "    -= o =-  /)\\    '  * " << endl;
		gotoXY(5, 10);
		wcout << "    .'/.\\'.   '          " << endl;
		gotoXY(5, 11);
		wcout << "       :" << endl;
		Sleep(300);

		setColor(4, 0);
		gotoXY(120, 4);
		wcout << "       .''.      .       " << endl;
		gotoXY(120, 5);
		wcout << "      :_\\/_:   _\\(/_  .:." << endl;
		gotoXY(120, 6);
		wcout << "  .''.: /\\ :   ./)\\   ':'" << endl;
		gotoXY(120, 7);
		wcout << " :_\\/_:'.:::.    ' *''*  " << endl;
		gotoXY(120, 8);
		wcout << " : /\\ : :::::     *_\\/_* " << endl;
		gotoXY(120, 9);
		wcout << "  '..'  ':::'     * /\\ * " << endl;
		gotoXY(120, 10);
		wcout << "                   *..*   " << endl;
		Sleep(300);

		gotoXY(5, 4);
		wcout << "          .''.           " << endl;
		gotoXY(5, 5);
		wcout << " *''*    :_\\/_:     .    " << endl;
		gotoXY(5, 6);
		wcout << "*_\\/_*   : /\\ :  .'.:.'. " << endl;
		gotoXY(5, 7);
		wcout << "* /\\ * :  '..'.  -=:o:=- " << endl;
		gotoXY(5, 8);
		wcout << "  * '.\\'/.' _\\(/_'.':'.' " << endl;
		gotoXY(5, 9);
		wcout << "    -= o =-  /)\\    '  * " << endl;
		gotoXY(5, 10);
		wcout << "    .'/.\\'.   '          " << endl;
		gotoXY(5, 11);
		wcout << "       :" << endl;

		setColor(11, 0);
		gotoXY(120, 4);
		wcout << "       .''.      .       " << endl;
		gotoXY(120, 5);
		wcout << "      :_\\/_:   _\\(/_  .:." << endl;
		gotoXY(120, 6);
		wcout << "  .''.: /\\ :   ./)\\   ':'" << endl;
		gotoXY(120, 7);
		wcout << " :_\\/_:'.:::.    ' *''*  " << endl;
		gotoXY(120, 8);
		wcout << " : /\\ : :::::     *_\\/_* " << endl;
		gotoXY(120, 9);
		wcout << "  '..'  ':::'     * /\\ * " << endl;
		gotoXY(120, 10);
		wcout << "                   *..*   " << endl;
		Sleep(300);

		gotoXY(5, 4);
		wcout << "          .''.           " << endl;
		gotoXY(5, 5);
		wcout << " *''*    :_\\/_:     .    " << endl;
		gotoXY(5, 6);
		wcout << "*_\\/_*   : /\\ :  .'.:.'. " << endl;
		gotoXY(5, 7);
		wcout << "* /\\ * :  '..'.  -=:o:=- " << endl;
		gotoXY(5, 8);
		wcout << "  * '.\\'/.' _\\(/_'.':'.' " << endl;
		gotoXY(5, 9);
		wcout << "    -= o =-  /)\\    '  * " << endl;
		gotoXY(5, 10);
		wcout << "    .'/.\\'.   '          " << endl;
		gotoXY(5, 11);
		wcout << "       :" << endl;

		i++;
	};
}

void level_3() {

	system("cls"); 
	int i = 0;
	setColor(12, 0);
	Car c(level3, 160, 17, -2);
	while (i < 60) {
		c.movelevel();
		c.draw();
		Sleep(50);
		i++;
	};
	
}

void level_4() {
	
	int i = 0;
	while (i < 5) {

		system("cls");

		setColor(11, 0);
		for (int i = 0; i < 9; i++) {
			gotoXY((X_max - level4_1[0].length()) / 2, 15 + i);
			wcout << level4_1[i] << endl;
		}
		Sleep(500);

		system("cls");

		setColor(14, 0);
		for (int i = 0; i < 9; i++) {
			gotoXY((X_max - level4[0].length()) / 2, 15 + i);
			wcout << level4[i] << endl;
		}
		Sleep(500);

		i++;
	}

}

void level_5() {
	system("cls");
	int i = 0;
	while (i < 5) {

		system("cls");
		setColor(11, 0);
		for (int i = 0; i < 9; i++) {
			gotoXY(70, 5 + i);
			wcout << level5[i] << endl;
		}
		Sleep(500);

		system("cls");

		setColor(14, 0);
		for (int i = 0; i < 9; i++) {
			gotoXY(4, 26 + i);
			wcout << level5[i] << endl;
		}
		Sleep(500);

		i++;
	}
}

void saveScr(GAME &game) {
	wcout << "Do you want to overwrite save file? [Y/N]" << endl;
	int key = _getch();
	switch (key) {
	case 89: case 121: {
		game.save();
		wcout << "Your progress has been saved!" << endl;
		break;
	}
	case 78: case 110: {
		wcout << "Your progress hasn't been saved!" << endl;
		break;
	}
	}
	wcout << "PRESS ANY KEY TO CONTINUE" << endl;
	key = _getch();
}

void MenuSave() {

	system("cls");
	gotoXY(60, 13);
	wcout << " ____  ____  ____  _  _  _  _  ____ " << endl;
	gotoXY(60, 14);
	wcout << "(  _ \\(  __)/ ___)/ )( \\( \\/ )(  __)" << endl;
	gotoXY(60, 15);
	wcout << " )   / ) _) \\___ \\) \\/ (/ \\/ \\ ) _) " << endl;
	gotoXY(60, 16);
	wcout << "(__\\_)(____)(____/\\____/\\_)(_/(____)" << endl;

	gotoXY(51, 19);
	wcout << " ____   __   _  _  ____         ___   __   _  _  ____ " << endl;
	gotoXY(51, 20);
	wcout << "/ ___) / _\\ / )( \\(  __)       / __) / _\\ ( \\/ )(  __)" << endl;
	gotoXY(51, 21);
	wcout << "\\___ \\/    \\\\ \\/ / ) _)       ( (_ \\/    \\/ \\/ \\ ) _) " << endl;
	gotoXY(51, 22);
	wcout << "(____/\\_/\\_/ \\__/ (____)       \\___/\\_/\\_/\\_)(_/(____)" << endl;

	gotoXY(51, 25);
	wcout << "  ___  _  _   __   ____   __    ___  ____  ____  ____ " << endl;
	gotoXY(51, 26);
	wcout << " / __)/ )( \\ / _\\ (  _ \\ / _\\  / __)(_  _)(  __)(  _ \\ " << endl;
	gotoXY(51, 27);
	wcout << "( (__ ) __ (/    \\ )   //    \\( (__   )(   ) _)  )   /" << endl;
	gotoXY(51, 28);
	wcout << " \\___)\\_)(_/\\_/\\_/(__\\_)\\_/\\_/ \\___) (__) (____)(__\\_)" << endl;

	char x;
	int line = 7;
	gotoXY(0, line);

	while (true) {
		if (_kbhit) {
			x = _getch();
			switch (x) {
			case 80:
			case 83:
			case 115:
			{
				gotoXY(30, line);
				wcout << "              ";
				gotoXY(30, line + 1);
				wcout << "              ";
				gotoXY(30, line + 2);
				wcout << "              ";
				gotoXY(30, line + 3);
				wcout << "              ";
				line += 6;
				if (line > 28) { line = 13; }
				gotoXY(30, line);
				wcout << " __    __   ";
				gotoXY(30, line + 1);
				wcout << " \\ \\   \\ \\  ";
				gotoXY(30, line + 2);
				wcout << "  ) )   ) ) ";
				gotoXY(30, line + 3);
				wcout << " /_/   /_/  ";
				break;
			}
			case 72:
			case 87:
			case 119:
			{
				gotoXY(30, line);
				wcout << "              ";
				gotoXY(30, line + 1);
				wcout << "              ";
				gotoXY(30, line + 2);
				wcout << "              ";
				gotoXY(30, line + 3);
				wcout << "              ";
				line -= 6;
				if (line < 13) line = 25;
				gotoXY(30, line);
				wcout << " __    __   ";
				gotoXY(30, line + 1);
				wcout << " \\ \\   \\ \\  ";
				gotoXY(30, line + 2);
				wcout << "  ) )   ) ) ";
				gotoXY(30, line + 3);
				wcout << " /_/   /_/  ";
				break;
			}
			case 13:
			{
				char key = ' ';
				switch (line) {
				case 13: {
					//resume
					break;
				}

				case 19: {
					//SAVE GAME
					break;
				}

				case 25: {
					//CHARACTER
					break;
				}
				}
				break;
			}
			}
		}
	}
}


Menu::~Menu()
{

}