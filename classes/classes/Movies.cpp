#include "movies.h"
#include <iostream>
#include <algorithm>

using std::find_if;
using std::cout;
using std::endl;

#define DUMMY 0
#define ADD_MOVIE 1
#define INCREAMENT_WATCHED 2

bool Movies::Movie_handler(string movie_name, int function_name, int num_to_increase) {
    int i;

    for (i = 0; i < movies.size(); i++) {
        if (movies.at(i).get_name() == movie_name) {
            if (ADD_MOVIE == function_name) {
                return false;
            }
            if (INCREAMENT_WATCHED == function_name) {
                movies.at(i).increament_watched(num_to_increase);
                return true;
            }
        }
    }

    return ADD_MOVIE == function_name;
}

void Movies::add_movie(Movie movie) {
    if (Movies::Movie_handler(movie.get_name(), ADD_MOVIE, DUMMY)) {
        movies.push_back(movie);
    }

    else {
        cout << "Error! These movie already exist" << endl;
    }
}

void Movies::increment_watched(string name, int increament) {
    if (!Movies::Movie_handler(name, INCREAMENT_WATCHED, increament)) {
        cout << "Error! These movie not exist" << endl;
    }
}

void Movies::display() {
    for (auto& i : movies) {
        i.movie_display();
    }
}