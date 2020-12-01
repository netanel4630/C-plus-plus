#pragma once
#ifndef _MOVIES_H_
#define _MOVIES_H_

#include "movie.h"
#include <vector>

using std::vector;
using std::string;

class Movies {
private:
	vector<Movie> movies;

public:
	bool Movie_handler(string movie_name, int function_name, int num_to_increase);
	void add_movie(Movie movie);
	void increment_watched(string name, int increment);
	void display();

};

#endif