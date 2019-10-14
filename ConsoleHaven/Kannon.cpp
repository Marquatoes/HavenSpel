#include "Kannon.h"

Kannon::Kannon() : _type{ 0 }, _prijs{ 0 } {}

Kannon::Kannon(int type, int prijs) : _type { type }, _prijs { prijs } {}

const int Kannon::getType()
{
	return _type;
}

const int Kannon::getPrijs()
{
	return _prijs;
}
