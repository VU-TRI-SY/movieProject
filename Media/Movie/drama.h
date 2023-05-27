/*
The Drama class is a subclass of the Movie class, which adds a specific
movie-type attribute. This class forms the basis for the specific movie types
Comedy, Drama, and Classic. Beside inheriting some main attibutes from the Movie
class, this class has its own attribute, such as getYear, setYear...
*/

#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Drama : public Movie {
private:
  char movieType;

public:
  Drama();
  Drama(char type, int stock, string director, string title, int year);
  // seter, getter
  void setYear(int);
  int getYear();
};

#endif