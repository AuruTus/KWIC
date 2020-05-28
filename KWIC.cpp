#include "KWIC.h"

Spliter KWIC::spliter = Spliter(" ");

vector<Rotation> KWIC::rotateLine(const string& line) {
	vector<Rotation> rotations;
	vector<string> words = spliter(line);

	for (vector<string>::size_type i = 0; i < words.size(); ++i) {
		Rotation rot = { words.size() - i, words };
		rotations.push_back(rot);
		rotate(words.begin(), words.begin() + 1, words.end());
	}

	return rotations;
}


void KWIC::rortateLines(vector<string> lines) {
	for (vector<string>::size_type i = 0; i < lines.size(); ++i) {
		vector<Rotation> new_rotations = rotateLine(lines[i]);
		rotations.insert(rotations.end(), new_rotations.begin(), new_rotations.end());
	}
}

string KWIC::toLowerCase(const string& data) {
	string str = data;
	std::transform(data.begin(), data.end(), str.begin(), ::tolower);
	return str;
}

vector<string> KWIC::lowcase(const vector<string>& data) {
	vector<string> vect;
	for (vector<string>::const_iterator it = data.begin(); it != data.end(); ++it) {
		vect.push_back(toLowerCase(*it));
	}
	return vect;
}

bool KWIC::compare(const Rotation& x, const Rotation& y) {
	return lowcase(x.words) < lowcase(y.words);
}

vector<Rotation> KWIC::sortLines() {
	sort(rotations.begin(), rotations.end(), compare);
	return rotations;
}

void KWIC::printLines() {
	vector<string> first_halves;
	vector<string> second_halves;
	string::size_type max_first_half_width = 0;

	for (vector<Rotation>::size_type i = 0; i < rotations.size(); ++i) {
		Rotation rot = rotations[i];
		string first_half, second_half;

		for (vector<string>::size_type j = rot.first; j < rot.words.size(); ++j)
			first_half += rot.words[j] + " ";

		first_halves.push_back(first_half);

		if (first_half.size() > max_first_half_width)
			max_first_half_width = first_half.size();

		for (vector<string>::size_type j = 0; j < rot.first; ++j)
			second_half += rot.words[j] + " ";

		second_halves.push_back(second_half);
	}

	for (vector<string>::size_type i = 0; i < first_halves.size(); ++i) {
		cout << setw(max_first_half_width);
		cout << first_halves[i];
		cout << "\t";
		cout << second_halves[i];
		cout << endl;
	}
}