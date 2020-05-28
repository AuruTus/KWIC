#include "inputFilter.h"

vector<Rotation> InputFilter::execute(string str) {
	Reader* reader = ReaderFactory::getInputReader();
	KWIC kwic;

	kwic.rortateLines(reader->readLines());
	delete reader;
	return kwic.sortLines();
}