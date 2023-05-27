/*
The Comedy class is a subclass of the Movie class, which adds a specific
movie-type attribute. This class forms the basis for the specific movie types
Comedy, Drama, and Classic. Beside inheriting some main attibutes from the Movie
class, this class has its own attribute, such as getYear, setYear...
*/

#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Comedy : public Movie {

public:
  // constructor
  Comedy();
  Comedy(char type, int stock, string director, string title, int year);

  // getter, setter
  void setYear(int);
  int getYear();
};

#endif