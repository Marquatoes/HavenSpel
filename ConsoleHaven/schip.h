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
	int _maxSchadepunten;
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
	bool repareer(int aantalSchadePunten);
	const int getMaxSchadePuntenOmTeRepareren() const;
	const int getSchade() const;
	const int getDamage() const;
	void setSchade(int aantal);
	const bool hasBijzonderheid(const char* bijzonderheid) const;
	void addKanon(Kanon kanon);
	bool checkMaxKanonnen() const;
	void verkoopKanon(Speler* speler);
	void seedKanonnen(int aantal);
	Handelsgoed* getHandelsGoederen() const;
	const int getAantalHandelsGoederen() const;
	const int getCapaciteit() const;
	int getPrijs() const;
	int getMaxAantalHandelsGoederen() const;
	int getMaxAantalKanonnen() const;
	const char* getType() const;
	const char* getBijzonderheden() const;
	void printInfo() const;

};