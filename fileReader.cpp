#include "fileReader.h"

FileReader::FileReader(const string fileName) {
	if (fileStream.is_open() == false) {
		fileStream.close();
	}
	fileStream.open(fileName);
}
FileReader::~FileReader() {
	if (fileStream.is_open() == false) {
		fileStream.close();
	}
}

vector<string> FileReader::readLines() {
	vector<string> lines;
	if (fileStream.is_open() == false) { 
		return lines; 
	}
	string line;
	while (getline(fileStream, line)) {
		lines.push_back(line);
	}
	fileStream.close();
	return lines;
}
