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
	int* _afstanden;
	char* _naam;
	
public:
	Haven();
	Haven(Handelsgoed* handelsGoederen, size_t aantalGoederen, char* naam, int* afstanden);
	
	~Haven();
	Haven(const Haven& copyHaven);
	Haven& operator=(const Haven& copyHaven);
	Haven(Haven&& moveHaven) noexcept;
	Haven& operator=(Haven&& moveHaven) noexcept;
	void seedHaven();
	void seedKanonnen();
	void seedGoederen();
	void enterHaven(schip* vaarschip);
	void repareer(schip* repareerSchip, Speler* speler, int aantalSchadePunten);
	void KoopKanonnen(schip* havenschip, Speler* speler);
	void VerkoopKanon(schip* havenschip, Speler* speler);
	void KoopGoederen();
	void VerkoopGoederen();
	void KoopSchip();
	void VerkoopSchip();
	void Wegvaren();
	void RepareerSchip();
};
