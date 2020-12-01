#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;


void main() {
	vector <vector <int>> vector_2d;

	vector <int> vector1;
	vector <int> vector2;

	vector1.push_back(10);
	vector1.push_back(20);

	cout << vector1.at(0) << "  " << vector1.at(1) << "  " << vector1.size() << endl;


	vector2.push_back(100);
	vector2.push_back(200);
	
	cout << vector2.at(0) << "  " << vector2.at(1) << "  " << vector2.size() << endl;
	

	vector_2d.push_back(vector1);
	vector_2d.push_back(vector2);

	cout << vector_2d.at(0).at(0) << "  " << vector_2d.at(0).at(1) << "  " << vector_2d.size() << endl;
	cout << vector_2d.at(1).at(0) << "  " << vector_2d.at(1).at(1) << "  " << vector_2d.size() << endl;

	vector1.at(0) = 1000;

	cout << vector_2d.at(0).at(0) << "  " << vector_2d.at(0).at(1) << "  " << vector_2d.size() << endl;
	cout << vector1.at(0) << "  " << vector1.at(1) << "  " << vector1.size() << endl;
	_getch();
}