#include "Spel.h"

void Spel::Start()
{
	speelBeurt();
}

void Spel::speelBeurt()
{
	if (_speler->getGoudstukken() >= 1000000) {
		std::cout << "Je bent Koning van dit spel waaraan wij zo lang hebben zitten werken," << std::endl;
		std::cout << "fijn dat er tenminste een iemand het spel gespeeld heeft" << std::endl;
		return;
	}
	std::cout << "Je bent in " << _huidigeHaven->getNaam() << ", dit zijn je opties" << std::endl;
	std::cout << "1: Koop goederen" << std::endl;
	std::cout << "2: Verkoop goederen" << std::endl;
	std::cout << "3: Koop kanonnen" << std::endl;
	std::cout << "4: Verkoop kanonnen" << std::endl;
	std::cout << "5: Koop schip" << std::endl;
	std::cout << "6: Wegvaren" << std::endl;
	std::cout << "7: Repareer Schip" << std::endl;
	std::cout << "8: Afsluiten" << std::endl;
	int result;
	std::cin >> result;

	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin >> result;
	}

	switch (result) {
	case 1:
		_huidigeHaven->KoopGoederen(_huidigSchip, _speler);
		break;
	case 2:
		_huidigeHaven->VerkoopGoederen(_huidigSchip, _speler);
		break;
	case 3:
		_huidigeHaven->KoopKanonnen(_huidigSchip, _speler);
		break;
	case 4:
		_huidigeHaven->VerkoopKanon(_huidigSchip, _speler);
		break;
	case 5:
		_huidigeHaven->KoopSchip(_speler, _huidigSchip);
		break;
	case 6:
		kiesHaven();
		return;
	case 7:
		_huidigeHaven->RepareerSchip(_speler, _huidigSchip);
		break;
	case 8:
		return;
		
	}
	speelBeurt();
}

Spel::Spel()
{
	try {
		_alleSchepen = new schip[13];
		_havens = new Haven[240000];
		_speler = new Speler(20000);
		FileReader f = FileReader();
		f.ReadSchepenFile(_alleSchepen);
		f.MaakHavens(_havens);
		_huidigSchip = new schip();
	    *_huidigSchip = _alleSchepen[0];
		_zee = new Zee(0, _alleSchepen);
		_havens[0].enterHaven(_huidigSchip);
		_huidigeHaven = &_havens[0];
		_huidigeHaven->seedSchepen(_alleSchepen, 13);
	}
	catch (...) {
		std::cout << "Er is een fout opgetreden bij het aanmaken van het spel" << std::endl;
		delete[] _alleSchepen;
		delete[] _havens;
		delete _zee;
		delete _huidigSchip;
		delete _speler;
		delete _huidigeHaven;
		RNG::Release();
		throw;
	}

	
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
	if (_speler != nullptr) {
		delete _speler;
	}
	if (_huidigeHaven != nullptr) {
		delete _huidigeHaven;
	}
	RNG::Release();
}

void Spel::Stop() const
{
	std::cout << "L0Z3R" << std::endl;
}

void Spel::kiesHaven() {
	std::cout << "Je bent nu in " << _huidigeHaven->getNaam() << std::endl;
	std::cout << "Je kunt naar de volgende Havens: " << std::endl;
	for (int i = 0; i < 24; i++)
	{
		std::cout << i << ": " << _havens[i].getNaam() << " de afstand is: " << _huidigeHaven->getAfstand(i) << std::endl;
	}
	int result;
	std::cin >> result;

	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin >> result;
	}
	int afstand = _huidigeHaven->getAfstand(result);
    _zee->enterZee(_huidigSchip, afstand);
	if (!_zee->vaar()) {
		Stop();
	}
	else {
		_huidigeHaven = &_havens[result];
		_huidigeHaven->seedHaven();
		_huidigeHaven->seedSchepen(_alleSchepen, 13);
		speelBeurt();
	}
}
