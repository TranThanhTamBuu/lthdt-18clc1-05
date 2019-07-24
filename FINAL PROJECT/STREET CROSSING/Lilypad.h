#pragma once
#include "River.h"

static time_t now;

static wstring lilypad[3] = {
	L" .'”””',",
	L"(     <'",
	L" `.___.’",
};

class Lilypad : public River
{
public:
	Lilypad();
	Lilypad(int x, int y);
	~Lilypad();
	void draw();
	void clear();
	bool isImpact(People &people);
	void startTime();
	void setTime();
	void setOn();
	bool getState();
	int timeLeft();

private:
	wstring *ppad;
	bool people;
	time_t start;
};

bool isUsed(int x, vector <int> usedX);