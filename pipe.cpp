#include "pipe.h"

void Pipe::leadTo(Filter* filter, string order) {
	vector<Rotation> rotations = filter->execute(order);
	records.push_back({order, results.size()});
	results.insert(results.end(), rotations.begin(), rotations.end());
}

void Pipe::printLines() {
	vector<string> first_halves;
	vector<string> second_halves;
	string::size_type max_first_half_width = 0;

	for (vector<Rotation>::size_type i = 0; i < results.size(); ++i) {
		Rotation rot = results[i];
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

	string breakLine(max_first_half_width, '-');

	for (vector<string>::size_type i = 0, j = 0; i < first_halves.size(); ++i) {
		if ( j < records.size() && i == records[j].second) {
			cout << breakLine << endl;
			cout << "@:> " << records[j++].first << " : "<< endl;
			cout << breakLine << endl;
		}
		cout << setw(max_first_half_width);
		cout << first_halves[i];
		cout << "\t";
		cout << second_halves[i];
		cout << endl;
	}

	cout << breakLine << endl;
	cout << breakLine << endl;
	cout << "@:> flow ends "<< endl;
	cout << breakLine << endl;
	cout << breakLine << endl;

}

void Pipe::clear() {
	results.clear();
}