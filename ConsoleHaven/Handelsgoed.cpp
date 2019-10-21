#include "Handelsgoed.h"

Handelsgoed::Handelsgoed() :_prijs{ 0 }, _aantal{ 0 }, _maxPrijs{ 0 }, _minPrijs{ 0 }, _maxAantal{ 0 }, _minAantal{ 0 } {
	_type = new char[100];
}

Handelsgoed::Handelsgoed(int prijs, int aantal, int maxPrijs, int minPrijs, int maxAantal, int minAantal, char* type) : 
	_prijs{ prijs }, _aantal{ aantal }, _maxPrijs{ maxPrijs }, _minPrijs{ minPrijs }, _maxAantal { maxAantal }, _minAantal { minAantal } 
{
	_type = new char[100];
	std::memcpy(_type, type, 100);
	
}

Handelsgoed::~Handelsgoed()
{
	if (_type != nullptr) {
		delete[] _type;
	}
}

Handelsgoed::Handelsgoed(const Handelsgoed& copyHandelsgoed) : 
	_prijs{ copyHandelsgoed._prijs }, _aantal{ copyHandelsgoed._aantal }, _minPrijs{ copyHandelsgoed._minPrijs }, _maxPrijs{ copyHandelsgoed._maxPrijs },
	_minAantal{ copyHandelsgoed._minAantal }, _maxAantal{ copyHandelsgoed._maxAantal }
{
	_type = new char[100];
	std::memcpy(_type, copyHandelsgoed._type, 100);
}

Handelsgoed& Handelsgoed::operator=(const Handelsgoed& copyHandelsgoed)
{
	if (&copyHandelsgoed == this) return *this;

	if (_type != nullptr) {
		delete _type;
	}
	_type = new char[100];
	std::memcpy(_type, copyHandelsgoed._type, 100);
	_prijs = copyHandelsgoed._prijs;
	_aantal = copyHandelsgoed._aantal;
	_minPrijs = copyHandelsgoed._minPrijs;
	_maxPrijs = copyHandelsgoed._maxPrijs;
	_minAantal = copyHandelsgoed._minAantal;
	_maxAantal = copyHandelsgoed._maxAantal;
	return *this;
}

Handelsgoed::Handelsgoed(Handelsgoed&& moveHandelsgoed) noexcept : 
	_type{ moveHandelsgoed._type }, _prijs { moveHandelsgoed._prijs }, _aantal{ moveHandelsgoed._aantal }, _minPrijs{ moveHandelsgoed._minPrijs }, _maxPrijs{ moveHandelsgoed._maxPrijs },
	_minAantal{ moveHandelsgoed._minAantal }, _maxAantal{ moveHandelsgoed._maxAantal }
{
	moveHandelsgoed._type = nullptr;
	moveHandelsgoed._aantal = moveHandelsgoed._minAantal = moveHandelsgoed._maxAantal = moveHandelsgoed._prijs = moveHandelsgoed._minPrijs = moveHandelsgoed._maxPrijs = 0;
}

Handelsgoed& Handelsgoed::operator=(Handelsgoed&& moveHandelsgoed) noexcept
{
	if (&moveHandelsgoed == this) {
		return *this;
	}
	if (_type != nullptr) {
		delete[] _type;
	}

	_type = moveHandelsgoed._type;
	_prijs = moveHandelsgoed._prijs;
	_aantal = moveHandelsgoed._aantal;
	_minPrijs = moveHandelsgoed._minPrijs;
	_maxPrijs = moveHandelsgoed._maxPrijs;
	_minAantal = moveHandelsgoed._minAantal;
	_maxAantal = moveHandelsgoed._maxAantal;

	moveHandelsgoed._type = nullptr;
	moveHandelsgoed._aantal = moveHandelsgoed._minAantal = moveHandelsgoed._maxAantal = moveHandelsgoed._prijs = moveHandelsgoed._minPrijs = moveHandelsgoed._maxPrijs = 0;

	return *this;
}

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

