#include "Zee.h"

void Zee::enterZee(schip* vaarSchip)
{
	_vaarSchip = std::move(vaarSchip);
}

int Zee::vaar(RNG* rng)
{
	if (rng->getRandomNumber(1,10) < 3) {
		vechtMetPiraten();		
	}
	else {
		int random = rng->getRandomNumber(1,20);
		return gevolgWind(random, rng);
	}
}

void Zee::vechtMetPiraten() {
}
//DP toepassen wanneer we klaar zijn !
int Zee::gevolgWind(int actie, RNG* rng) {
	if (actie <= 2) {
		return 0;
	}
	else if (actie >= 3 && actie <= 4) {
		if (_vaarSchip->hasType("licht")) {
			return 1;
		}
		return 0;
	}
	else if (actie >= 5 && actie <= 7) {
		if (_vaarSchip->hasType("log")) {
			return 0;
		}
		return 1;
	}
	else if (actie >= 8 && actie <= 17) {
		return 1;
	}
	else if (actie >= 18 && actie <= 19) {
		return 2;
	}
	else {
		int stormGevolg = rng->getRandomNumber(1, 10);
		if (stormGevolg >= 1 && stormGevolg <= 4) {
			return -1;
		}
		else if (stormGevolg >= 5 && stormGevolg <= 8) {
			return 0;
		}
		else if (stormGevolg >= 9 && stormGevolg <= 10) {
			return 1;
		}
		_vaarSchip->setSchade(_vaarSchip->getSchade() * rng->getRandomNumber(1, 100));
	}
}