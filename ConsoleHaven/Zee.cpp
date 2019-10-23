#include "Zee.h"
Zee::Zee(int turns, schip* schepen) : _turns{ turns }, _vaarSchip{ nullptr }, _piraten{ nullptr }, _schepen {schepen}
{
	_schepen = new schip[13];
	for (int i = 0; i < 13; i++) {
		_schepen[i] = schepen[i];
	}
	_piraten = new schip();
}

Zee::~Zee()
{
	if (_piraten != nullptr) {
		delete _piraten;
	}
	if (_schepen != nullptr) {
		delete[] _schepen;
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

void Zee::enterZee(schip* vaarSchip, int afstand)
{
	_vaarSchip = vaarSchip;
	_turns = afstand;
}

bool Zee::vaar()
{
	if (_turns > 0 && _vaarSchip->getSchade() > 0) {
		if (RNG::Instance()->getRandomNumber(1, 10) < 3) {
			std::cout << "--------------------PIRATEN--------------------" << std::endl;
			int random = RNG::Instance()->getRandomNumber(0, 12);
			*_piraten = _schepen[random];
			_piraten->seedKanonnen(RNG::Instance()->getRandomNumber(1, _piraten->getMaxAantalKanonnen()));
			vechtMetPiraten();
		}
		else {
			int random = RNG::Instance()->getRandomNumber(1, 20);
			gevolgWind(random);
		}
	}

	return _vaarSchip->getSchade() > 0;
}

void Zee::vechtMetPiraten() {
	
	std::cout << "PiratenSchip: " << std::endl;
	_piraten->printInfo();
	std::cout << std::endl;
	std::cout << "Jouw schip: " << std::endl;
	_vaarSchip->printInfo();
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Kies wat je wilt doen: " << std::endl;
	std::cout << "1: Vecht" << std::endl;
	std::cout << "2: Vlucht" << std::endl;
	std::cout << "3: Geef je over" << std::endl;
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
		vecht();
		break;
	case 2: 
		vlucht();
		break;
	case 3: 
		geefOver();
		break;
	}
	vaar();
}

void Zee::vecht() {
	std::cout << "-----------------------------------------------------------" << std::endl;
	int vSchade = _vaarSchip->getDamage();
	std::cout << "Je schiet en raakt de piraten voor: " << vSchade << " schade." << std::endl;
	_piraten->setSchade(_piraten->getSchade() - vSchade);

	if (_piraten->getSchade() > 0) {
		int pSchade = _piraten->getDamage();
		std::cout << "De piraten schieten terug en ze raken je voor: " << pSchade << " schade." << std::endl;
		_vaarSchip->setSchade(_vaarSchip->getSchade() - pSchade);
		if (_vaarSchip->getSchade() > 0) {
			std::cout << "-----------------------------------------------------------" << std::endl;
			vechtMetPiraten();
		}
		else {
			std::cout << "Je bent gezonken." << std::endl;
		}
	}
	else {
		std::cout << "Het piratenschip is gezonken, Je hebt gewonnen." << std::endl;
	}
}

void Zee::vlucht() {
	std::cout << "-----------------------------------------------------------" << std::endl;
	int vluchtkans = getVluchtKans();
	std::cout << "Je probeert te vluchten met een vlucht kans van " << vluchtkans << "%" << std::endl;
	int pSchade = _piraten->getDamage();
	std::cout << "De piraten schieten nog een keer op je en ze raken je voor: " << pSchade << " schade." << std::endl;
	_vaarSchip->setSchade(_vaarSchip->getSchade() - pSchade);
	if (_vaarSchip->getSchade() <= 0) {
		std::cout << "Je bent gezonken." << std::endl;
		return;
	}

	int random = RNG::Instance()->getRandomNumber(1, 100);
	if (random <= vluchtkans) {
		std::cout << "Het is gelukt! je laat de piraten achter je en vaart verder." << std::endl;
	}
	else {
		std::cout << "Het vluchten is mislukt!" << std::endl;
		vechtMetPiraten();
	}
}

void Zee::geefOver() {
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "Je geeft je over en de piraten jatten zo veel als in hun schip past, de rest gooien ze over boord."<< std::endl;
	_vaarSchip->dumpHandelsgoederen();
}

//DP toepassen wanneer we klaar zijn !
void Zee::gevolgWind(int actie) {
	std::cout << "--------------------VAREN--------------------" << std::endl;
	std::cout << "De afstand to de haven is " << _turns << std::endl;
	int turnVerschil = 0;
	if (actie >= 3 && actie <= 4) {
		std::cout << "Er staat een briesje" << std::endl;
		if (_vaarSchip->hasBijzonderheid("licht")) {
			turnVerschil -= 1;
		}
	}
	else if (actie >= 5 && actie <= 7) {
		std::cout << "Er staat een zwakke wind" << std::endl;
		if (!_vaarSchip->hasBijzonderheid("log")) {
			turnVerschil -= 1;
		}
	}
	else if (actie >= 8 && actie <= 17) {
		std::cout << "Er staat een normale wind" << std::endl;
		turnVerschil -= 1;
	}
	else if (actie >= 18 && actie <= 19) {
		std::cout << "Er staat een sterke wind" << std::endl;
		turnVerschil -= 2;
	}
	else {
		std::cout << "Het stormt!" << std::endl;
		int stormGevolg = RNG::Instance()->getRandomNumber(1, 10);
		if (stormGevolg >= 1 && stormGevolg <= 4) {
			turnVerschil += 1;
		}
		else if (stormGevolg >= 9 && stormGevolg <= 10) {
			turnVerschil -= 1;
		}

		
		double schade = _vaarSchip->getSchade();
		int random = RNG::Instance()->getRandomNumber(1, 100);
		int windSchade = schade * random / 100;
		std::cout << "Door de storm pakt je schip " << windSchade << " schade." << std::endl;
		_vaarSchip->setSchade(schade - windSchade);
	}
	
	_turns = _turns + turnVerschil;
	if (_vaarSchip->getSchade() > 0) {
		std::cout << "Als gevolg van de wind is de afstand tot de haven met " << turnVerschil << " veranderd" << std::endl;
		vaar();
	}
	
}

int Zee::getVluchtKans()
{
	if (_vaarSchip->hasBijzonderheid("licht")) {
		if (_piraten->hasBijzonderheid("licht")) {
			return 50;
		}
		else if (_piraten->hasBijzonderheid("normaal")) {
			return 60;
		}
		else {
			return 75;
		}

	}
	else if (_vaarSchip->hasBijzonderheid("normaal")) {
		if (_piraten->hasBijzonderheid("licht")) {
			return 30;
		}
		else if (_piraten->hasBijzonderheid("normaal")) {
			return 40;
		}
		else {
			return 55;
		}
	}
	else {
		if (_piraten->hasBijzonderheid("licht")) {
			return 5;
		}
		else if (_piraten->hasBijzonderheid("normaal")) {
			return 15;
		}
		else {
			return 30;
		}
	}
}
