#include "fileFilter.h"

vector<Rotation> FileFilter::execute(string fileName) {
	Reader* reader = ReaderFactory::getFileReader(fileName);
	KWIC kwic;

	kwic.rortateLines(reader->readLines());
	delete reader;
	return kwic.sortLines();
}