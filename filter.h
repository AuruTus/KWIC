#pragma once
#include "KWIC.h"
#include "readerFactory.h"

class Filter {
public:
	virtual vector<Rotation> execute(string str) = 0;
};