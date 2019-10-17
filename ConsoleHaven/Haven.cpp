#include "Haven.h"

Haven::Haven(schip* dockedSchip, schip* koopSchepen, Handelsgoed* handelsGoederen, size_t aantalSchepen, size_t aantalGoederen, size_t aantalKannonen) :
	_dockedSchip{ dockedSchip }, _koopSchepen{ koopSchepen }, _handelsGoederen{ handelsGoederen }, _aantalSchepen { aantalSchepen }, _aantalGoederen { aantalGoederen } , _aantalKannonen { aantalKannonen } 
{
	_kannonen = nullptr;
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
	if (_kannonen != nullptr) {
		delete[] _kannonen;
	}
	_aantalSchepen = _aantalGoederen = _aantalKannonen = 0;

}

Haven::Haven(const Haven& copyHaven) : _dockedSchip { copyHaven._dockedSchip }, _koopSchepen { new schip[copyHaven._aantalSchepen]}, _handelsGoederen { new Handelsgoed[copyHaven._aantalGoederen]}, 
_kannonen { new Kannon[copyHaven._aantalKannonen]},_aantalSchepen { copyHaven._aantalSchepen}, _aantalGoederen{ copyHaven._aantalGoederen }, _aantalKannonen{ copyHaven._aantalKannonen }
{
	std::memcpy(_koopSchepen,copyHaven._koopSchepen, copyHaven._aantalSchepen);
	std::memcpy(_handelsGoederen, copyHaven._handelsGoederen, copyHaven._aantalGoederen);
	std::memcpy(_kannonen, copyHaven._kannonen, copyHaven._aantalKannonen);
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
	if (_kannonen != nullptr) {
		delete _kannonen;
	}

	_dockedSchip = copyHaven._dockedSchip;
	_handelsGoederen = copyHaven._handelsGoederen;
	_koopSchepen = copyHaven._koopSchepen;
	_kannonen = copyHaven._kannonen;
	return *this;
}

Haven::Haven(Haven&& moveHaven) noexcept : _dockedSchip { moveHaven._dockedSchip }, _koopSchepen{ moveHaven._koopSchepen }, _handelsGoederen{ moveHaven._handelsGoederen },
_kannonen{ moveHaven._kannonen }, _aantalSchepen{ moveHaven._aantalSchepen }, _aantalGoederen{ moveHaven._aantalGoederen }, _aantalKannonen{ moveHaven._aantalKannonen }
{
	moveHaven._dockedSchip = nullptr;
	moveHaven._handelsGoederen = nullptr;
	moveHaven._kannonen = nullptr;
	moveHaven._koopSchepen = nullptr;
	moveHaven._aantalGoederen = moveHaven._aantalKannonen = moveHaven._aantalSchepen  = 0;
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
	if (_kannonen != nullptr) {
		delete _kannonen;
	}

	_dockedSchip = moveHaven._dockedSchip;
	_handelsGoederen = moveHaven._handelsGoederen;
	_koopSchepen = moveHaven._koopSchepen;
	_kannonen = moveHaven._kannonen;

	moveHaven._dockedSchip = nullptr;
	moveHaven._handelsGoederen = nullptr;
	moveHaven._kannonen = nullptr;
	moveHaven._koopSchepen = nullptr;
	moveHaven._aantalGoederen = moveHaven._aantalKannonen = moveHaven._aantalSchepen = 0;

	return *this;
}

void Haven::seedHaven(RNG *rng)
{
	seedKannonen(rng);
	seedGoederen(rng);
}

void Haven::seedKannonen(RNG* rng)
{
	_aantalKannonen = 0;
	_kannonen = new Kannon[10];
	int random = rng->getRandomNumber(0, 5);	
	for (int i = _aantalKannonen; i < random; i++) {
		_kannonen[i] = Kannon(1, 50);
	}
	_aantalKannonen += random;
	random = rng->getRandomNumber(0, 3);
	for (int i = _aantalKannonen; i < _aantalKannonen + random; i++) {
		_kannonen [i] = Kannon(2, 200);
	}
	_aantalKannonen += random;
	random = rng->getRandomNumber(0, 2);
	for (int i = _aantalKannonen; i < _aantalKannonen + random; i++) {
		_kannonen[i] = Kannon(3, 1000);
	}
	_aantalKannonen += random;
	for (int i = 0; i < _aantalKannonen; i++) {
		std::cout << _kannonen[i].getPrijs() << std::endl;
	}
}

void Haven::seedGoederen(RNG* rng)
{
	for (int i = 0; i < _aantalGoederen; i++) {
		_handelsGoederen[i].setAantal(rng->getRandomNumber(_handelsGoederen[i].getMinAantal(), _handelsGoederen[i].getMaxAantal()));
		_handelsGoederen[i].setPrijs(rng->getRandomNumber(_handelsGoederen[i].getMinPrijs(), _handelsGoederen[i].getMaxPrijs()));
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
void Haven::koopKannon(schip* schip, Speler* speler, int type) {
	
	//Selecteer optie
	for (int i = 0; i < _aantalKannonen; i++) {
		if (_kannonen[i].getType() == type && _kannonen[i].getPrijs() < speler->getGoudstukken()) {
			speler->setGoudstukken(speler->getGoudstukken() - _kannonen[i].getPrijs());
			//Move kannon to schip
			_dockedSchip->addKannon(_kannonen[i]);
		}
	}
}

