#include "Haven.h"
#include <cstring>

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
		delete[] _koopSchepen;
	}
	if (_handelsGoederen != nullptr) {
		delete[] _handelsGoederen;
	}
	if (_kannonen != nullptr) {
		delete[] _kannonen;
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
		delete[] _koopSchepen;
	}
	if (_handelsGoederen != nullptr) {
		delete[] _handelsGoederen;
	}
	if (_kannonen != nullptr) {
		delete[] _kannonen;
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

void Haven::seedCannons(RNG *rng)
{
	int aantal = 0;
	_kannonen = nullptr;
	_kannonen = new Kannon[10];
	int random = rng->getRandomNumber(0, 5);
	aantal += random;
	for (int i = 0; i < random; i++) {
		_kannonen[i] = *new Kannon(1, 50);
	}
	random = rng->getRandomNumber(0, 3);
	aantal += random;
	for (int i = aantal; i < aantal + random; i++) {
		_kannonen[i] = *new Kannon(2, 200);
	}
	random = rng->getRandomNumber(0, 2);
	aantal += random;
	for (int i = aantal; i < aantal + random; i++) {
		_kannonen[i] = *new Kannon(3, 1000);
	}
	_aantalKannonen = aantal;
}
