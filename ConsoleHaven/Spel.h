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
public:
	void Start();
	void Stop();

};