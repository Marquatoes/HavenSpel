#include "Kannon.h"

Kannon::Kannon() : _type{ 0 }, _prijs{ 0 }, _minDamage{ 0 }, _maxDamage{ 0 } {}

Kannon::Kannon(char* const type, int prijs) : _type { type }, _prijs { prijs }
{
	_minDamage = 0;
	if (std::strcmp(_type, "licht") == 0) {
		_maxDamage = 2;
	}
	else if (std::strcmp(_type, "middelgroot") == 0) {
		_maxDamage = 4;
	}
	else {
		_maxDamage = 6;
	}
}

Kannon::~Kannon()
{
	if (_type != nullptr) {
		delete[] _type;
	}
	
}

Kannon::Kannon(const Kannon& copyKannon) : _type{copyKannon._type}, _prijs{copyKannon._prijs}, _minDamage{copyKannon._minDamage}, _maxDamage{copyKannon._maxDamage}
{
	std:memcpy(_type, copyKannon._type, 100);
}

Kannon& Kannon::operator=(const Kannon& copyKannon)
{
	if (&copyKannon == this) return *this;

	if (_type != nullptr) {
		delete _type;
	}

	_type = copyKannon._type;
	_prijs = copyKannon._prijs;
	_minDamage = copyKannon._minDamage;
	_maxDamage = copyKannon._maxDamage;
	return *this;
}

Kannon::Kannon(Kannon&& moveKannon) noexcept : _type{ moveKannon._type }, _prijs{ moveKannon._prijs }, _minDamage{ moveKannon._minDamage }, _maxDamage{ moveKannon._maxDamage }
{
	_type = nullptr;
	_minDamage = _maxDamage = _prijs = 0;
}

Kannon& Kannon::operator=(Kannon&& moveKannon) noexcept
{
	if (&moveKannon == this) {
		return *this;
	}
	if (_type != nullptr) {
		delete[] _type;
	}

	_type = moveKannon._type;

	moveKannon._type = nullptr;
	moveKannon._minDamage = moveKannon._maxDamage = moveKannon._prijs = 0;

	return *this;
}

const char* Kannon::getType()
{
	return _type;
}

const int Kannon::getPrijs()
{
	return _prijs;
}

const int Kannon::getDamage(RNG* rng)
{
	return rng->getRandomNumber(_minDamage, _maxDamage);
}
