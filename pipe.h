#pragma once
#include "filter.h"
using std::pair;

class Pipe {
private:
	vector<Rotation> results;
	vector<pair<string, size_t>> records;
public:
	void leadTo(Filter* filter, string order);
	void printLines();
	void clear();
};
