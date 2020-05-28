#pragma once
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "spliter.h"
#include "reader.h"
using std::cout;
using std::setw;
using std::endl;
using std::rotate;

struct Rotation {
	vector<string>::size_type first;
	vector<string> words;
};

class KWIC {
public:
	static string toLowerCase(const string& data);
	static vector<string> lowcase(const vector<string>& data);
	static bool compare(const Rotation& x, const Rotation& y);

	vector<Rotation> rotateLine(const string& line);
	void rortateLines(vector<string> lines);
	vector<Rotation> sortLines();
	void printLines();

private:
	vector<Rotation> rotations;
	static Spliter spliter;
};