#pragma once
#include <vector>
#include <string>
#include <regex>
using std::vector;
using std::string;
using std::regex;
using std::sregex_token_iterator;

class Spliter {
private:
	string regex;
public:
	Spliter() = default;
	Spliter(string regex);
	static Spliter& getInstance();
	Spliter& setRegex(string regex);
	vector<string> operator()(const string& str) const;
};