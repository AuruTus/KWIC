#pragma once
#include "filter.h"

class InputFilter : public Filter {
public:
	vector<Rotation> execute(string str) override;
};