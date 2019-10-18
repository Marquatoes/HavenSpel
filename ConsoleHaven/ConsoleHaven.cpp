// ConsoleHaven.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include "RNG.h";
#include "Kanon.h";
#include "Haven.h";
#include "FileReader.h"
#include "Zee.h"


int main()
{
	//Haven *haven = new Haven(nullptr, nullptr, nullptr, 0, 0, 0);
	//haven->seedHaven();
	//delete haven;
	schip* alleSchepen;
	alleSchepen = new schip[13];
	Haven* havens;
	havens = new Haven[24];

	FileReader f = FileReader();
	//schip *schepen = alleSchepen;
	f.ReadSchepenFile(alleSchepen);
	f.MaakHavens(havens);
	int turns = 5;
	//Zee* zee = new Zee(turns, schepen);
	//zee->enterZee(kutschip);
	//zee->vaar();
	RNG::Release();
	delete[] alleSchepen;
	delete[] havens;
	_CrtDumpMemoryLeaks();

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
