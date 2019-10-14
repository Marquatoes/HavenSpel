#include "Speler.h"
#include "schip.h"
#include <utility>

int Speler::getGoudstukken()
{
	return _goudstukken;
}

void Speler::setGoudstukken(int aantal)
{
	_goudstukken = aantal;
}

void Speler::setSchip(schip &newSchip)
{
	_schip = std::move(newSchip);
}
