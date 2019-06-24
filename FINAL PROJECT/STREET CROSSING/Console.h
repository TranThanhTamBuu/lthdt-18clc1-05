#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void FixConsoleWindow();
void gotoXY(const unsigned int &x, const unsigned int &y);
unsigned int whereX();
unsigned int whereY();
void textColor(const unsigned int& color); // from 1 to 255