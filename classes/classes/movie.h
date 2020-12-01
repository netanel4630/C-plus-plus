#pragma once
#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>
#include <stdio.h>
using std::string;
//using namespace std; // for all std

#define G "G"
#define PG "PG"
#define PG_13 "PG-13"
#define R "R"

class Movie {

private:
	string name;
	string rating;
	int watched;
public:
	Movie(string name, string rating, int watched);

	string get_name()const;
	string get_rating()const;
	int get_watched()const;
	void increament_watched(int num_to_increament);
	void movie_display()const;
};


#endif