#include "spliter.h"

Spliter::Spliter(string regex) : regex(regex) {

}

Spliter& Spliter::getInstance() {
	static Spliter INSTANCE(" ");
	return INSTANCE;
}

Spliter& Spliter::setRegex(string regex) {
	this->regex = regex;
	return *this;
}

vector<string> Spliter::operator()(const string& str) const {
	std::regex re(this->regex);
	std::sregex_token_iterator
		first{ str.begin(), str.end(), re, -1 },
		last;
	return { first, last };
}