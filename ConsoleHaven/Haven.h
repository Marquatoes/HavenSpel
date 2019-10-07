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
public:
	Haven(schip *dockedSchip, schip* koopSchepen, Handelsgoed* handelsGoederen);
	~Haven();
	Haven(const Haven& copyHaven);
	Haven& operator=(const Haven& copyHaven);
	Haven(Haven&& moveHaven);
	Haven& operator=(Haven&& moveHaven) noexcept;
};
