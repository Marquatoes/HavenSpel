#include "schip.h";
#include "Handelsgoed.h";
#include "Kannon.h";
#pragma once
class Haven
{
private:
	schip* _dockedSchip;
	schip* _koopSchepen;
	Handelsgoed* _handelsGoederen;
	Kannon* _kannonen;
	size_t _aantalSchepen;
	size_t _aantalGoederen;
	size_t _aantalKannonen;
public:
	Haven(schip *dockedSchip, schip* koopSchepen, Handelsgoed* handelsGoederen, size_t aantalSchepen , size_t aantalGoederen, size_t aantalKannonen);
	~Haven();
	Haven(const Haven& copyHaven);
	Haven& operator=(const Haven& copyHaven);
	Haven(Haven&& moveHaven);
	Haven& operator=(Haven&& moveHaven) noexcept;
};
