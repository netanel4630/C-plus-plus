#include "movie.h"
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

Movie::Movie(string name, string rating, int watched):name(name), rating(rating),watched(watched){}

string Movie::get_name()const { return name; }

string Movie::get_rating()const { return rating; }

int Movie::get_watched()const { return watched; }

void Movie::increament_watched(int num_to_increament) { watched += num_to_increament; }

void Movie::movie_display()const {
	cout << "movie name: " << name << "\trating movie: " << rating << "\t\tnumber of watched:" << watched << endl;
}
