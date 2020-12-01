#include "Students.h"
#include <conio.h>

int main() {
	Students students{ "responses.txt" };

	students.printStudents();

	_getch();
	return 0;
}