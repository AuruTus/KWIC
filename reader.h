#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::string;
using std::vector;

/**
* this is the ceil interface for user;
**/
class Reader {
public:
	virtual vector<string> readLines() = 0;
};