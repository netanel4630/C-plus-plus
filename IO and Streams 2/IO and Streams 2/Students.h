#ifndef _STUDENTS_H_
#define _STUDENTS_H_

#include "Student.h"
#include <vector>
#include <iostream>
#include <fstream>

using std::vector;
using std::ifstream; 

class Students {
private:
	vector <Student> students;
	string file_name;
	string results;

public:
	Students(string file_name);
	
	void readStudentsAndResults();
	void writeScore();
	void printStudents();
	int calculateScore(string result);
};

#endif
