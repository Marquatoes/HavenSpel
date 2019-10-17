#include <cstring>
#include <cstddef>
#include "RNG.h"
#pragma once
class Kannon {
private:
	char* _type;
	int _prijs;
	int _maxDamage;
	int _minDamage;
public:
	Kannon();
	Kannon(char* const type, int prijs);
	~Kannon();
	Kannon(const Kannon& copyKannon);
	Kannon& operator=(const Kannon& copyKannon);
	Kannon(Kannon&& moveKannon) noexcept;
	Kannon& operator=(Kannon&& moveKannon) noexcept;
	const char* getType();
	const int getPrijs();
	const int getDamage(RNG* rng);
};
