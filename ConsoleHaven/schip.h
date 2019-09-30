#include <cstddef>
#pragma once
class schip
{
private:
	char *_type;
	int _prijs;
	int _laadruimte;
	int _kanonnen;
	int _schadepunte;
	char *_bijzonderheden;
public:
	schip(char *type ,int prijs, int laadruimte, int kanonnen, int schadepunten, char *bijzonderheden) {};
	~schip() {};
	schip(const schip &copySchip) {};
	schip& operator=(const schip& moveSchip) {};
	schip(const schip &&moveSchip) {};
	schip& operator=(const schip &&moveSchip) {};
};

