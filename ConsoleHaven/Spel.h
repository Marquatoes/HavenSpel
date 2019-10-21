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
	schip* alleSchepen;
	Haven* havens;
	schip* huidigSchip;
	Haven* huidigeHaven;
public:
	void Start();
	void Stop();

};