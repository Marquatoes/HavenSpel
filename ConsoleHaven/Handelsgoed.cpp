#include "Handelsgoed.h"
#include <iostream>

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

const char* Handelsgoed::getType() const {
	return _type;
}

int Handelsgoed::Koop(const int huidigAantal, const int goudstukken)
{
	std::cout << "---------------------------------------------------------------"<< std::endl;
	std::cout << "Koop " << _type << std::endl;
	std::cout << "inventaris: " << huidigAantal << std::endl;
	std::cout << "huiding goudstukken: " << goudstukken << std::endl;
	std::cout << "Kosten per stuk: " << _prijs << std::endl;
	std::cout << "aantal beschikbaar: " << _aantal << std::endl;

	std::cout << "Hoeveel wil je er kopen?" << std::endl;
	int result;
	std::cin >> result;
	if (result <= _aantal && _aantal >= 0 && result * _prijs <= goudstukken) {
		_aantal -= result;
		return result;
	}
	else {
		if (result > _aantal) {
			std::cout << "Zoveel goederen zijn er niet beschikbaar" << std::endl;
		}
		if (result * _prijs > goudstukken) {
			std::cout << "Zoveel goederen kun je niet betalen" << std::endl;
		}
	}

	Koop(huidigAantal, goudstukken);
}

