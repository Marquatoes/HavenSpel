#include "Speler.h"
#include "schip.h"
#include <utility>

Speler::Speler(int goudStukken) : _goudstukken { goudStukken }
{

}

int Speler::getGoudstukken() const
{
	return _goudstukken;
}

void Speler::setGoudstukken(int aantal)
{
	_goudstukken = aantal;
}