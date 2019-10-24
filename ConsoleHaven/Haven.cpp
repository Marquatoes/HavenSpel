#include "Haven.h"

Haven::Haven()
{
	_handelsGoederen = nullptr;
	_kanonnen = nullptr;
	_naam = nullptr;
	_afstanden = nullptr;
	_koopSchepen = nullptr;
	try {
		_handelsGoederen = new Handelsgoed[10];
		_kanonnen = new Kanon[10];
		_aantalKanonnen = _aantalGoederen = 0;
		_naam = new char[100];
		_afstanden = new int[24];
		_koopSchepen = new schip[10];
	}
	catch (...) {
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
		if (_koopSchepen != nullptr) {
			delete[] _koopSchepen;
		}
		throw;
	}
		
	
}

Haven::Haven(Handelsgoed* handelsGoederen, int aantalGoederen, char* naam, int* afstanden) : _aantalGoederen{ aantalGoederen }, _aantalKanonnen { 0 }
{
	_handelsGoederen = nullptr;
	_kanonnen = nullptr;
	_naam = nullptr;
	_afstanden = nullptr;
	_koopSchepen = nullptr;
	try {
		_naam = new char[100];
		_handelsGoederen = new Handelsgoed[aantalGoederen];
		_afstanden = new int[24];
		_kanonnen = new Kanon[10];
		_koopSchepen = new schip[13];
	}
	catch (...) {
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
		if (_koopSchepen != nullptr) {
			delete[] _koopSchepen;
		}
		throw;
	}
	
	std::memcpy(_naam, naam, 100);
	
	for (int i = 0; i < aantalGoederen; i++) {
		_handelsGoederen[i] = handelsGoederen[i];
	}
	
	for (int i = 0; i < 24; i++) {
		_afstanden[i] = afstanden[i];
	}
	

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
	if (_koopSchepen != nullptr) {
		delete[] _koopSchepen;
	}
	_aantalGoederen = _aantalKanonnen = _aantalKoopSchepen = 0;

}

Haven::Haven(const Haven& copyHaven) :  _handelsGoederen { new Handelsgoed[copyHaven._aantalGoederen]}, 
_kanonnen { new Kanon[copyHaven._aantalKanonnen]}, _aantalGoederen{ copyHaven._aantalGoederen }, _aantalKanonnen{ copyHaven._aantalKanonnen }, _aantalKoopSchepen { copyHaven._aantalKoopSchepen }
{
	_handelsGoederen = nullptr;
	_kanonnen = nullptr;
	_naam = nullptr;
	_afstanden = nullptr;
	_koopSchepen = nullptr;
	try {
		_naam = new char[100];
		_handelsGoederen = new Handelsgoed[_aantalGoederen];
		_afstanden = new int[24];
		_kanonnen = new Kanon[10];
		_koopSchepen = new schip[13];
	}
	catch (...) {
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
		if (_koopSchepen != nullptr) {
			delete[] _koopSchepen;
		}
		throw;
	}

	std::memcpy(_naam, copyHaven._naam, 100);
	std::memcpy(_handelsGoederen, copyHaven._handelsGoederen, copyHaven._aantalGoederen);
	std::memcpy(_kanonnen, copyHaven._kanonnen, copyHaven._aantalKanonnen);
	std::memcpy(_afstanden, copyHaven._afstanden, 24);
	std::memcpy(_koopSchepen, copyHaven._koopSchepen, copyHaven._aantalKoopSchepen);
}

Haven& Haven::operator=(const Haven& copyHaven)
{
	if (&copyHaven == this) return *this;

	Handelsgoed* handelsGoederen = nullptr;
	Kanon* kanonnen = nullptr;
	int* afstanden = nullptr;
	char* naam = nullptr;
	schip* koopSchepen = nullptr;
	try {
		handelsGoederen = new Handelsgoed[15];
		kanonnen = new Kanon[10];
		afstanden = new int[24];
		naam = new char[100];
		koopSchepen = new schip[copyHaven._aantalKoopSchepen];

		if (_handelsGoederen != nullptr) {
			delete[] _handelsGoederen;
		}
		if (_kanonnen != nullptr) {
			delete[] _kanonnen;
		}
		if (_afstanden != nullptr) {
			delete[] _afstanden;
		}
		if (_koopSchepen != nullptr) {
			delete[] _koopSchepen;
		}
		if (_naam != nullptr) {
			delete[] _naam;
		}

		_handelsGoederen = handelsGoederen;
		_kanonnen = kanonnen;
		_afstanden = afstanden;
		_koopSchepen = koopSchepen;
		_naam = naam;
	}
	catch (...) {
		if (handelsGoederen != nullptr) {
			delete[] _handelsGoederen;
		}
		if (kanonnen != nullptr) {
			delete[] _kanonnen;
		}
		if (afstanden != nullptr) {
			delete[] _afstanden;
		}
		if (koopSchepen != nullptr) {
			delete[] _koopSchepen;
		}
		if (naam != nullptr) {
			delete[] naam;
		}
		throw;
	}
	for (int i = 0; i < copyHaven._aantalKanonnen; i++) {
		_kanonnen[i] = Kanon();
		_kanonnen[i] = copyHaven._kanonnen[i];
	}
	for (int i = 0; i < 15; i++) {
		_handelsGoederen[i] = Handelsgoed();
		_handelsGoederen[i] = copyHaven._handelsGoederen[i];
	}
	for (int i = 0; i < copyHaven._aantalKoopSchepen; i++) {
		_koopSchepen[i] = schip();
		_koopSchepen[i] = copyHaven._koopSchepen[i];
	}
	std::memcpy(_naam, copyHaven._naam, 100);
	_aantalGoederen = copyHaven._aantalGoederen;
	_aantalKanonnen = copyHaven._aantalKanonnen;
	_afstanden = copyHaven._afstanden;
	_aantalKoopSchepen = copyHaven._aantalKoopSchepen;
	return *this;
}

Haven::Haven(Haven&& moveHaven) noexcept :  _handelsGoederen{ moveHaven._handelsGoederen },
_kanonnen{ moveHaven._kanonnen }, _aantalGoederen{ moveHaven._aantalGoederen }, _aantalKanonnen{ moveHaven._aantalKanonnen }, _naam { moveHaven._naam }, 
_afstanden{ moveHaven._afstanden }, _aantalKoopSchepen {moveHaven._aantalKoopSchepen}, _koopSchepen { moveHaven._koopSchepen }
{
	moveHaven._handelsGoederen = nullptr;
	moveHaven._kanonnen = nullptr;
	moveHaven._naam = nullptr;
	moveHaven._afstanden = nullptr;
	moveHaven._koopSchepen = nullptr;
	moveHaven._aantalGoederen = moveHaven._aantalKanonnen = moveHaven._aantalKoopSchepen = 0;
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
	if (_koopSchepen != nullptr) {
		delete[] _koopSchepen;
	}

	_naam = moveHaven._naam;
	_handelsGoederen = moveHaven._handelsGoederen;
	_aantalGoederen = moveHaven._aantalGoederen;
	_kanonnen = moveHaven._kanonnen;
	_afstanden = moveHaven._afstanden;
	_aantalKoopSchepen = moveHaven._aantalKoopSchepen;
	_koopSchepen = moveHaven._koopSchepen;

	moveHaven._koopSchepen = nullptr;
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
	if (_kanonnen != nullptr) {
		delete[] _kanonnen;
	}
	_kanonnen = nullptr;
	try {
		_kanonnen = new Kanon[10];
	}
	catch (...) {

		throw;
	}
	_aantalKanonnen = 0;
	
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

void Haven::KoopGoederen(schip* havenschip, Speler* speler)
{
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Druk op 0 om terug te gaan" << std::endl;
	std::cout << "Kies een handelsgoed om te kopen." << std::endl;
	for (int i = 0; i < _aantalGoederen; i++) {
		std::cout << i + 1 << ": " << _handelsGoederen[i].getType() << " | Prijs per stuk: " << _handelsGoederen[i].getPrijs() << " | Aantal beschikbaar: " << _handelsGoederen[i].getAantal() << std::endl;
	}
	int result;
	std::cin >> result;

	while (!std::cin.good() || result > _aantalGoederen)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin >> result;
	}
	
	if (result == 0) {
		return;
	}

	int aantal = _handelsGoederen[result - 1].Koop(havenschip->getHandelsGoederen()[result - 1].getAantal(), speler->getGoudstukken());
	if (havenschip->getCapaciteit() > havenschip->getAantalHandelsGoederen() + aantal) {
		speler->setGoudstukken(speler->getGoudstukken() - aantal * _handelsGoederen[result - 1].getPrijs());
		havenschip->getHandelsGoederen()[result - 1].setAantal(havenschip->getHandelsGoederen()[result - 1].getAantal() + aantal);
		_handelsGoederen[result - 1].setAantal(_handelsGoederen[result - 1].getAantal() - aantal);
	}
	else {
		std::cout << "Er is niet genoeg laadruimte beschikbaar voor dat aantal grondstoffen." << std::endl;
		KoopGoederen(havenschip, speler);
	}
	
}

void Haven::VerkoopGoederen(schip* havenschip, Speler* speler)
{
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Druk op 0 om terug te gaan" << std::endl;
	std::cout << "Kies een handelsgoed om te verkopen." << std::endl;
	for (int i = 0; i < _aantalGoederen; i++) {
		std::cout << i + 1 << ": " << _handelsGoederen[i].getType() << " | Prijs per stuk: " << _handelsGoederen[i].getPrijs() << " | Aantal in inventaris: " << havenschip->getHandelsGoederen()[i].getAantal() << std::endl;
	}
	int result;
	std::cin >> result;

	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin >> result;
	}
	if (result == 0) {
		return;
	}
	int aantal = _handelsGoederen[result - 1].Verkoop(havenschip->getHandelsGoederen()[result - 1].getAantal(), speler->getGoudstukken());
	speler->setGoudstukken(speler->getGoudstukken() + aantal * _handelsGoederen[result - 1].getPrijs());
	havenschip->getHandelsGoederen()[result - 1].setAantal(havenschip->getHandelsGoederen()[result - 1].getAantal() - aantal);
}

void Haven::KoopKanonnen(schip* havenschip, Speler* speler)
{
	if (_aantalKanonnen == 0) {
		std::cout << "Deze haven heeft geen kanonnen" << std::endl;
		return;
	}
	std::cout << "Druk op 0 om terug te gaan" << std::endl;
	std::cout << "Welke type kanon wil je kopen?" << std::endl;
	std::cout << "Je hebt "<< speler->getGoudstukken() << " goudstukken"<< std::endl;
	for (int i = 0; i < _aantalKanonnen; i++) {
		std::cout << i+1 << ": " << _kanonnen[i].getType() << "Kanon voor de prijs van "<< _kanonnen[i].getPrijs()  << std::endl;
	}
	int result;
	std::cin >> result;

	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin >> result;
	}

	if (result == 0) {
		return;
	}
	if (result <= _aantalKanonnen && result > 0) {
		if (_kanonnen[result - 1].getPrijs() < speler->getGoudstukken()) {
			speler->setGoudstukken(speler->getGoudstukken() - _kanonnen[result - 1].getPrijs());
			if(havenschip->checkMaxKanonnen()) {
				havenschip->addKanon(std::move(_kanonnen[result - 1]));
				for (int i = result - 1; i < _aantalKanonnen - 1; i++) {
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

void Haven::KoopSchip(Speler* speler, schip*& huidigSchip)
{
	if(_aantalKoopSchepen <= 0) { 
		std::cout << "De schepen zijn op" << std::endl;
		return;
	}

	std::cout << "welk schip wil je kopen?" << std::endl;
	for (int i = 0; i < _aantalKoopSchepen; i++) {
		std::cout << i+1 << ": " << _koopSchepen[i].getType() << " kost: " << _koopSchepen[i].getPrijs() << " en heeft ruimte voor " << _koopSchepen[i].getMaxAantalHandelsGoederen() << std::endl;
		std::cout << "En " << _koopSchepen[i].getMaxAantalKanonnen() << " kanonnen, en heeft als bijzonderheden: " << _koopSchepen[i].getBijzonderheden() << std::endl;
	}
	std::cout << "druk op 0 om terug te gaan" << std::endl;
	int result;
	std::cin >> result;
	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin >> result;
	}
	if (result > 0 && result <= _aantalKoopSchepen) {
		if (_koopSchepen[result - 1].getPrijs() < (speler->getGoudstukken() + huidigSchip->getPrijs()/ 2)) {
			speler->setGoudstukken(speler->getGoudstukken() + (huidigSchip->getPrijs() / 2) - _koopSchepen[result - 1].getPrijs());
			schip* tmp = nullptr;
			try {
				tmp = new schip();
				delete huidigSchip;
				huidigSchip = tmp;
				*huidigSchip = std::move(_koopSchepen[result - 1]);
			}
			catch (...) {
				if (tmp != nullptr) {
					delete tmp;
				}
				throw;
			}
			
			
			for (int i = result - 1; i < _aantalKoopSchepen - 1; i++) {
				_koopSchepen[i] = schip(std::move(_koopSchepen[i + 1]));
			}
			_aantalKoopSchepen--;
			std::cout << "Je hebt een " << huidigSchip->getType() << " gekocht" << std::endl;
			return;
		}
		std::cout << "Armoede is wel een dingetje, ga nog maar ff sparen jonge" << std::endl;
	}
	
}
void Haven::seedSchepen(const schip* mogelijkeSchepen, const int aantalSchepen) {
	if (_koopSchepen != nullptr)
	{
		delete[] _koopSchepen; 
	}
	_koopSchepen = nullptr;
	_aantalKoopSchepen = RNG::Instance()->getRandomNumber(0, aantalSchepen);
	try {
		_koopSchepen = new schip[_aantalKoopSchepen];
	}
	catch (...) {
		throw;
	}
	
	int beginVanaf = RNG::Instance()->getRandomNumber(0, aantalSchepen - _aantalKoopSchepen);
	
	for (int i = 0; i < _aantalKoopSchepen ; i++) {
		//memory safety is handled in copy contructor
		_koopSchepen[i] = mogelijkeSchepen[beginVanaf];
		++beginVanaf;
	}
}

int Haven::getAfstand(const int havenNummer) const
{
	return _afstanden[havenNummer];
}

void Haven::RepareerSchip(Speler* speler, schip* huidigSchip) const
{
	std::cout << "druk op 0 om terug te gaan" << std::endl;
	std::cout << "Repareren kost 1 goudstuk per 10 schadepunten, hoeveel wens je er te repareren" << std::endl;
	std::cout << "Je kunt maximaal " << huidigSchip->getMaxSchadePuntenOmTeRepareren() << " repareren" << std::endl;
	int result;
	std::cin >> result;
	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin >> result;
	}
	if (result <= 0) {
		return;
	}
	if (speler->getGoudstukken() > result / 10) {
		speler->setGoudstukken(speler->getGoudstukken() - result / 10);
		if (!huidigSchip->repareer(result)) {
			RepareerSchip(speler, huidigSchip);
		}
	}
	else {
		std::cout << "Je bent te sceer" << std::endl;
	}
}

const char* Haven::getNaam() const
{
	return _naam;
}
