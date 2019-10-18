#include "Kanon.h"

Kanon::Kanon() :  _prijs{ 0 }, _minDamage{ 0 }, _maxDamage{ 0 } { _type = new char[15]; }

Kanon::Kanon(char* const type, int prijs) : _type { type }, _prijs { prijs }
{
	_minDamage = 0;
	if (std::strcmp(type, "licht") == 0) {
		_maxDamage = 2;
	}
	else if (std::strcmp(type, "middelgroot") == 0) {
		_maxDamage = 4;
	}
	else {
		_maxDamage = 6;
	}
}

Kanon::~Kanon()
{
	if (_type != nullptr) {
		delete[] _type;
	}
}

Kanon::Kanon(const Kanon& copyKanon) : _type{copyKanon._type}, _prijs{copyKanon._prijs}, _minDamage{copyKanon._minDamage}, _maxDamage{copyKanon._maxDamage}
{
	std:memcpy(_type, copyKanon._type, 100);
}

Kanon& Kanon::operator=(const Kanon& copyKanon)
{
	if (&copyKanon == this) return *this;

	if (_type != nullptr) {
		delete _type;
	}

	_type = copyKanon._type;
	_prijs = copyKanon._prijs;
	_minDamage = copyKanon._minDamage;
	_maxDamage = copyKanon._maxDamage;
	return *this;
}

Kanon::Kanon(Kanon&& moveKanon) noexcept : _type{ moveKanon._type }, _prijs{ moveKanon._prijs }, _minDamage{ moveKanon._minDamage }, _maxDamage{ moveKanon._maxDamage }
{
	_type = nullptr;
	_minDamage = _maxDamage = _prijs = 0;
}

Kanon& Kanon::operator=(Kanon&& moveKanon) noexcept
{
	if (&moveKanon == this) {
		return *this;
	}
	if (_type != nullptr) {
		delete[] _type;
	}

	_type = moveKanon._type;

	moveKanon._type = nullptr;
	moveKanon._minDamage = moveKanon._maxDamage = moveKanon._prijs = 0;

	return *this;
}

const char* Kanon::getType()
{
	return _type;
}

const int Kanon::getPrijs()
{
	return _prijs;
}

const int Kanon::getDamage(RNG* rng)
{
	return rng->getRandomNumber(_minDamage, _maxDamage);
}
