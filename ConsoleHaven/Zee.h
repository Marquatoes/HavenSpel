#include "RNG.h";
#include "schip.h";
#pragma once
class Zee {
private:
	int _turns;
	schip* _vaarSchip;
	schip* _piraten;
	schip* _schepen;
	void vechtMetPiraten(RNG* rng);
	void gevolgWind(int actie, RNG* rng);
public:
	Zee(int turns, schip* schepen);
	~Zee();
	Zee(const Zee& copyZee);
	Zee& operator=(const Zee& copyZee);
	Zee(Zee&& moveZee) noexcept;
	Zee& operator=(Zee&& moveZee) noexcept;
	void enterZee(schip* vaarSchip);
	bool vaar(RNG* rng);
};