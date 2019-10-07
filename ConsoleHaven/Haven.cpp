#include "Haven.h"
#include <cstring>

Haven::Haven(schip* dockedSchip, schip* koopSchepen, Handelsgoed* handelsGoederen) :
	_dockedSchip{ dockedSchip }, _koopSchepen{ koopSchepen }, _handelsGoederen{ handelsGoederen } {
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

Haven::Haven(const Haven& copyHaven) : _dockedSchip { copyHaven._dockedSchip }
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

}
