// ConsoleHaven.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#include "spel.h"

int main()
{
	Spel* spel = new Spel();
	spel->Start();
	delete spel;
	_CrtDumpMemoryLeaks();

}


