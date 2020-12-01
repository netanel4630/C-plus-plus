#include "PART_ONE.h"

static void display_words_parts1(const map<string, int> &words);
static void cnt_words(map<string, int> &words, string line, int line_num);

// Display the word and count from the 
// std::map<std::string, int>
static void display_words_parts1(const map<string, int> &words) {
	cout << std::setw(12) << std::left << "\nWord"
		<< std::setw(7) << std::right << "Count" << std::endl;
	cout << "===================" << std::endl;
	for (auto pair : words)
		std::cout << std::setw(12) << std::left << pair.first
		<< std::setw(7) << std::right << pair.second << std::endl;
}

// Get map of words and the number of times they occur in the file
static void cnt_words(map<string, int> &words, string line, int line_num) {
	string word;
	stringstream ss(line);

	while (ss >> word) {
		if (words.find(word) == words.end()) {
			words.insert(make_pair(word, INITIAL));
		}
		else {
			words[word] += INCREASE;
		}
	}
}

//Call read_from_file func
void part1() {
	read_from_file(cnt_words, display_words_parts1);
}