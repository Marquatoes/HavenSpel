#pragma once
#include <stdlib.h>
#include <iostream>
#include <random>
#include <ctime>
class RNG {
private:
	 std::random_device generator;
	 static RNG* myInstance;
	 RNG();
	 RNG(const RNG& rng) = delete; // Copy constructor
	 RNG(const RNG&& rng) = delete;  // Move constructor
	 RNG& operator=(const RNG& rng) = delete; // Assignment operator
	 RNG& operator=(const RNG&& rng) = delete; // Move operator
public:
	static RNG* Instance();
	static void Release();
	int getRandomNumber(int min, int max);
};
