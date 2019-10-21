#include <cstddef>
#include "Kanon.h";
#include <cstring>
#include "Handelsgoed.h"
#pragma once
class schip
{
private:
	char* _type;
	int _prijs;
	int _laadruimte;
	Handelsgoed* _handelsGoederen;
	int _maxKanonnen;
	int _aantalKanonnen;
	int _schadepunten;
	char* _bijzonderheden;
	Kanon* _kanonnen;
public:
	schip();
	schip(char* type, int prijs, int laadruimte, int maxKanonnen, int schadepunten, char* bijzonderheden, Kanon* kanonnen, int aantalKanonnen);
	~schip();
	schip(const schip& copySchip);
	schip& operator=(const schip& copySchip);
	schip(schip&& moveSchip) noexcept;
	schip& operator=(schip&& moveSchip) noexcept;
	void repareer(int aantalSchadePunten);
	const int getSchade();
	const int getDamage();
	void setSchade(int aantal);
	const bool hasBijzonderheid(const char* bijzonderheid);
	bool addKanon(Kanon kanon);
	void seedKanonnen(int aantal);
	void dumpHandelsgoederen();
};