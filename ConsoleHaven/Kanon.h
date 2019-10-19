#include <cstring>
#include <cstddef>
#include "RNG.h"
#pragma once
class Kanon {
private:
	char* _type;
	int _prijs;
	int _maxDamage;
	int _minDamage;
public:
	Kanon();
	Kanon(char* type, int prijs);
	~Kanon();
	Kanon(const Kanon& copyKanon);
	Kanon& operator=(const Kanon& copyKanon);
	Kanon(Kanon&& moveKanon) noexcept;
	Kanon& operator=(Kanon&& moveKanon) noexcept;
	const char* getType();
	const int getPrijs();
	const int getDamage();
};
