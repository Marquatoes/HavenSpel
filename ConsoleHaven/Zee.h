#include "RNG.h";
#include "schip.h";
#pragma once
class Zee {
private:
	schip* _vaarSchip;
	void vechtMetPiraten();
	int gevolgWind(int actie, RNG* rng);
public:
	void enterZee(schip* vaarSchip);
	int vaar(RNG* rng);
};