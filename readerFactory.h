#pragma once
#include "lineReader.h"
#include "fileReader.h"
#include "inputReader.h"

class ReaderFactory {
public:
	/**
	* DON'T FORGET TO DELETE READER POINTER!!!
	**/
	static Reader* getInputReader();
	static Reader* getFileReader(string fileName);

private:
	ReaderFactory() = delete;
};