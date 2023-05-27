/*
The Classics class is a subclass of the Movie class, which adds a specific
movie-type attribute. This class forms the basis for the specific movie types
Comedy, Drama, and Classic. Beside inheriting some main attibutes from the Movie
class, this class has its own attribute, such as monthReleased, actor,...
*/

#ifndef CLASSICS_H
#define CLASSICS_H

#include "movie.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Classics : public Movie {
private:
  int monthReleased;
  string actor;

public:
  // getter, setter
  void setActor(string);
  void setReleaseMonth(int);
  int getReleaseMonth();
};

#endif