#include "Handelsgoed.h"

Handelsgoed::Handelsgoed()
{
}

Handelsgoed::Handelsgoed(int prijs, int aantal, int maxPrijs, int minPrijs, int maxAantal, int minAantal) :
	_prijs{ prijs }, _aantal{ aantal }, _maxPrijs{ maxPrijs }, _minPrijs{ minPrijs }, _maxAantal { maxAantal }, _minAantal { minAantal } {}

const int Handelsgoed::getPrijs()
{
	return _prijs;
}

const int Handelsgoed::getAantal()
{
	return _aantal;
}

const int Handelsgoed::getMinAantal()
{
	return _minAantal;
}

const int Handelsgoed::getMaxAantal()
{
	return _maxAantal;
}

const int Handelsgoed::getMinPrijs()
{
	return _minPrijs;
}

const int Handelsgoed::getMaxPrijs()
{
	return _maxPrijs;
}

