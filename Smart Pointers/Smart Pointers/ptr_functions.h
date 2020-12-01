#pragma once
#ifndef _PTR_FUNCTIONS_H_
#include "Test.h"
#include <memory>
#include <vector>

using std::unique_ptr;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::make_unique;
using std::endl;

unique_ptr<vector<shared_ptr<Test>>> make();
void fill(vector<shared_ptr<Test>> &vec, int num);
void display(const vector<shared_ptr<Test>>&vec);

#endif // !_PTR_FUNCTIONS_H_
