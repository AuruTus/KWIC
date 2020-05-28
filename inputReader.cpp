#include "inputReader.h"

vector<string> InputReader::readLines() {
	vector<string> lines;
	string line;
	while (getline(cin, line)) {
		lines.push_back(line);
	}
	return lines;
}