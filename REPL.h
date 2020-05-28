#pragma once
#include <iostream>
#include <string>
#include "spliter.h"
#include "pipe.h"
#include "filter.h"
#include "inputFilter.h"
#include "fileFilter.h"
using std::cin;
using std::string;


class REPL {
private:
	const static Spliter spliter;
	static Pipe pipe;
	Filter* inputFilter, * fileFilter;
public:
	REPL();
	void distribute();
	void workLoop();
};