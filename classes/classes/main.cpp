/******************************************************************
 * Section 13 Challenge
 * main.cpp
 * 
 * Test the Movies project
 * 
 * ***************************************************************/
#include <iostream>
#include "Movies.h"

// Function prototypes
void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &movies, std::string name, std::string rating, int watched);

/******************************************************************
 * helper function 
 * increment_watched expects a reference to a Movies object 
 * and the name of the movie to increment the watched count
 *
 * If the watched count was incremented successfully it
*  displays a success message
*  otherwise the watched count could not be incremented
*  because the name of the movie was not found
 * ***************************************************************/


int main() {
    
    Movies my_movies;
    
    my_movies.display();
    
    my_movies.add_movie(Movie("Big", PG_13,2));                 // OK
    my_movies.add_movie(Movie("Star Wars", PG, 5));             // OK
    my_movies.add_movie(Movie("Cinderella", PG, 7));           // OK
     
    my_movies.display();   // Big, Star Wars, Cinderella
    
    my_movies.add_movie(Movie("Cinderella", PG, 7));             // Already exists
    my_movies.add_movie(Movie("Ice Age", PG, 12));              // OK
 
    my_movies.display();    // Big, Star Wars, Cinderella, Ice Age
    
    
    my_movies.increment_watched("Big", 1);                    // OK
    my_movies.increment_watched("Ice Age", 1);              // OK
    
    my_movies.display();    // Big and Ice Age watched count incremented by 1
    
    my_movies.increment_watched("XXX", 1);         // XXX not found

	return 0;
}