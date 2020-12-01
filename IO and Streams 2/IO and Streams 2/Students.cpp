#include "Students.h"
#include <iomanip>

using std::setw;
using std::endl;
using std::left;
using std::right;
using std::cerr;
using std::endl;
using std::getline;
using std::cout;

Students::Students(string file_name) : file_name{ file_name } {
	readStudentsAndResults();
}

void Students::readStudentsAndResults() {
	ifstream in_file{ file_name };
	string nameTemp;
	string resultTemp;

	if (!in_file) {
		cerr << "Error opening file" << endl;
		return;
	}

	getline(in_file, results);
	
	while (!in_file.eof()) {
		getline(in_file, nameTemp);
		getline(in_file, resultTemp);
		students.push_back({ nameTemp, resultTemp });
	}

	in_file.close();

	writeScore();
}

void Students::writeScore() {
	
	for (auto& student:students) {
		student.setScore(calculateScore(student.getResult()));
	}
}

int Students::calculateScore(string result) {
	int cnt = 0;

	for (int i = 0 ; i < result.size() ; i++) {
		if (result[i] == results[i]) {
			cnt++;
		}
	}

	return cnt;
}

void Students::printStudents() {
	float avg = 0;
	cout << setw(15) << left << "Student" << setw(10) << "Score"<<endl;
	cout << "--------------------"<<endl;

	for (auto& student : students) {
		cout << setw(10) << left << student.getName() << setw(10) << right << student.getScore()<< endl;
		avg += student.getScore();
	}

	cout << "--------------------" << endl;
	if(students.size()){
		cout << setw(13) << left << "Average score" << setw(7) << right << (avg / students.size()) << endl;
	}

}