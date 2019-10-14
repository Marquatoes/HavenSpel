#include "schip.h";
#pragma once
class Speler {
private:
	int _goudstukken;
	schip _schip;
public: 
	int getGoudstukken();
	void setGoudstukken(int aantal);
	void setSchip(schip& newSchip);
};