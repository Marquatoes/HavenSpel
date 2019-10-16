#include "schip.h"
#include <cstring>

schip::schip() : _prijs{ 0 }, _laadruimte{ 0 }, _kanonnen{ 0 }, _schadepunten{ 0 }
{
	_type = new char[100];
	_bijzonderheden = new char[100];
}

schip::schip(char *type, int prijs, int laadruimte, int kanonnen, int schadepunten, char *bijzonderheden) :
	_type{ type } , _prijs{ prijs }, _laadruimte{ laadruimte }, _kanonnen{ kanonnen }, _schadepunten{ schadepunten }, _bijzonderheden{ bijzonderheden } {};

schip::~schip()
{
	if (_type != nullptr) {
		delete[] _type;
	}
	if (_bijzonderheden != nullptr) {
		delete[] _bijzonderheden;
	}
}

schip::schip(const schip& copySchip) : _type{ new char[100] }, _prijs{ copySchip._prijs }, _laadruimte{ copySchip._laadruimte }, _kanonnen{ copySchip._kanonnen }, _schadepunten{ copySchip._schadepunten }, _bijzonderheden{ new char[100] } {
	std::memcpy(_type, copySchip._type, 100);
	std::memcpy(_bijzonderheden, copySchip._bijzonderheden, 100);
}

schip& schip::operator=(const schip& copySchip)
{
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
	_schadepunten = copySchip._schadepunten;
	_bijzonderheden = copySchip._bijzonderheden;
	return *this;
}

schip::schip(schip&& moveSchip) noexcept : _type{ moveSchip._type }, _prijs{ moveSchip._prijs }, _laadruimte{ moveSchip._laadruimte }, _kanonnen{ moveSchip._kanonnen }, _schadepunten{ moveSchip._schadepunten }, _bijzonderheden{ moveSchip._bijzonderheden } {
	moveSchip._type = nullptr;
	moveSchip._bijzonderheden = nullptr;
	moveSchip._kanonnen = moveSchip._prijs = moveSchip._schadepunten = moveSchip._laadruimte = 0;
}

schip& schip::operator=(schip&& moveSchip) noexcept
{
	if (&moveSchip == this) {
		return *this;
	}
	if (_type != nullptr) {
		delete[] _type;
	}
	if (_bijzonderheden != nullptr) {
		delete[] _bijzonderheden;
	}

	_type = moveSchip._type;
	_prijs = moveSchip._prijs;
	_laadruimte = moveSchip._laadruimte;
	_kanonnen = moveSchip._kanonnen;
	_schadepunten = moveSchip._schadepunten;
	_bijzonderheden = moveSchip._bijzonderheden;

	moveSchip._type = nullptr;
	moveSchip._bijzonderheden = nullptr;
	moveSchip._kanonnen = moveSchip._prijs = moveSchip._schadepunten = moveSchip._laadruimte = 0;

	return *this;
}

void schip::repareer(int aantalSchadePunten)
{
	if (_schadepunten > aantalSchadePunten) {
		_schadepunten -= aantalSchadePunten;
	}
	else {
		_schadepunten = 0;
	}
}

const int schip::getSchade()
{
	return _schadepunten;
}

void schip::setSchade(int aantal)
{
	_schadepunten = aantal;
}

const bool schip::hasType(const char* type)
{
	return false;
}
