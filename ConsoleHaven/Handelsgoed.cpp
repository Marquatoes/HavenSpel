#include "Handelsgoed.h"

Handelsgoed::Handelsgoed() :_prijs{ 0 }, _aantal{ 0 }, _maxPrijs{ 0 }, _minPrijs{ 0 }, _maxAantal{ 0 }, _minAantal{ 0 } {}

Handelsgoed::Handelsgoed(int prijs, int aantal, int maxPrijs, int minPrijs, int maxAantal, int minAantal) : 
	_prijs{ prijs }, _aantal{ aantal }, _maxPrijs{ maxPrijs }, _minPrijs{ minPrijs }, _maxAantal { maxAantal }, _minAantal { minAantal } {}

int Handelsgoed::getPrijs() const
{
	return _prijs;
}

int Handelsgoed::getAantal() const
{
	return _aantal;
}

int Handelsgoed::getMinAantal() const
{
	return _minAantal;
}

int Handelsgoed::getMaxAantal() const
{
	return _maxAantal;
}

int Handelsgoed::getMinPrijs() const
{
	return _minPrijs;
}

int Handelsgoed::getMaxPrijs() const
{
	return _maxPrijs;
}

void Handelsgoed::setAantal(int aantal)
{
	_aantal = aantal;
}

void Handelsgoed::setPrijs(int prijs)
{
	_prijs = prijs;
}

