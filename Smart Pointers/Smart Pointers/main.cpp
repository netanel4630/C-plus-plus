#include "ptr_functions.h"
#include <conio.h>

int main() {
	unique_ptr<std::vector<shared_ptr<Test>>> vec_ptr;
	vec_ptr = make();
	std::cout << "How many data points do you want to enter: ";
	int num;
	std::cin >> num;
	fill(*vec_ptr, num);
	display(*vec_ptr);

	//_getch();
	return 0;
}