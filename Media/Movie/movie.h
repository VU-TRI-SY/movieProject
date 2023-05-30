/*
The Movie class is a subclass of the Media class, which adds a specific
movie-type attribute. This class forms the basis for the specific movie types
Comedy, Drama, and Classic. Beside inheriting some main attibutes from the Media
class, this class has its own attribute, such as movieType... such as:
*/

#ifndef MOVIE_H
#define MOVIE_H

#include "../media.h"
#include <fstream>

using namespace std;

class Movie : public Media {
private:
  char movieType;

public:
  Movie();
  Movie(char type, int stock, string director, string title, int year);
  string getDetails(); //override
};

#endif