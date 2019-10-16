#include <cstddef>
#pragma once
class schip
{
private:
	char *_type;
	int _prijs;
	int _laadruimte;
	int _kanonnen;
	int _schadepunten;
	char *_bijzonderheden;
public:
	schip();
	schip(char *type ,int prijs, int laadruimte, int kanonnen, int schadepunten, char *bijzonderheden);
	~schip();
	schip(const schip &copySchip);
	schip& operator=(const schip& copySchip);
	schip(schip &&moveSchip) noexcept;
	schip& operator=(schip &&moveSchip) noexcept;
	void repareer(int aantalSchadePunten);
	const int getSchade();
	void setSchade(int aantal);
	const bool hasType(const char* type);
};

