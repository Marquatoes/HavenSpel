#include "Haven.h"

Haven::Haven()
{
	_handelsGoederen = new Handelsgoed[10];
	_kanonnen = new Kanon[10];
	_aantalKanonnen = _aantalGoederen = 0;
	_naam = new char[100];
	_afstanden = new int[24];
}

Haven::Haven(Handelsgoed* handelsGoederen, int aantalGoederen, char* naam, int* afstanden) : _aantalGoederen{ aantalGoederen }, _aantalKanonnen { 0 }
{
	_naam = new char[100];
	std::memcpy(_naam, naam, 100);
	_handelsGoederen = new Handelsgoed[aantalGoederen];
	for (int i = 0; i < aantalGoederen; i++) {
		_handelsGoederen[i] = handelsGoederen[i];
	}
	_afstanden = new int[24];
	for (int i = 0; i < 24; i++) {
		_afstanden[i] = afstanden[i];
	}
	_kanonnen = new Kanon[10];

}

Haven::~Haven()
{
	if (_handelsGoederen != nullptr) {
		delete[] _handelsGoederen;
	}
	if (_kanonnen != nullptr) {
		delete[] _kanonnen;
	}
	if (_naam != nullptr) {
		delete[] _naam;
	}
	if (_afstanden != nullptr) {
		delete[] _afstanden;
	}
	_aantalGoederen = _aantalKanonnen = 0;

}

Haven::Haven(const Haven& copyHaven) :  _handelsGoederen { new Handelsgoed[copyHaven._aantalGoederen]}, 
_kanonnen { new Kanon[copyHaven._aantalKanonnen]}, _aantalGoederen{ copyHaven._aantalGoederen }, _aantalKanonnen{ copyHaven._aantalKanonnen }
{
	std::memcpy(_naam, copyHaven._naam, 100);
	std::memcpy(_handelsGoederen, copyHaven._handelsGoederen, copyHaven._aantalGoederen);
	std::memcpy(_kanonnen, copyHaven._kanonnen, copyHaven._aantalKanonnen);
	std::memcpy(_afstanden, copyHaven._afstanden, 24);
}

Haven& Haven::operator=(const Haven& copyHaven)
{
	if (&copyHaven == this) return *this;

	if (_handelsGoederen != nullptr) {
		delete[] _handelsGoederen;
	}
	if (_kanonnen != nullptr) {
		delete[] _kanonnen;
	}
	if (_afstanden != nullptr) {
		delete[] _afstanden;
	}

	std::memcpy(_naam, copyHaven._naam, 100);
	_handelsGoederen = copyHaven._handelsGoederen;
	_kanonnen = copyHaven._kanonnen;
	_aantalGoederen = copyHaven._aantalGoederen;
	_aantalKanonnen = copyHaven._aantalKanonnen;
	_afstanden = copyHaven._afstanden;
	return *this;
}

Haven::Haven(Haven&& moveHaven) noexcept :  _handelsGoederen{ moveHaven._handelsGoederen },
_kanonnen{ moveHaven._kanonnen }, _aantalGoederen{ moveHaven._aantalGoederen }, _aantalKanonnen{ moveHaven._aantalKanonnen }, _naam { moveHaven._naam }, _afstanden{ moveHaven._afstanden }
{
	moveHaven._handelsGoederen = nullptr;
	moveHaven._kanonnen = nullptr;
	moveHaven._naam = nullptr;
	moveHaven._afstanden = nullptr;
	moveHaven._aantalGoederen = moveHaven._aantalKanonnen = 0;
}

Haven& Haven::operator=(Haven&& moveHaven) noexcept
{
	if (&moveHaven == this) return *this;

	if (_handelsGoederen != nullptr) {
		delete[] _handelsGoederen;
	}
	if (_kanonnen != nullptr) {
		delete[] _kanonnen;
	}
	if (_naam != nullptr) {
		delete[] _naam;
	}
	if (_afstanden != nullptr) {
		delete[] _afstanden;
	}
	_naam = moveHaven._naam;
	_handelsGoederen = moveHaven._handelsGoederen;
	_aantalGoederen = moveHaven._aantalGoederen;
	_kanonnen = moveHaven._kanonnen;
	_afstanden = moveHaven._afstanden;

	moveHaven._handelsGoederen = nullptr;
	moveHaven._kanonnen = nullptr;
	moveHaven._naam = nullptr;
	moveHaven._afstanden = nullptr;
	moveHaven._aantalGoederen = moveHaven._aantalKanonnen = 0;

	return *this;
}

void Haven::seedHaven()
{
	seedKanonnen();
	seedGoederen();
}

void Haven::seedKanonnen()
{
	_aantalKanonnen = 0;
	_kanonnen = new Kanon[10];
	int random = RNG::Instance()->getRandomNumber(0, 5);	
	for (int i = _aantalKanonnen; i < random; i++) {
		char grootte[] = "licht";
		char* ptr = grootte; //same as char *ptr = &arr[0]
		_kanonnen[i] = Kanon(ptr, 50);
	}
	_aantalKanonnen += random;
	random = RNG::Instance()->getRandomNumber(0, 3);
	for (int i = _aantalKanonnen; i < _aantalKanonnen + random; i++) {
		char grootte[] = "middelgroot";
		char* ptr = grootte;
		_kanonnen [i] = Kanon(ptr, 200);
	}
	_aantalKanonnen += random;
	random = RNG::Instance()->getRandomNumber(0, 2);
	for (int i = _aantalKanonnen; i < _aantalKanonnen + random; i++) {
		char grootte[] = "zwaar";
		char* ptr = grootte;
		_kanonnen[i] = Kanon(ptr, 1000);
	}
	_aantalKanonnen += random;
	for (int i = 0; i < _aantalKanonnen; i++) {
		std::cout << _kanonnen[i].getPrijs() << std::endl;
		std::cout << _kanonnen[i].getType() << std::endl;
	}
	
}

void Haven::seedGoederen()
{
	for (int i = 0; i < _aantalGoederen; i++) {
		_handelsGoederen[i].setAantal(RNG::Instance()->getRandomNumber(_handelsGoederen[i].getMinAantal(), _handelsGoederen[i].getMaxAantal()));
		_handelsGoederen[i].setPrijs(RNG::Instance()->getRandomNumber(_handelsGoederen[i].getMinPrijs(), _handelsGoederen[i].getMaxPrijs()));
	}
}

void Haven::enterHaven(schip* vaarschip)
{
	seedHaven();
}

void Haven::repareer(schip* repareerSchip, Speler* speler, const int aantalSchadePunten)
{
	if (speler->getGoudstukken() >= (aantalSchadePunten / 10) && aantalSchadePunten <= repareerSchip->getSchade()) {
		repareerSchip->repareer(aantalSchadePunten);
		speler->setGoudstukken(speler->getGoudstukken() - (aantalSchadePunten / 10));
	}
	
}

void Haven::KoopGoederen(schip* havenschip, Speler* speler)
{
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Kies een handelsgoed om te kopen." << std::endl;
	for (int i = 0; i < _aantalGoederen; i++) {
		std::cout << i << ": " << _handelsGoederen[i].getType() << " | Prijs per stuk: " << _handelsGoederen[i].getPrijs() << " | Aantal beschikbaar: " << _handelsGoederen[i].getAantal() << std::endl;
	}
	int result;
	std::cin >> result;
	int aantal = _handelsGoederen[result].Koop(havenschip->getHandelsGoederen()[result].getAantal(), speler->getGoudstukken());
	speler->setGoudstukken(speler->getGoudstukken() - aantal * _handelsGoederen[result].getPrijs());
	havenschip->getHandelsGoederen()[result].setAantal(havenschip->getHandelsGoederen()[result].getAantal() + aantal);
}

void Haven::VerkoopGoederen(schip* havenschip, Speler* speler)
{
}

void Haven::KoopKanonnen(schip* havenschip, Speler* speler)
{
	if (_aantalKanonnen == 0) {
		std::cout << "Deze haven heeft geen kanonnen" << std::endl;
		return;
	}
	std::cout << "Welke type kanon wil je kopen?" << std::endl;
	std::cout << "Je hebt "<< speler->getGoudstukken() << " goudstukken"<< std::endl;
	for (int i = 0; i < _aantalKanonnen; i++) {
		std::cout << i << ": " << _kanonnen[i].getType() << "Kanon voor de prijs van "<< _kanonnen[i].getPrijs()  << std::endl;
	}
	int result;
	std::cin >> result;
	if (result <= _aantalKanonnen && result >= 0) {
		if (_kanonnen[result].getPrijs() < speler->getGoudstukken()) {
			speler->setGoudstukken(speler->getGoudstukken() - _kanonnen[result].getPrijs());
			if(havenschip->checkMaxKanonnen()) {
				havenschip->addKanon(std::move(_kanonnen[result]));
				for (int i = result; i < _aantalKanonnen - 1; i++) {
					_kanonnen[i] = Kanon(std::move(_kanonnen[i + 1]));
				}
				_aantalKanonnen--;
			}
			else {
				std::cout << "Je hebt al het maximale aantal kanonnen" << std::endl;
			}
			
		}
		else {
			std::cout << "Je hebt niet genoeg geld" << std::endl;
		}

	}
}

void Haven::VerkoopKanon(schip* havenschip, Speler* speler)
{
	havenschip->verkoopKanon(speler);
}

void Haven::KoopSchip()
{

}

void Haven::VerkoopSchip()
{
}

void Haven::Wegvaren()
{
}

void Haven::RepareerSchip()
{
}
