#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::cerr;
using std::endl;

void check(string userWord, int* found, int* search) {
	*found = 0;
	*search = 0;
	ifstream in_file{ "romeoandjuliet.txt" };
	string txtWord;

	if (!in_file) {
		cerr << "Error opening file" << endl;
		return;
	}

	while (in_file >> txtWord) {
		if (txtWord.find(userWord) != string::npos) {
			*found = *found + 1;
		}
		*search = *search + 1;
	}

	in_file.close();
}


void main() {
	string userWord;
	int found = 0, search = 0;
	
	cout << "Enter the substring to search for: ";
	cin >> userWord;

	check(userWord, &found, &search);

	cout << search << " words were searched... " << endl;
	cout << "The substring '" << userWord << "' was found " << found << " times";

	_getch();
}