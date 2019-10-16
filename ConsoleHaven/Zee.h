#include "RNG.h";
#include "schip.h";
#pragma once
class Zee {
private:
	schip* _vaarSchip;
	schip* _piraten;
	void vechtMetPiraten();
	int gevolgWind(int actie, RNG* rng);
public:
	void enterZee(schip* vaarSchip);
	int vaar(RNG* rng);
};