#include "schip.h";
#include "Handelsgoed.h";
#include "Kanon.h";
#include "RNG.h";
#include "Speler.h";
#pragma once
class Haven
{
private:
	Handelsgoed* _handelsGoederen;
	Kanon* _kanonnen;
	size_t _aantalGoederen;
	size_t _aantalKanonnen;
public:
	Haven();
	Haven(Handelsgoed* handelsGoederen, size_t aantalGoederen);
	~Haven();
	Haven(const Haven& copyHaven);
	Haven& operator=(const Haven& copyHaven);
	Haven(Haven&& moveHaven) noexcept;
	Haven& operator=(Haven&& moveHaven) noexcept;
	void seedHaven();
	void seedKanonnen();
	void seedGoederen();
	void repareer(schip* repareerSchip, Speler* speler, int aantalSchadePunten);
	void koopKanon(schip* schip, Speler* speler, char* type);
};
