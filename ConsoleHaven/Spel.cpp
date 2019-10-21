#include "Spel.h"

void Spel::Start()
{
	_havens[0].enterHaven(_huidigSchip);
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
		_huidigeHaven->KoopGoederen();
	case 2:
		_huidigeHaven->VerkoopGoederen();
	case 3:
		_huidigeHaven->KoopKanonnen();
	case 4:
		_huidigeHaven->VerkoopKanonnen();
	case 5:
		_huidigeHaven->KoopSchip();
	case 6:
		_huidigeHaven->VerkoopSchip();
	case 7:
		_huidigeHaven->Wegvaren();
	case 8:
		_huidigeHaven->RepareerSchip();
	case 9:
		Stop();
	}
}

Spel::Spel()
{
	_alleSchepen = new schip[13];
	_havens = new Haven[24];
	FileReader f = FileReader();
	f.ReadSchepenFile(_alleSchepen);
	f.MaakHavens(_havens);
	const char* s = "klein,licht";
	const char* typo = "zeerkut";
	char* t = new char[44];
	char* type = new char[44];
	strcpy_s(t, 44, s);
	strcpy_s(type, 44, typo);
	Kanon* kanon = new Kanon[1];
	char grootte[] = "licht";
	kanon[0] = Kanon(grootte, 50);
	_huidigSchip = new schip(type, 100, 100, 100, 417, t, kanon, 1);
}

Spel::~Spel()
{
	if (_alleSchepen != nullptr) {
		delete[] _alleSchepen;
	}
	if (_havens != nullptr) {
		delete[] _havens;
	}
	if (_zee != nullptr) {
		delete _zee;
	}
	if (_huidigSchip != nullptr) {
		delete _huidigSchip;
	}
	RNG::Release();
}

void Spel::Stop()
{
}
