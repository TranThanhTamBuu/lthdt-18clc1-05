#pragma once

#include "Console.h"
#include "conio.h"
#include <string>
#include <ostream>
#include <Windows.h>
#include "GAME.h"

using namespace std;

static wstring t[6] = {
	L"         ____    _                          _        ____                              _                 ",
	L"\t\t\t\t / ___|  | |_   _ __    ___    ___  | |_     / ___|  _ __    ___    ___   ___  (_)  _ __     __ _ ",
	L"\t\t\t\t \\___ \\  | __| | '__|  / _ \\  / _ \\ | __|   | |     | '__|  / _ \\  / __| / __| | | | '_ \\   / _` |",
	L"\t\t\t\t  ___) | | |_  | |    |  __/ |  __/ | |_    | |___  | |    | (_) | \\__ \\ \\__ \\ | | | | | | | (_| |",
	L"\t\t\t\t |____/   \\__| |_|     \\___|  \\___|  \\__|    \\____| |_|     \\___/  |___/ |___/ |_| |_| |_|  \\__, |",
	L"\t\t\t\t                                                                                            |___/ "
};

static wstring u[13] = {
	L"  .--.--.      ___                               ___     ,----..                                                                      ",
	L" /  /    '.  ,--.'|_                           ,--.'|_  /   /   \\                                        ,--,                         ",
	L"|  :  /`. /  |  | :,'  __  ,-.                 |  | :,'|   :     : __  ,-.  ,---.                      ,--.'|        ,---,            ",
	L";  |  |--`   :  : ' :,' ,'/ /|                 :  : ' :.   |  ;. ,' ,'/ /| '   ,'\\  .--.--.   .--.--.  |  |,     ,-+-. /  | ,----._,. ",
	L"|  :  ;_   .;__,'  / '  | |' |,---.    ,---. .;__,'  / .   ; /--`'  | |' |/   /   |/  /    ' /  /    ' `--'_    ,--.'|'   |/   /  ' / ",
	L" \\  \\    `.|  |   |  |  |   ,/     \\  /     \\|  |   |  ;   | ;   |  |   ,.   ; ,. |  :  /`./|  :  /`./ ,' ,'|  |   |  ,'' |   :     | ",
	L"  __ \\  \\  | '  : |__|  | '.    ' / .    ' / | '  : |__.   | '___|  | '  '   | .; :\\  \\    `.\\  \\    `.|  | :  |   | |  | .   ; ';  | ",
	L" /  /`--'  / |  | '.';  : |'   ;   /'   ;   /| |  | '.''   ; : .';  : |  |   :    | `----.   \\`----.   '  : |__|   | |  |/'   .   . | ",
	L"'--'.     /  ;  :    |  , ;'   |  / '   |  / | ;  :    '   | '/  |  , ;   \\   \\  / /  /`--'  /  /`--'  |  | '.'|   | |--'  `---`-'| | ",
	L"  `--'---'   |  ,   / ---' |   :    |   :    | |  ,   /|   :    / ---'     `----' '--'.     '--'.     /;  :    |   |/      .'__/\\_: | ",
	L"              ---`-'        \\   \\  / \\   \\  /   ---`-'  \\   \\ .'                    `--'---'  `--'---' |  ,   /'---'       |   :    : ",
	L"                             `----'   `----'             `---`                                          ---`-'              \\   \\  /  ",
	L"                                                                                                                             `--`-'   ",
};

class Menu
{
public:
	Menu();
	void ShowTitle();
	void printMenu(wstring menu[], int n);
	int Choice();
	void Do();
	void mainMenu();
	void control();
	~Menu();

private:
	wstring menu[6] = { L"NEW GAME", L"CONTINUE", L"SETTING", L"HELP", L"ABOUT US", L"EXIT GAME" };
	wstring *title;
	int c;
};

void SubThread(GAME &game);