#include "schip.h"
#include <cstring>

schip::schip(char type, int prijs, int laadruimte, int kanonnen, int schadepunten, char bijzonderheden) :
	_type{ &type } , _prijs{ prijs }, _laadruimte{ laadruimte }, _kanonnen{ kanonnen }, _schadepunte{ schadepunten }, _bijzonderheden{ &bijzonderheden } {};

schip::~schip()
{
	if (_type != nullptr) {
		delete[] _type;
	}
	if (_bijzonderheden != nullptr) {
		delete[] _bijzonderheden;
	}
}

schip::schip(const schip& copySchip) : 
	_type{ new char[100] }, _prijs{ copySchip._prijs }, _laadruimte{ copySchip._laadruimte }, _kanonnen{ copySchip._kanonnen }, _schadepunte{ copySchip._schadepunte }, _bijzonderheden{ new char[100] } {
	std:memcpy(_type, copySchip._type, 100);
	std:memcpy(_bijzonderheden, copySchip._bijzonderheden, 100);
}

schip::schip &operator=(const schip& copySchip) {
	if (&copySchip == this) return *this;

	if (_type != nullptr) {
		delete[] _type;
	}
	if (_bijzonderheden != nullptr) {
		delete[] _bijzonderheden;
	}

	_type = copySchip._type;
	_prijs = copySchip._prijs;
	_laadruimte = copySchip._laadruimte;
	_kanonnen = copySchip._kanonnen;
	_schadepunte = copySchip._schadepunte;
	_bijzonderheden = copySchip._bijzonderheden;
	return *this;
}
