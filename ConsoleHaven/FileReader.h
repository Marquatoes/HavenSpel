#pragma once
#include "schip.h"
#include "Haven.h"

class FileReader {
private:
	void readGoederen(char*** goederen, const char* path) const;
	void readAfstanden(int** afstanden) const;
public:
	void ReadSchepenFile(schip* schepen) const;
	void MaakHavens(Haven* havens) const;
};