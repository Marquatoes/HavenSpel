#include "schip.h"

schip::schip() : _prijs{ 0 }, _laadruimte{ 0 }, _maxKanonnen{ 0 }, _schadepunten{ 0 }, _aantalKanonnen{ 0 }
{
	_type = new char[100];
	_bijzonderheden = new char[100];
	_kanonnen = new Kanon[10];
}

schip::schip(char *type, int prijs, int laadruimte, int maxKanonnen, int schadepunten, char *bijzonderheden, Kanon* kanonnen, int aantalKanonnen) :
	_prijs{ prijs }, _laadruimte{ laadruimte }, _maxKanonnen{ maxKanonnen }, _schadepunten{ schadepunten }, _bijzonderheden{ bijzonderheden }, _kanonnen{ kanonnen }, _aantalKanonnen{ aantalKanonnen } {
	_type = type;
	_handelsGoederen = new Handelsgoed[15];
	for (int i = 0; i < 15; i++) {
		_handelsGoederen[i] = Handelsgoed();
	}
};

schip::~schip()
{
	if (_type != nullptr) {
		delete[] _type;
	}
	if (_bijzonderheden != nullptr) {
		delete[] _bijzonderheden;
	}
	if (_kanonnen != nullptr) {
		delete[] _kanonnen;
	}
	if (_handelsGoederen != nullptr) {
		delete[] _handelsGoederen;
	}
}

schip::schip(const schip& copySchip) : _type{ new char[100] }, _prijs{ copySchip._prijs }, _laadruimte{ copySchip._laadruimte }, _maxKanonnen{ copySchip._maxKanonnen }, _schadepunten{ copySchip._schadepunten }, _bijzonderheden{ new char[100] }, _kanonnen{ new Kanon[_maxKanonnen] }, _aantalKanonnen{ 0 } {
	std::memcpy(_type, copySchip._type, 100);
	std::memcpy(_bijzonderheden, copySchip._bijzonderheden, 100);
	std:memcpy(_kanonnen, copySchip._kanonnen, _maxKanonnen);
}

schip& schip::operator=(const schip& copySchip)
{
	if (&copySchip == this) return *this;

	if (_type != nullptr) {
		delete[] _type;
	}
	if (_bijzonderheden != nullptr) {
		delete[] _bijzonderheden;
	}
	if (_kanonnen != nullptr) {
		delete[] _kanonnen;
	}
	_type = new char[100];
	std::memcpy(_type, copySchip._type, 100);
	_prijs = copySchip._prijs;
	_laadruimte = copySchip._laadruimte;
	_maxKanonnen = copySchip._maxKanonnen;
	_schadepunten = copySchip._schadepunten;
	_bijzonderheden = new char[100];
	std::memcpy(_bijzonderheden, copySchip._bijzonderheden, 100);
	_kanonnen = new Kanon[copySchip._maxKanonnen];
	for (int i = 0; i < copySchip._aantalKanonnen; i++) {
		_kanonnen[i] = Kanon();
		_kanonnen[i] = copySchip._kanonnen[i];
	}
	for (int i = 0; i < 15; i++) {
		_handelsGoederen[i] = Handelsgoed();
		_handelsGoederen[i] = copySchip._handelsGoederen[i];
	}
	_aantalKanonnen = copySchip._aantalKanonnen;
	return *this;
}

schip::schip(schip&& moveSchip) noexcept : _type{ moveSchip._type }, _prijs{ moveSchip._prijs }, _laadruimte{ moveSchip._laadruimte }, _maxKanonnen{ moveSchip._maxKanonnen }, _schadepunten{ moveSchip._schadepunten }, _bijzonderheden{ moveSchip._bijzonderheden }, _kanonnen{ moveSchip._kanonnen }, _aantalKanonnen{ moveSchip._aantalKanonnen }, _handelsGoederen{ moveSchip._handelsGoederen } {
	moveSchip._type = nullptr;
	moveSchip._bijzonderheden = nullptr;
	moveSchip._kanonnen = nullptr;
	moveSchip._handelsGoederen = nullptr;
	moveSchip._maxKanonnen = moveSchip._prijs = moveSchip._schadepunten = moveSchip._laadruimte = moveSchip._aantalKanonnen = 0;
}

schip& schip::operator=(schip&& moveSchip) noexcept
{
	if (&moveSchip == this) {
		return *this;
	}
	if (_type != nullptr) {
		delete[] _type;
	}
	if (_bijzonderheden != nullptr) {
		delete[] _bijzonderheden;
	}
	if (_kanonnen != nullptr) {
		delete[] _kanonnen;
	}

	_type = moveSchip._type;
	_prijs = moveSchip._prijs;
	_laadruimte = moveSchip._laadruimte;
	_maxKanonnen = moveSchip._maxKanonnen;
	_schadepunten = moveSchip._schadepunten;
	_bijzonderheden = moveSchip._bijzonderheden;
	_kanonnen = moveSchip._kanonnen;
	_aantalKanonnen = moveSchip._aantalKanonnen;
	_handelsGoederen = moveSchip._handelsGoederen;
	moveSchip._type = nullptr;
	moveSchip._bijzonderheden = nullptr;
	moveSchip._kanonnen = nullptr;
	moveSchip._handelsGoederen = nullptr;
	moveSchip._maxKanonnen = moveSchip._aantalKanonnen = moveSchip._prijs = moveSchip._schadepunten = moveSchip._laadruimte = 0;

	return *this;
}

void schip::repareer(int aantalSchadePunten)
{
	if (_schadepunten > aantalSchadePunten) {
		_schadepunten -= aantalSchadePunten;
	}
	else {
		_schadepunten = 0;
	}
}

const int schip::getSchade()
{
	return _schadepunten;
}

const int schip::getDamage()
{
	int dmg = 0;
	for (int i = 0; i < _aantalKanonnen; i++) {
		dmg += _kanonnen[i].getDamage();
	}
	return dmg;
}

void schip::setSchade(int aantal)
{
	_schadepunten = aantal;
}

const bool schip::hasBijzonderheid(const char* bijzonderheid)
{
	char* copy = new char[100];
	strcpy_s(copy, 100 , _bijzonderheden);
	if (bijzonderheid != nullptr) {
		char* next_token1{};
		copy = strtok_s(copy, ",", &next_token1);
		if (std::strcmp(copy, bijzonderheid) == 0) {
			delete[] copy;
			return true;
		}
		if (next_token1 != nullptr && std::strcmp(next_token1, bijzonderheid) == 0)
		{
			delete[] copy;
			return true;
		}
		delete[] copy;
	}
	return false;
}

void schip::addKanon(Kanon kanon)
{
	if (_aantalKanonnen < _maxKanonnen) {
		_kanonnen[_aantalKanonnen] = std::move(kanon);
		_aantalKanonnen++;
	}
}
bool schip::checkMaxKanonnen() {
	if (_aantalKanonnen < _maxKanonnen) {
		return true;
	}
	return false;
}
void schip::verkoopKanon(Speler* speler) {
	if (_aantalKanonnen == 0) {
		std::cout << "Je hebt geen kanonnen, beetje gevaarlijk niet?" << std::endl;
		return;
	}
	for (int i = 0; i < _aantalKanonnen; i++) {
		std::cout << i << ": " << _kanonnen[i].getType() << "Kanon voor de prijs van: " << _kanonnen[i].getPrijs() << std::endl;
	}
	int result;
	std::cin >> result;
	if (result >= 0 && result < _aantalKanonnen) {
		speler->setGoudstukken(speler->getGoudstukken() + _kanonnen[result].getPrijs());
		--_aantalKanonnen;
	}
	else {
		for (int i = result; i < _aantalKanonnen - 1; i++) {
			_kanonnen[i] = _kanonnen[i+1];
		}
	}
}

void schip::seedKanonnen(int aantal)
{
	if (_kanonnen != nullptr) {
		delete[] _kanonnen;
	}
	_aantalKanonnen = 0;

	_kanonnen = new Kanon[aantal];
	for (int i = 0; i < aantal; i++) {
		int random;
		if (hasBijzonderheid("klein")) {
			random = RNG::Instance()->getRandomNumber(0, 1);
		}
		else {
			random = RNG::Instance()->getRandomNumber(0, 2);
		}
		
		char* kanonGrootte;
		if (random == 0) {
			char grootte[] = "licht";
			kanonGrootte = grootte;
		}
		else if (random == 1) {
			char grootte[] = "middelgroot";
			kanonGrootte = grootte;
		}
		else {
			char grootte[] = "zwaar";
			kanonGrootte = grootte;
		}
		_kanonnen[i] = Kanon(kanonGrootte, 50);
	}
}

void schip::dumpHandelsgoederen()
{
	
}

Handelsgoed* schip::getHandelsGoederen()
{
	return _handelsGoederen;
}

const int schip::getAantalHandelsGoederen()
{
	int aantal = 0;
	for (int i = 0; i < 15; i++) {
		aantal += _handelsGoederen[i].getAantal();
	}
	return aantal;
}

const int schip::getCapaciteit()
{
	return _laadruimte;
}
int schip::getPrijs() const {
	return _prijs;
}

int schip::getMaxAantalHandelsGoederen() const
{
	return _laadruimte;
}

int schip::getMaxAantalKanonnen() const
{
	return _maxKanonnen;
}
const char* schip::getType() const {
	return _type;
}
const char* schip::getBijzonderheden() const {
	return _bijzonderheden;
}

