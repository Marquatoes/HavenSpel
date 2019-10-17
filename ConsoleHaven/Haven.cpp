#include "Haven.h"

Haven::Haven(schip* dockedSchip, schip* koopSchepen, Handelsgoed* handelsGoederen, size_t aantalSchepen, size_t aantalGoederen, size_t aantalKanonnen) :
	_dockedSchip{ dockedSchip }, _koopSchepen{ koopSchepen }, _handelsGoederen{ handelsGoederen }, _aantalSchepen { aantalSchepen }, _aantalGoederen { aantalGoederen } , _aantalKanonnen { aantalKanonnen } 
{
	_kanonnen = nullptr;
}

Haven::~Haven()
{
	if (_dockedSchip != nullptr) {
		delete _dockedSchip;
	}
	if (_koopSchepen != nullptr) {
		delete[] _koopSchepen;
	}
	if (_handelsGoederen != nullptr) {
		delete[] _handelsGoederen;
	}
	if (_kanonnen != nullptr) {
		delete[] _kanonnen;
	}
	_aantalSchepen = _aantalGoederen = _aantalKanonnen = 0;

}

Haven::Haven(const Haven& copyHaven) : _dockedSchip { copyHaven._dockedSchip }, _koopSchepen { new schip[copyHaven._aantalSchepen]}, _handelsGoederen { new Handelsgoed[copyHaven._aantalGoederen]}, 
_kanonnen { new Kanon[copyHaven._aantalKanonnen]},_aantalSchepen { copyHaven._aantalSchepen}, _aantalGoederen{ copyHaven._aantalGoederen }, _aantalKanonnen{ copyHaven._aantalKanonnen }
{
	std::memcpy(_koopSchepen,copyHaven._koopSchepen, copyHaven._aantalSchepen);
	std::memcpy(_handelsGoederen, copyHaven._handelsGoederen, copyHaven._aantalGoederen);
	std::memcpy(_kanonnen, copyHaven._kanonnen, copyHaven._aantalKanonnen);
}

Haven& Haven::operator=(const Haven& copyHaven)
{
	if (&copyHaven == this) return *this;

	if (_dockedSchip != nullptr) {
		delete _dockedSchip;
	}
	if (_koopSchepen != nullptr) {
		delete _koopSchepen;
	}
	if (_handelsGoederen != nullptr) {
		delete _handelsGoederen;
	}
	if (_kanonnen != nullptr) {
		delete _kanonnen;
	}

	_dockedSchip = copyHaven._dockedSchip;
	_handelsGoederen = copyHaven._handelsGoederen;
	_koopSchepen = copyHaven._koopSchepen;
	_kanonnen = copyHaven._kanonnen;
	return *this;
}

Haven::Haven(Haven&& moveHaven) noexcept : _dockedSchip { moveHaven._dockedSchip }, _koopSchepen{ moveHaven._koopSchepen }, _handelsGoederen{ moveHaven._handelsGoederen },
_kanonnen{ moveHaven._kanonnen }, _aantalSchepen{ moveHaven._aantalSchepen }, _aantalGoederen{ moveHaven._aantalGoederen }, _aantalKanonnen{ moveHaven._aantalKanonnen }
{
	moveHaven._dockedSchip = nullptr;
	moveHaven._handelsGoederen = nullptr;
	moveHaven._kanonnen = nullptr;
	moveHaven._koopSchepen = nullptr;
	moveHaven._aantalGoederen = moveHaven._aantalKanonnen = moveHaven._aantalSchepen  = 0;
}

Haven& Haven::operator=(Haven&& moveHaven) noexcept
{
	if (&moveHaven == this) return *this;

	if (_dockedSchip != nullptr) {
		delete _dockedSchip;
	}
	if (_koopSchepen != nullptr) {
		delete _koopSchepen;
	}
	if (_handelsGoederen != nullptr) {
		delete _handelsGoederen;
	}
	if (_kanonnen != nullptr) {
		delete _kanonnen;
	}

	_dockedSchip = moveHaven._dockedSchip;
	_handelsGoederen = moveHaven._handelsGoederen;
	_koopSchepen = moveHaven._koopSchepen;
	_kanonnen = moveHaven._kanonnen;

	moveHaven._dockedSchip = nullptr;
	moveHaven._handelsGoederen = nullptr;
	moveHaven._kanonnen = nullptr;
	moveHaven._koopSchepen = nullptr;
	moveHaven._aantalGoederen = moveHaven._aantalKanonnen = moveHaven._aantalSchepen = 0;

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
		char grootte[] = "licht";
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

void Haven::enterHaven(schip* enterSchip)
{
	_dockedSchip = std::move(enterSchip);
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
			_dockedSchip->addKanon(_kanonnen[i]);
		}
	}
}

