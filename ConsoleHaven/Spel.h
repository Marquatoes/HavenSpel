#include <stdlib.h>
#include <iostream>
#include "RNG.h";
#include "Kanon.h";
#include "Haven.h";
#include "FileReader.h"
#include "Zee.h"
#pragma once

class Spel {
private: 
	void speelBeurt();
	schip* _alleSchepen;
	Haven* _havens;
	schip* _huidigSchip;
	Haven* _huidigeHaven;
	Zee* _zee;
	Speler* _speler;

	void kiesHaven();
public:
	Spel();
	~Spel();
	Spel(const Spel& copySpel) = delete;
	Spel& operator=(const Spel& copySpel) = delete;
	Spel(Spel&& moveSpel) = delete;
	Spel& operator=(Spel&& moveSpel) = delete;
	void Start();
	void Stop() const;

};