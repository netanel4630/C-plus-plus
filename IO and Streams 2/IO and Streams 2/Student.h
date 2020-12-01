#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>
using std::string;

class Student {
private:
	string name;
	string result;
	int score { 0 };

public:
	Student(string name , string result);
	string getName();
	string getResult();
	int getScore();
	void setScore(int score);
};

#endif
