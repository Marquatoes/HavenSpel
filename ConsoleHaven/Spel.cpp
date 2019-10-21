#include "Spel.h"

void Spel::Start()
{
	//Haven *haven = new Haven(nullptr, nullptr, nullptr, 0, 0, 0);
	//haven->seedHaven();
	//delete haven;
	
	alleSchepen = new schip[13];
	
	havens = new Haven[24];
	const char* s = "klein,licht";
	const char* typo = "zeerkut";
	char* t = new char[44];
	char* type = new char[44];
	strcpy_s(t, 44, s);
	strcpy_s(type, 44, typo);
	Kanon* kanon = new Kanon[1];
	char grootte[] = "licht";
	kanon[0] = Kanon(grootte, 50);
	huidigSchip = new schip(type, 100, 100, 100, 417, t, kanon, 1);
	FileReader f = FileReader();
	schip* schepen = alleSchepen;
	f.ReadSchepenFile(alleSchepen);
	f.MaakHavens(havens);
	havens[0].enterHaven(huidigSchip);
	int turns = 5;
	//Zee* zee = new Zee(turns, schepen);
	//zee->enterZee(kutschip);
	//zee->vaar();

	RNG::Release();

	delete[] havens;
	//delete zee;
	delete[] alleSchepen;
}

void Spel::speelBeurt()
{
	std::cout << "Je bent in een haven, dit zijn je opties" << std::endl;
	std::cout << "1: Koop goederen" << std::endl;
	std::cout << "2: Verkoop goederen" << std::endl;
	std::cout << "3: Koop kanonnen" << std::endl;
	std::cout << "4: Verkoop kanonnen" << std::endl;
	std::cout << "5: Koop schip" << std::endl;
	std::cout << "6: Verkoop schip" << std::endl;
	std::cout << "7: Wegvaren" << std::endl;
	std::cout << "8: Repareer Schip" << std::endl;
	std::cout << "9: Afsluiten" << std::endl;
	int result;
	std::cin >> result;

	switch (result) {
	case 1:
		koopGoederen();
	case 2:
		verkoopGoederen();
	case 3:
		koopKanonnen();
	case 4:
		verkoopKanonnen();
	case 5:
		koopSchip();
	case 6:
		verkoopSchip();
	case 7:
		wegvaren();
	case 8:
		repareerSchip();
	case 9:
		afsluiten();
	}
}

void Spel::Stop()
{
}
