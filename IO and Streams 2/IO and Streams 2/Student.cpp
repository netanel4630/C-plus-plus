#include "Student.h"

Student::Student(string name , string result) : name{ name }, result{ result }{}

string Student::getName() {
	return name;
}

string Student::getResult() {
	return result;
}

int Student::getScore() {
	return score;
}

void Student::setScore(int score) {
	(*this).score = score;
}