#include <cstddef>
#include "Kanon.h"
#include <cstring>
#include "Handelsgoed.h"
#include "Speler.h"
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
	void addKanon(Kanon kanon);
	bool checkMaxKanonnen();
	void verkoopKanon(Speler* speler);
	void seedKanonnen(int aantal);
	void dumpHandelsgoederen();
	Handelsgoed* getHandelsGoederen();
	const int getAantalHandelsGoederen();
	const int getCapaciteit();
};