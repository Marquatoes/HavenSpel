#include "FileReader.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h> 
#include <string.h>


void FileReader::ReadSchepenFile(schip* schepen) const {

	std::ifstream file("DataFiles/schepen.csv");

	char* next_token1 = NULL;
	char line[1000];
	int currentShip = 0;
	char*** ships = nullptr;
	try {
		ships = new char** [14];
		//set all the entries in the array to nullptr and then allocate memory to them
		for (int i = 0; i < 14; i++) {
			ships[i] = nullptr;
		}
		for (int i = 0; i < 14; i++) {
			ships[i] = new char* [6];
			for (int j = 0; j < 6; j++) {
				ships[i][j] = nullptr;
			}
			for (int j = 0; j < 6; j++) {
				ships[i][j] = new char[25];
			}
		}
	}
	catch (...) {
		//delete the entries of ships that have memory allocated to them if something went wrong
		if (ships != nullptr) {
			for (int i = 0; i < 14; i++) {
				if (ships[i] != nullptr) {
					for (int j = 0; j < 6; j++) {
						if (ships[i][j] != nullptr) {
							delete[] ships[i][j];
						}
					}
					delete[] ships[i];
				}
			}
			delete[] ships;
		}
		throw;
	}

	while (currentShip < 14)
	{
		file.getline(line, sizeof line);
		char* token1 = strtok_s(line, ";", &next_token1);

		for (int i = 0; i < 6; i++) {
			if (token1 != NULL) {
				strcpy_s(ships[currentShip][i], 25, token1);
				token1 = strtok_s(NULL, ";", &next_token1);
			}
			else if (i == 5) {
				strcpy_s(ships[currentShip][i], 25, "geen");
			}
		}
		currentShip++;
		delete[] token1;
	}
	file.close();
	for (int i = 1; i < 14; i++) {
		Kanon* kanon = new Kanon[1];
		kanon[0] = Kanon();

		schepen[i - 1] = schip(ships[i][0], atoi(ships[i][1]), atoi(ships[i][2]), atoi(ships[i][3]), atoi(ships[i][4]), ships[i][5], kanon, 0);

	}
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 6; j++) {
			if (i == 0 || (j > 0 && j < 5)) {
				delete[] ships[i][j];
			}
		}
		if (ships[i] != nullptr) {
			delete[] ships[i];
		}
	}
	if (ships != nullptr) {
		delete[] ships;
	}


}

void FileReader::MaakHavens(Haven* havens) const {
	char*** prijzen = nullptr;
	char*** hoeveelheden = nullptr;
	int** afstanden = nullptr;
	try {
		prijzen = new char** [25];
		hoeveelheden = new char** [25];
		afstanden = new int* [24];
		for (int i = 0; i < 25; i++) {
			prijzen[i] = nullptr;
			hoeveelheden[i] = nullptr;
			if (i < 24) {
				afstanden[i] = nullptr;
			}

		}
		for (int i = 0; i < 25; i++) {
			prijzen[i] = new char* [16];
			hoeveelheden[i] = new char* [16];
			if (i < 24) {
				afstanden[i] = new int[24];
			}
			for (int j = 0; j < 16; j++) {
				prijzen[i][j] = nullptr;
				hoeveelheden[i][j] = nullptr;
			}
			for (int j = 0; j < 16; j++) {
				prijzen[i][j] = new char[25];
				hoeveelheden[i][j] = new char[25];
			}
		}
	}
	catch (...) {
		deleteData(prijzen, hoeveelheden, afstanden);
		throw;
	}

	readGoederen(prijzen, "DataFiles/goederen prijzen.csv");
	readGoederen(hoeveelheden, "DataFiles/goederen hoeveelheid.csv");
	readAfstanden(afstanden);
	for (int i = 1; i < 25; i++) {
		Handelsgoed goederen[15];
		int k;
		int minPrijs = NULL;
		int maxPrijs = NULL;
		int minHoeveelheid = NULL;
		int maxHoeveelheid = NULL;
		for (int j = 1; j < 16; j++) {
			char* maxP = NULL;
			char* minP = strtok_s(prijzen[i][j], "-", &maxP);
			minPrijs = atoi(minP);
			maxPrijs = atoi(maxP);

			char* maxH = NULL;
			char* minH = strtok_s(hoeveelheden[i][j], "-", &maxH);
			minHoeveelheid = atoi(minH);
			maxHoeveelheid = atoi(maxH);
			goederen[j - 1] = Handelsgoed(0, 0, maxPrijs, minPrijs, maxHoeveelheid, minHoeveelheid, prijzen[0][j - 1]);
		}
		try {
			havens[i - 1] = Haven(goederen, 15, prijzen[i][0], afstanden[i - 1]);
		}
		catch (...) {
			deleteData(prijzen, hoeveelheden, afstanden);
			throw;
		}
		
	}
	deleteData(prijzen, hoeveelheden, afstanden);
}

void FileReader::deleteData(char*** prijzen, char*** hoeveelheden, int** afstanden) const {
	for (int i = 0; i < 25; i++) {
		if (prijzen[i] != nullptr || hoeveelheden[i] != nullptr) {
			for (int j = 0; j < 16; j++) {
				if (prijzen[i] != nullptr && prijzen[i][j] != nullptr) {
					delete[] prijzen[i][j];
				}
				if (hoeveelheden[i] != nullptr && hoeveelheden[i][j] != nullptr) {
					delete[] hoeveelheden[i][j];
				}
			}
			if (prijzen[i] != nullptr) {
				delete[] prijzen[i];
			}
			if (hoeveelheden[i] != nullptr) {
				delete[] hoeveelheden[i];
			}
		}
		if (i < 24 && afstanden[i] != nullptr) {
			delete[] afstanden[i];
		}
	}
	if (prijzen != nullptr) {
		delete[] prijzen;
	}
	if (hoeveelheden != nullptr) {
		delete[] hoeveelheden;
	}
	if (afstanden != nullptr) {
		delete[] afstanden;
	}
}

void FileReader::readGoederen(char*** goederen, const char* path) const {
	std::ifstream file(path);
	char* next_token1 = NULL;
	char line[1000];
	int currentShip = 0;

	while (currentShip < 25)
	{
		file.getline(line, sizeof line);
		if (line[0] != '#') {

			char* token;
			char* rest = line;
			int counter = 0;
			while ((token = strtok_s(rest, ";", &rest))) {

				strcpy_s(goederen[currentShip][counter], 25, token);
				counter++;
			}
			currentShip++;
		}

	}
	file.close();
}

void FileReader::readAfstanden(int** afstanden) const
{

	std::ifstream file("DataFiles/afstanden tussen steden.csv");
	char* next_token1 = NULL;
	char line[1000];
	int currentShip = 0;

	while (currentShip < 25)
	{
		file.getline(line, sizeof line);
		if (line[0] != '#') {

			char* token;
			char* rest = line;
			int counter = 0;
			while ((token = strtok_s(rest, ";", &rest))) {
				if (currentShip > 0 && counter > 0) {
					int afstand = atoi(token);
					afstanden[currentShip - 1][counter - 1] = afstand;

				}

				counter++;
			}
			currentShip++;
		}

	}
	file.close();
}
