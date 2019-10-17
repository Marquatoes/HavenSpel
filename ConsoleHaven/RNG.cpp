#include "RNG.h"
#include <stddef.h> 

RNG* RNG::myInstance = NULL;

RNG::RNG()
{
	
}

RNG* RNG::Instance()
{
	if (!myInstance) {
		myInstance = new RNG();
	}
	return myInstance;
}

void RNG::Release()
{
	if (myInstance) {
		delete myInstance;
	}
}

int RNG::getRandomNumber(int min, int max)
{
	std::uniform_int_distribution<int> distribution1(min, max);
	return distribution1(generator);
}