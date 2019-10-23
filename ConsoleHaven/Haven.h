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
	int _aantalGoederen;
	int _aantalKoopSchepen;
	size_t _aantalKanonnen;
	int* _afstanden;
	char* _naam;
	schip* _koopSchepen;
	
public:
	Haven();
	Haven(Handelsgoed* handelsGoederen, int aantalGoederen, char* naam, int* afstanden);
	
	~Haven();
	Haven(const Haven& copyHaven);
	Haven& operator=(const Haven& copyHaven);
	Haven(Haven&& moveHaven) noexcept;
	Haven& operator=(Haven&& moveHaven) noexcept;
	void seedHaven();
	void seedKanonnen();
	void seedGoederen();
	void enterHaven(schip* vaarschip);
	void KoopKanonnen(schip* havenschip, Speler* speler);
	void VerkoopKanon(schip* havenschip, Speler* speler);
	void KoopGoederen(schip* havenschip, Speler* speler);
	void VerkoopGoederen(schip* havenschip, Speler* speler);
	void KoopSchip(Speler* speler, schip*& huidigSchip);
	void seedSchepen(const schip* mogelijkeSchepen, const int aantalSchepen);
	int getAfstand(const int havenNummer) const;
	void RepareerSchip(Speler* speler, schip* huidigSchip) const;
	const char* getNaam() const;
};
