#ifndef _PART_HANDLER_H_
#define _PART_HANDLER_H_
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>

using std::string;
using std::map;
using std::set;
using std::cout;
using std::cerr;
using std::ifstream;
using std::make_pair;
using std::stringstream;

template <typename T1, typename T2>
void read_from_file(void (cnt)(map<T1, T2> &, string, int), void (display)(const map<T1, T2>&));
#endif