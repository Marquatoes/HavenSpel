#pragma once
#include "schip.h"
#include "Haven.h"

class FileReader {
private:
	void readGoederen(char* goederen[25][16], const char* path);
public:
	void ReadSchepenFile(schip* schepen[]);
	void MaakHavens(Haven* havens[], schip* schepen[]);
};