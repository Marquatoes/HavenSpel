// ConsoleHaven.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include "RNG.h";
#include "Kannon.h";
#include "Haven.h";
#include "FileReader.h"
#include "Zee.h"

schip* schepen[13];
Haven* havens[25];
int main()
{
	RNG *rng = new RNG();
	Haven *haven = new Haven(nullptr, nullptr, nullptr, 0, 0, 0);
	haven->seedHaven(rng);
	delete haven;
	
	const char* s = "log,licht";
	char* t = new char[44];
	strcpy_s(t, 44, s);
	schip* kutschip = new schip(nullptr, 100, 100, 100, 417, t , new Kannon(1, 50));

	//std::cout << kutschip->hasBijzonderheid("licht") << std::endl;
	int turns = 5;
	Zee* zee = new Zee(turns, schepen);
	zee->enterZee(kutschip);
	zee->vaar(rng);
	delete rng;
	delete zee;
	_CrtDumpMemoryLeaks();

    //std::cout << "Hello World!\n";
	//FileReader f = FileReader();
	//f.ReadSchepenFile(schepen);
	//f.MaakHavens(havens, schepen);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
