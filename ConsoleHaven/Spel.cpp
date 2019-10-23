#include "Spel.h"

void Spel::Start()
{
	_havens[0].enterHaven(_huidigSchip);
	_huidigeHaven = &_havens[0];
	_huidigeHaven->seedSchepen(_alleSchepen, 13);
	speelBeurt();
}

void Spel::speelBeurt()
{
	std::cout << "Je bent in een haven, dit zijn je opties" << std::endl;
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
		std::cout << _huidigSchip->getType() << std::endl;
		break;
	case 6:
		_huidigeHaven->Wegvaren();
		break;
	case 7:
		_huidigeHaven->RepareerSchip();
		break;
	case 8:
		Stop();
		return;
		
	}
	speelBeurt();
}

Spel::Spel()
{
	_alleSchepen = new schip[13];
	_havens = new Haven[24];
	_speler = new Speler(200000);
	FileReader f = FileReader();
	f.ReadSchepenFile(_alleSchepen);
	f.MaakHavens(_havens);
	_huidigSchip = new schip();
	*_huidigSchip = _alleSchepen[0];
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
	RNG::Release();
}

void Spel::Stop()
{
}
