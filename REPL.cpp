#include "REPL.h"

const Spliter REPL::spliter = Spliter("\\s+\\|\\s+");
Pipe REPL::pipe = Pipe();

REPL::REPL() {
	inputFilter = new InputFilter();
	fileFilter = new FileFilter();
}

void REPL::distribute() {
	string curLine;
	getline(cin, curLine);
	vector<string> orders = spliter(curLine);
	for (auto order : orders) {
		switch (order[0]) {
		case '#':
			pipe.leadTo(inputFilter, order);
			break;
		default:
			pipe.leadTo(fileFilter, order);
		}
	}
}

void REPL::workLoop() {
	while (true) {
		cout << "@:< " << std::flush;
		distribute();
		pipe.printLines();
		pipe.clear();
		cin.clear();
	}
}