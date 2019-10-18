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
	schip alleSchepen[13];
	Haven havens[24];
	Haven* ptr = &havens[0];
	const char* s = "log,licht";
	const char* typo = "zeerkut";
	char* t = new char[44];
	char* type = new char[44];
	strcpy_s(t, 44, s);
	strcpy_s(type, 44, typo);
	Kanon* kanon = new Kanon[1];
	kanon[0] = Kanon();
	schip* kutschip = new schip(type, 100, 100, 100, 417, t , kanon  , 0);
	FileReader f = FileReader();
	schip *schepen = alleSchepen;
	f.ReadSchepenFile(schepen);
	f.MaakHavens(ptr);
	//std::cout << kutschip->hasBijzonderheid("licht") << std::endl;
	int turns = 5;
	//Zee* zee = new Zee(turns, schepen);
	//schip *schip1 = schepen[5];
	//zee->enterZee(kutschip);
	//zee->vaar();
	RNG::Release();
	delete kutschip;
	//delete zee;
	_CrtDumpMemoryLeaks();
    //std::cout << "Hello World!\n";

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
