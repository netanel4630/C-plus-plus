#include "ptr_functions.h"

unique_ptr<vector<shared_ptr<Test>>> make() {
	 return make_unique<vector<shared_ptr<Test>>>();
}


void fill(vector<shared_ptr<Test>> &vec, int num) {
	int i;
	int data;

	for (i = 1 ; i <= num; i++) {
		cout << "Enter data point [" << i << "]: ";
		cin >> data;
		vec.push_back(make_shared<Test>(data));
	}
}


void display(const vector<shared_ptr<Test>>&vec) {
	cout << "==================" << endl;
	for (const auto &i:vec) {
		cout << i->get_data()<< endl;
	}
	cout << "==================" << endl;
}