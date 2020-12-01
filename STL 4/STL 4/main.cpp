// Section 20
// Challenge 4
// Identifying palindrome strings using a stack and queue
#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>

using std::stack;
using std::queue;
bool is_palindrome(const std::string& s)
{
	stack<char>l;
	queue<char>r;

	for (auto &i : s) {
		if (std::isalpha(i)) {
			l.push(tolower(i));
			r.push(tolower(i));
		}
	}

	while (!l.empty()) {
		if (!(l.top() == r.front())) {
			return false;
		}
		l.pop();
		r.pop();
	}
	return true;
}

int main()
{
	std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
		"avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
		"A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

	std::cout << std::boolalpha;
	std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
	for (const auto& s : test_strings) {
		std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
	}
	std::cout << std::endl;

	_getch();
	return 0;
}