#include "lineReader.h"

LineReader::LineReader(Reader* reader) : reader(reader) {

}

LineReader::~LineReader() {
	if (reader != nullptr) {
		delete reader;
	}
}

vector<string> LineReader::readLines() {
	return reader->readLines();
}