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

static wstring level1[9] = {
	L"              ('-.         (`-.      ('-.                             ",
	L"            _(  OO)      _(OO  )_  _(  OO)                            ",
	L" ,--.      (,------. ,--(_/   ,. \\(,------.  ,--.             .---.  ",
	L" |  |.-')   |  .---' \\   \\   /(__/ |  .---'  |  |.-')        /_   | ",
	L" |  | OO )  |  |      \\   \\ /   /  |  |      |  | OO )        |   | ",
	L" |  |`-' | (|  '--.    \\   '   /, (|  '--.   |  |`-' |        |   |  ",
	L"(|  '---.'  |  .--'     \\     /__) |  .--'  (|  '---.'        |   |  ",
	L" |      |   |  `---.     \\   /     |  `---.  |      |         |   |  ",
	L" `------'   `------'      `-'      `------'  `------'         `---'   ",
};

static wstring level2[8] = {
	L"           (`-')  _       (`-') (`-')  _                           ",
	L"   <-.     ( OO).-/      _(OO ) ( OO).-/    <-.                    ",
	L" ,--. )   (,------. ,--.(_/,-.\\(,------.  ,--. )        .----.    ",
	L" |  (`-')  |  .---' \\   \\ / (_/ |  .---'  |  (`-')     \\_,-.  | ",
	L" |  |OO ) (|  '--.   \\   /   / (|  '--.   |  |OO )        .' .'   ",
	L"(|  '__ |  |  .--'  _ \\     /_) |  .--'  (|  '__ |      .'  /_    ",
	L" |     |'  |  `---. \\-'\\   /    |  `---.  |     |'     |      |  ",
	L" `-----'   `------'     `-'     `------'  `-----'      `------'    ",
};

static wstring level3[7] = {
	L"     _        ___    __   __    ___      _                  ____                                       ",
	L"    | |      | __|   \\ \\ / /   | __|    | |        o O O   |__ /                                     ",
	L"    | |__    | _|     \\ V /    | _|     | |__     o         |_ \\                                     ",
	L"    |____|   |___|    _\\_/_    |___|    |____|   TS__[O]   |___/                                      ",
	L"  _|\"\"\"\"\" | _ | \"\"\"\"\"| _| \"\"\"\"| _|\"\"\"\"\" | _ | \"\"\"\"\"|  {======| _|\"\"\"\"\" |  ",
	L"  \"`-0 - 0 - ' \"`-0-0-' \"`-0-0-' \"`-0 - 0 - ' \"`-0-0-' . / o--000' \"`-0-0-'                      ",
	L"                                                                                                       ",
};

static wstring level4[7] = {
	L" __           ______       __   __      ______       __             __   __       ",
	L"/_/\\         /_____/\\     /_/\\ /_/\\    /_____/\\     /_/\\           /__/\\/__/\\     ",
	L"\\:\\ \\        \\::::_\\/_    \\:\\ \\\\ \\ \\   \\::::_\\/_    \\:\\ \\          \\  \\ \\: \\ \\__  ",
	L" \\:\\ \\        \\:\\/___/\\    \\:\\ \\\\ \\ \\   \\:\\/___/\\    \\:\\ \\          \\::\\_\\::\\/_/\\ ",
	L"  \\:\\ \\____    \\::___\\/_    \\:\\_/.:\\ \\   \\::___\\/_    \\:\\ \\____      \\_:::   __\\/ ",
	L"   \\:\\/___/\\    \\:\\____/\\    \\ ..::/ /    \\:\\____/\\    \\:\\/___/\\          \\::\\ \\  ",
	L"    \\_____\\/     \\_____\\/     \\___/_/      \\_____\\/     \\_____\\/           \\__\\/  ",
};

static wstring level4_1[7] = {
	L" ___           _______       ___      ___  _______       ___               ___   ___     ",
	L"|\\  \\         |\\  ___ \\     |\\  \\    /  /||\\  ___ \\     |\\  \\             |\\  \\ |\\  \\    ",
	L"\\ \\  \\        \\ \\   __/|    \\ \\  \\  /  / /\\ \\   __/|    \\ \\  \\            \\ \\  \\\\_\\  \\   ",
	L" \\ \\  \\        \\ \\  \\_|/__   \\ \\  \\/  / /  \\ \\  \\_|/__   \\ \\  \\            \\ \\______  \\  ",
	L"  \\ \\  \\____    \\ \\  \\_|\\ \\   \\ \\    / /    \\ \\  \\_|\\ \\   \\ \\  \\____        \\|_____|\\  \\ ",
	L"   \\ \\_______\\   \\ \\_______\\   \\ \\__/ /      \\ \\_______\\   \\ \\_______\\             \\ \\__\\",
	L"    \\|_______|    \\|_______|    \\|__|/        \\|_______|    \\|_______|              \\|__|",
};


static wstring level5[9] = {
	L"   .---.          .-''-.   ,---.  ,---.     .-''-.     .---.              ,--------.       ",
	L"   | ,_|        .'_ _   \\  |   /  |   |   .'_ _   \\    | ,_|              |   _____|     ",
	L" ,-./  )       / ( ` )   ' |  |   |  .'  / ( ` )   ' ,-./  )              |  )             ",
	L" \\  '_ '`)    . (_ o _)  | |  | _ |  |  . (_ o _)  | \\  '_ '`)            |  '----.      ",
	L"  > (_)  )    |  (_,_)___| |  _( )_  |  |  (_,_)___|  > (_)  )            |_.._ _  '.      ",
	L" (  .  .-'    '  \\   .---. \\ (_ o._) /  '  \\   .---. (  .  .-'               ( ' )   \\ ",
	L"  `-'`-'|___   \\  `-'    /  \\ (_,_) /    \\  `-'    /  `-'`-'|___           _(_{;}_)  |  ",
	L"   |        \\   \\       /    \\     /      \\       /    |        \\         |  (_,_)  /  ",
	L"   `--------`    `'-..-'      `---`        `'-..-'     `--------`          `...__..'       ",
};

class Menu
{
public:
	Menu();
	void ShowTitle();
	void printMenu(wstring menu[], int n);
	int Choice();
	int Do(GAME &game);
	void control();
	~Menu();

private:
	wstring menu[6] = { L"NEW GAME", L"CONTINUE", L"SETTING", L"HELP", L"ABOUT US", L"EXIT GAME" };
	wstring *title;
	int c;
};

void saveScr(GAME &game);
void lose();
void level_1();
void level_2();
void level_3();
void level_4();
void level_5();
bool SubThread(GAME &game);