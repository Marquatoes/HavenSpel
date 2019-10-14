#include "RNG.h"

RNG::RNG()
{
	srand(time(NULL));
}

int RNG::getRandomNumber(int min, int max)
{
	return rand() % max + min;
}
