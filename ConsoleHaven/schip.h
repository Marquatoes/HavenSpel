#include <cstddef>
#include "Kannon.h";
#include <cstring>
#pragma once
class schip
{
private:
	char* _type;
	int _prijs;
	int _laadruimte;
	int _maxKanonnen;
	int _aantalKannonnen;
	int _schadepunten;
	char* _bijzonderheden;
	Kannon* _kannonen;
public:
	schip();
	schip(char* type, int prijs, int laadruimte, int maxKanonnen, int schadepunten, char* bijzonderheden, Kannon* kannonen, int aantalKannonnen);
	~schip();
	schip(const schip& copySchip);
	schip& operator=(const schip& copySchip);
	schip(schip&& moveSchip) noexcept;
	schip& operator=(schip&& moveSchip) noexcept;
	void repareer(int aantalSchadePunten);
	const int getSchade();
	const int getDamage(RNG* rng);
	void setSchade(int aantal);
	const bool hasBijzonderheid(const char* bijzonderheid);
	bool addKannon(Kannon kannon);
};