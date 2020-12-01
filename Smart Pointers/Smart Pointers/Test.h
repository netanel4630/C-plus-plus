#pragma once
#ifndef _TEST_H_

#include <iostream>

using std::cout;
using std::cin;

class Test {
private:
	int data;
public:
	Test();
	Test(int data);
	int get_data() const;
	~Test();
};

#endif // !_TEST_H
