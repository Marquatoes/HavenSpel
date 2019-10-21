#include "FileReader.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


void FileReader::ReadSchepenFile(schip* schepen) {

	std::ifstream file("DataFiles/schepen.csv");
	
	char* next_token1 = NULL;
	char line [1000];
	int currentShip = 0;
	
	char *ships[14][6];
	while (currentShip < 14)
	{
		file.getline(line, sizeof line);
		char* token1 = strtok_s(line, ";", &next_token1);
		
		for (int i = 0; i < 6; i++) {
			ships[currentShip][i] = new char[25];
			if (token1 != NULL) {
				strcpy_s(ships[currentShip][i], 25, token1);
				token1 = strtok_s(NULL, ";", &next_token1);
			}

		}
		currentShip++;
	}
	file.close();
	for (int i = 1; i < 14; i++) {
		Kanon* kanon = new Kanon[1];
		kanon[0] = Kanon();
		schepen[i - 1] = schip(ships[i][0], atoi(ships[i][1]), atoi(ships[i][2]), atoi(ships[i][3]), atoi(ships[i][4]), ships[i][5], kanon, 0);
	}
}

void FileReader::MaakHavens(Haven* havens) {
	char** prijzen = new char*[25];
	char** hoeveelheden = new char*[25];
	for (int i = 0; i < 25; i++) {
		prijzen[i] = new char[16];
		hoeveelheden[i] = new char[25];
	}
	readGoederen(prijzen, "DataFiles/goederen prijzen.csv");
	readGoederen(hoeveelheden, "DataFiles/goederen hoeveelheid.csv");

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
			goederen[j - 1] = Handelsgoed(0, 0, maxPrijs, minPrijs, maxHoeveelheid, minHoeveelheid);

		}
		havens[i - 1] =  Haven(goederen, 15);
	}
	delete[] prijzen;
	delete[] hoeveelheden;
}

void FileReader::readGoederen(char **goederen, const char* path) {
	std::ifstream file(path);

	char* next_token1 = NULL;
	char line[1000];
	int currentShip = 0;

	while (currentShip < 25)
	{
		file.getline(line, sizeof line);
		if (line[0] != '#') {
			char* token1 = strtok_s(line, ";", &next_token1);
			int counter = 0;

			while (token1 != NULL) {
				goederen[currentShip][counter] = new char[25];
				if (token1 != nullptr) {
					strcpy_s(goederen[currentShip][counter], 25, token1);
				}

				token1 = strtok_s(NULL, ";", &next_token1);
				counter++;
			}
			currentShip++;
		}
		
	}
	file.close();
}