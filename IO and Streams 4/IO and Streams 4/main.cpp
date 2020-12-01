#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using std::ifstream;
using std::ofstream;
using std::cerr;
using std::string;
using std::endl;
using std::getline;


void main() {

	ifstream in_file{ "romeoandjuliet.txt" };
	ofstream out_file{ "output.txt" };
	string line{};
	int lineNum = 1;


	if (!in_file || !out_file) {
		cerr << "Error opening file" << endl;
		return;
	}

	while (getline(in_file, line)) {
		if (!line.empty()) {
			out_file << std::setw(7)<<std::left<<lineNum << line << endl;
			lineNum++;
		}
		else {
			out_file << line << endl;
		}
	}
	in_file.close();

}