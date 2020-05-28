#pragma once
#include "filter.h"

class FileFilter : public Filter {
public:
	vector<Rotation> execute(string fileName) override;
};