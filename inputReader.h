#pragma once
#include "reader.h"
/**
* component of LineReader
**/
class InputReader : public Reader {
public:
	InputReader() = default;
	~InputReader() = default;
	vector<string> readLines() override;
};
