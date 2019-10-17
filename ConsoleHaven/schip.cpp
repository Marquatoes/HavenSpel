#include "schip.h"
#include <cstring>

schip::schip() : _prijs{ 0 }, _laadruimte{ 0 }, _maxKanonnen{ 0 }, _schadepunten{ 0 }
{
	_type = new char[100];
	_bijzonderheden = new char[100];
	_kannonen = nullptr;
}

schip::schip(char *type, int prijs, int laadruimte, int kanonnen, int schadepunten, char *bijzonderheden, Kannon* kannonen) :
	_type{ type }, _prijs{ prijs }, _laadruimte{ laadruimte }, _maxKanonnen{ kanonnen }, _schadepunten{ schadepunten }, _bijzonderheden{ bijzonderheden }, _kannonen{ kannonen } {};

schip::~schip()
{
	if (_type != nullptr) {
		delete[] _type;
	}
	if (_bijzonderheden != nullptr) {
		delete[] _bijzonderheden;
	}
	if (_kannonen != nullptr) {
		delete[] _kannonen;
	}
}

schip::schip(const schip& copySchip) : _type{ new char[100] }, _prijs{ copySchip._prijs }, _laadruimte{ copySchip._laadruimte }, _maxKanonnen{ copySchip._maxKanonnen }, _schadepunten{ copySchip._schadepunten }, _bijzonderheden{ new char[100] }, _kannonen{ new Kannon[_maxKanonnen] } {
	std::memcpy(_type, copySchip._type, 100);
	std::memcpy(_bijzonderheden, copySchip._bijzonderheden, 100);
	std:memcpy(_kannonen, copySchip._kannonen, _maxKanonnen);
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
	if (_kannonen != nullptr) {
		delete[] _kannonen;
	}

	_type = copySchip._type;
	_prijs = copySchip._prijs;
	_laadruimte = copySchip._laadruimte;
	_maxKanonnen = copySchip._maxKanonnen;
	_schadepunten = copySchip._schadepunten;
	_bijzonderheden = copySchip._bijzonderheden;
	_kannonen = copySchip._kannonen;
	return *this;
}

schip::schip(schip&& moveSchip) noexcept : _type{ moveSchip._type }, _prijs{ moveSchip._prijs }, _laadruimte{ moveSchip._laadruimte }, _maxKanonnen{ moveSchip._maxKanonnen }, _schadepunten{ moveSchip._schadepunten }, _bijzonderheden{ moveSchip._bijzonderheden }, _kannonen{ moveSchip._kannonen } {
	moveSchip._type = nullptr;
	moveSchip._bijzonderheden = nullptr;
	moveSchip._kannonen = nullptr;
	moveSchip._maxKanonnen = moveSchip._prijs = moveSchip._schadepunten = moveSchip._laadruimte = 0;
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
	if (_kannonen != nullptr) {
		delete[] _kannonen;
	}

	_type = moveSchip._type;
	_prijs = moveSchip._prijs;
	_laadruimte = moveSchip._laadruimte;
	_maxKanonnen = moveSchip._maxKanonnen;
	_schadepunten = moveSchip._schadepunten;
	_bijzonderheden = moveSchip._bijzonderheden;
	_kannonen = moveSchip._kannonen;

	moveSchip._type = nullptr;
	moveSchip._bijzonderheden = nullptr;
	moveSchip._kannonen = nullptr;
	moveSchip._maxKanonnen = moveSchip._prijs = moveSchip._schadepunten = moveSchip._laadruimte = 0;

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

const bool schip::hasBijzonderheid(const char* bijzonderheid)
{
	char* copy = new char[100];
	strcpy_s(copy, 100 , _bijzonderheden);
	if (bijzonderheid != nullptr) {
		char* next_token1{};
		copy = strtok_s(copy, ",", &next_token1);
		if (std::strcmp(copy, bijzonderheid) == 0) {
			delete[] copy;
			return true;
		}
		if (next_token1 != nullptr && std::strcmp(next_token1, bijzonderheid) == 0)
		{
			delete[] copy;
			return true;
		}
		delete[] copy;
	}
	return false;
}

bool schip::addKannon(Kannon kannon)
{
	return false;
}
