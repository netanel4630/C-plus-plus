#include "PARTS_HANDLER.h"

static string clean_string(const string &s);

// This function removes periods, commas, semicolons and colon in 
// a string and returns the clean version
static string clean_string(const string &s) {
	string result;
	for (char c : s) {
		if (c == '.' || c == ',' || c == ';' || c == ':')
			continue;
		else
			result += c;
	}
	return result;
}



//read lines from file, manipulate the words and print the result
template <typename T1, typename T2>
void read_from_file(void (cnt)(map<T1, T2> &, string, int), void (display)(const map<T1, T2>&)){
	map<T1, T2> words;
	string line{}, temp_line{};
	string word;
	ifstream in_file{ "words.txt" };
	stringstream ss;
	int line_num{};

	if (in_file) {
		while (getline(in_file, temp_line)) {
			stringstream ss(temp_line);
			while (ss >> word) {
				word = clean_string(word);
				line += " " + word;
			}
			line_num++;
			cnt(words, line, line_num);
			line = "";
		}
		in_file.close();
		display(words);
	}
	else {
		cerr << "Error opening input file" << std::endl;
	}
}

template void read_from_file(void (cnt)(map<string, int> &, string, int), void (display)(const map<string, int>&));
template void read_from_file(void (cnt)(map<string, set<int>> &, string, int), void (display)(const map<string, set<int>>&));