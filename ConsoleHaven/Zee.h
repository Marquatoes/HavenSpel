#include "RNG.h";
#include "schip.h";
#pragma once
class Zee {
private:
	int _turns;
	schip* _vaarSchip;
	schip* _piraten;
	schip* _schepen;
	void vechtMetPiraten();
	void vecht();
	void vlucht();
	void geefOver();
	void gevolgWind(int actie);
	int getVluchtKans() const;
public:
	Zee(int turns, schip* schepen);
	~Zee();
	Zee(const Zee& copyZee) = delete;
	Zee& operator=(const Zee& copyZee) = delete;
	Zee(Zee&& moveZee) = delete;
	Zee& operator=(Zee&& moveZee) = delete;
	void enterZee(schip* vaarSchip, int afstand);
	bool vaar();
};