#include "Haven.h"

Haven::Haven()
{
	_handelsGoederen = new Handelsgoed[10];
	_kanonnen = new Kanon[10];
	_aantalKanonnen = _aantalGoederen = 0;
}

Haven::Haven(Handelsgoed* handelsGoederen, size_t aantalGoederen) : _aantalGoederen{ aantalGoederen }, _aantalKanonnen { 0 }
{
	_handelsGoederen = new Handelsgoed[aantalGoederen];
	for (int i = 0; i < aantalGoederen; i++) {
		_handelsGoederen[i] = handelsGoederen[i];
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
	_aantalGoederen = _aantalKanonnen = 0;

}

Haven::Haven(const Haven& copyHaven) :  _handelsGoederen { new Handelsgoed[copyHaven._aantalGoederen]}, 
_kanonnen { new Kanon[copyHaven._aantalKanonnen]}, _aantalGoederen{ copyHaven._aantalGoederen }, _aantalKanonnen{ copyHaven._aantalKanonnen }
{
	std::memcpy(_handelsGoederen, copyHaven._handelsGoederen, copyHaven._aantalGoederen);
	std::memcpy(_kanonnen, copyHaven._kanonnen, copyHaven._aantalKanonnen);
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

	_handelsGoederen = copyHaven._handelsGoederen;
	_kanonnen = copyHaven._kanonnen;
	return *this;
}

Haven::Haven(Haven&& moveHaven) noexcept :  _handelsGoederen{ moveHaven._handelsGoederen },
_kanonnen{ moveHaven._kanonnen }, _aantalGoederen{ moveHaven._aantalGoederen }, _aantalKanonnen{ moveHaven._aantalKanonnen }
{
	moveHaven._handelsGoederen = nullptr;
	moveHaven._kanonnen = nullptr;
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

	_handelsGoederen = moveHaven._handelsGoederen;
	_kanonnen = moveHaven._kanonnen;

	moveHaven._handelsGoederen = nullptr;
	moveHaven._kanonnen = nullptr;
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
void Haven::koopKanon(schip* schip, Speler* speler, char* type) {
	
	//Selecteer optie
	for (int i = 0; i < _aantalKanonnen; i++) {
		if (std::strcmp(_kanonnen[i].getType(), type) == 0 && _kanonnen[i].getPrijs() < speler->getGoudstukken()) {
			speler->setGoudstukken(speler->getGoudstukken() - _kanonnen[i].getPrijs());
			//Move kanon to schip
			schip->addKanon(_kanonnen[i]);
		}
	}
}

void Haven::KoopGoederen()
{
}

void Haven::VerkoopGoederen()
{
}

void Haven::KoopKanonnen()
{
}

void Haven::VerkoopKanonnen()
{
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
