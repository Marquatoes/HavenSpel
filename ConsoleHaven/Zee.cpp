#include "Zee.h"
Zee::Zee(int turns, schip* schepen) : _turns{ turns }, _vaarSchip{ nullptr }, _piraten{ nullptr }, _schepen {schepen}
{

}

Zee::~Zee()
{
	if (_vaarSchip != nullptr) {
		delete _vaarSchip;
	}
	if (_piraten != nullptr) {
		delete _piraten;
	}
	
}

Zee::Zee(const Zee& copyZee) : _turns {copyZee._turns}, _vaarSchip{copyZee._vaarSchip}, _piraten{copyZee._piraten}, _schepen { new schip[13]}
{
	std:memcpy(_schepen, copyZee._schepen, 13);
}

Zee& Zee::operator=(const Zee& copyZee)
{
	if (&copyZee == this) return *this;

	if (_piraten != nullptr) {
		delete _piraten;
	}
	if (_vaarSchip != nullptr) {
		delete _vaarSchip;
	}
	if (_schepen != nullptr) {
		delete[] _schepen;
	}

	_piraten = copyZee._piraten;
	_vaarSchip = copyZee._vaarSchip;
	_schepen = copyZee._schepen;
	_turns = copyZee._turns;
	return *this;
}

Zee::Zee(Zee&& moveZee) noexcept : _turns{ moveZee._turns }, _vaarSchip{ moveZee._vaarSchip }, _piraten{ moveZee._piraten }, _schepen{moveZee._schepen}
{
	_piraten = nullptr;
	_vaarSchip = nullptr;
	_schepen = nullptr;
	_turns = 0;
}

Zee& Zee::operator=(Zee&& moveZee) noexcept
{
	if (&moveZee == this) {
		return *this;
	}
	if (_piraten != nullptr) {
		delete _piraten;
	}
	if (_vaarSchip != nullptr) {
		delete _vaarSchip;
	}
	if (_schepen != nullptr) {
		delete _schepen;
	}

	_piraten = moveZee._piraten;
	_vaarSchip = moveZee._vaarSchip;
	_turns = moveZee._turns;
	_schepen = moveZee._schepen;

	moveZee._piraten = nullptr;
	moveZee._vaarSchip = nullptr;
	moveZee._schepen = nullptr;
	moveZee._turns = 0;
	
	return *this;
}

void Zee::enterZee(schip* vaarSchip)
{
	_vaarSchip = std::move(vaarSchip);
}

bool Zee::vaar(RNG* rng)
{
	if (_turns != 0) {
		if (rng->getRandomNumber(1, 10) < 3) {
			vechtMetPiraten(rng);
		}
		else {
			int random = rng->getRandomNumber(1, 20);
			gevolgWind(random, rng);
		}
		return _vaarSchip->getSchade() > 0;
	}

	return true;
}

void Zee::vechtMetPiraten(RNG* rng) {
	int random = rng->getRandomNumber(0, 12);
	_piraten = new schip();
	*_piraten = _schepen[random];

	vaar(rng);
}
//DP toepassen wanneer we klaar zijn !
void Zee::gevolgWind(int actie, RNG* rng) {

	if (actie >= 3 && actie <= 4) {
		if (_vaarSchip->hasBijzonderheid("licht")) {
			_turns -= 1;
		}
	}
	else if (actie >= 5 && actie <= 7) {
		if (!_vaarSchip->hasBijzonderheid("log")) {
			_turns -= 1;
		}
	}
	else if (actie >= 8 && actie <= 17) {
		_turns -= 1;
	}
	else if (actie >= 18 && actie <= 19) {
		_turns -= 2;
	}
	else if(actie == 20) {
		int stormGevolg = rng->getRandomNumber(1, 10);
		if (stormGevolg >= 1 && stormGevolg <= 4) {
			_turns += 1;
		}
		else if (stormGevolg >= 9 && stormGevolg <= 10) {
			_turns -= 1;
		}
		int schade = _vaarSchip->getSchade();
		_vaarSchip->setSchade(schade - (schade * (rng->getRandomNumber(1, 100) / 100)));

	}
	if (_vaarSchip->getSchade() > 0) {
		vaar(rng);
	}
	
}