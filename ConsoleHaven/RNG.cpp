#include "RNG.h"
#include <stddef.h> 

RNG* RNG::myInstance = nullptr;

RNG::RNG()
{
	
}

RNG* RNG::Instance()
{
	if (myInstance == nullptr) {
		try {
			myInstance = new RNG();
		}
		catch(...) {
			throw;
		}
		
	}
	return myInstance;
}

void RNG::Release()
{
	if (myInstance) {
		delete myInstance;
	}
}

int RNG::getRandomNumber(int min, int max) {
	std::uniform_int_distribution<int> distribution1(min, max);
	return distribution1(generator);
}