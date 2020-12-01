#include "PART_TWO.h"

static void display_words_part2(const map<string, set<int>> &words);
static void cnt_lines(map<string, set<int>> &words, string line, int line_num);

// Display the word and occurences from the 
// std::map<std::string, std::set<int>>
static void display_words_part2(const map<string, set<int>> &words)
{
	std::cout << std::setw(12) << std::left << "\nWord"
		<< "Occurrences" << std::endl;
	std::cout << "=====================================================================" << std::endl;
	for (auto pair : words) {
		std::cout << std::setw(12) << std::left << pair.first
			<< std::left << "[ ";
		for (auto i : pair.second)
			std::cout << i << " ";
		std::cout << "]" << std::endl;
	}
}

// Get a map of words and a set of line numbers in which the word appears
static void cnt_lines(map<string, set<int>> &words, string line, int line_num) {
	string word;
	stringstream ss(line);

	while (ss >> word) {
			words[word].insert(line_num);
	}
}



//Call read_from_file func
void part2() {
	read_from_file(cnt_lines, display_words_part2);
}