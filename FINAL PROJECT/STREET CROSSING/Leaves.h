#pragma once
#include "River.h"

static wstring leaf[4] = {
	L" .-.-. ",
	L"(_\|/_)",
	L"( /|\ )",
	L" '-'-' ",
};

class Leaves : public River
{
public:
	Leaves();
	Leaves(int x, int y, int speed = 0);
	//void draw();
	//void clear();
	~Leaves();


private:
	wstring *pleaf;
};

//Leaves** createLeaves(int yLeaf[], int lineLeaf, int *numLeaf, int *spdLeaf);