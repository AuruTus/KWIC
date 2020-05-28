#include "readerFactory.h"

Reader* ReaderFactory::getInputReader() {
	return new LineReader(new InputReader());
}

Reader* ReaderFactory::getFileReader(string fileName) {
	return new LineReader(new FileReader(fileName));
}