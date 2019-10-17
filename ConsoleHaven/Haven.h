#include "schip.h";
#include "Handelsgoed.h";
#include "Kanon.h";
#include "RNG.h";
#include "Speler.h";
#pragma once
class Haven
{
private:
	schip* _dockedSchip;
	schip* _koopSchepen;
	Handelsgoed* _handelsGoederen;
	Kanon* _kanonnen;
	size_t _aantalSchepen;
	size_t _aantalGoederen;
	size_t _aantalKanonnen;
public:
	Haven(schip *dockedSchip, schip* koopSchepen, Handelsgoed* handelsGoederen, size_t aantalSchepen , size_t aantalGoederen, size_t aantalKanonnen);
	~Haven();
	Haven(const Haven& copyHaven);
	Haven& operator=(const Haven& copyHaven);
	Haven(Haven&& moveHaven) noexcept;
	Haven& operator=(Haven&& moveHaven) noexcept;
	void seedHaven();
	void seedKanonnen();
	void seedGoederen();
	void enterHaven(schip* enterSchip);
	void repareer(schip* repareerSchip, Speler* speler, int aantalSchadePunten);
	void koopKanon(schip* schip, Speler* speler, char* type);
};
