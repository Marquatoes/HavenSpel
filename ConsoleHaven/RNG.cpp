#include "RNG.h"

RNG::RNG()
{
	
}

int RNG::getRandomNumber(int min, int max)
{
	std::uniform_int_distribution<int> distribution1(min, max);
	return distribution1(generator);
}