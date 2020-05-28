#pragma once
#include "reader.h"
/**
* THIS IS THE DECORATOR.
* applicable components list: 
*		InputReader: read lines from the input of terminal;
*		FileReader: read lines from the chosen existing file.
* NOTE: 
*		initialize LineReader with a Reader pointer to any components mentioned above, 
*		and use readLines() to read lines;
*		or get a Reader pointer to a LineReader by using ReaderFactory.
**/
class LineReader : public Reader {
private:
	Reader* reader;
public:
	LineReader(Reader* reader);
	~LineReader();
	vector<string> readLines() override;
};