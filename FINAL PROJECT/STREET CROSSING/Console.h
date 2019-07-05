#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <cwchar>
#include <io.h>
#include <fcntl.h>

#define WIDTH 158
#define HEIGHT 42
#define X_max 158
#define Y_max 42

using namespace std;

/*
Color          Text      Background
-----------------------------------
Black            0           0
Blue             1           1
Green            2           2
Cyan             3           3
Red              4           4
Magenta          5           5
Brown            6           6
White            7           7
Gray             8           -
Intense Blue     9           -
Intense Green    10          -
Intense Cyan     11          -
Intense Red      12          -
Intense Magenta  13          -
Yellow           14          -
Intense White    15          -
*/

void FixConsoleWindow();
void FixSizeWindow(int width, int height);
void RemoveScrollBar();
void gotoXY(const unsigned int &x, const unsigned int &y);
unsigned int whereX();
unsigned int whereY();
void printSpace(int num);
void setColor(int textColor, int bgColor);
void clrscr();

