#pragma once
#include <fstream>
#include "reader.h"
using std::ifstream;

/**
* component of LineReader
**/
class FileReader : public Reader {
private:
	ifstream fileStream;
public:
	FileReader() = default;
	FileReader(const string fileName);
	~FileReader();
	vector<string> readLines() override;
};