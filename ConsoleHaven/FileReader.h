#pragma once
#include "schip.h"
#include "Haven.h"

class FileReader {
private:
	void readGoederen(char*** goederen, const char* path) const;
	void readAfstanden(int** afstanden) const;
	void deleteSchepen(char*** ships) const;
	void deleteData(char*** prijzen, char*** hoeveelheden, int** afstanden) const;
public:
	void ReadSchepenFile(schip* schepen) const;
	void MaakHavens(Haven* havens) const;
};