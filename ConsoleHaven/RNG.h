#pragma once
#include <stdlib.h>
#include <iostream>
#include <random>
#include <ctime>
class RNG {
private:
	 std::random_device generator;
public:
	 RNG();
	 int getRandomNumber(int min, int max);
};
