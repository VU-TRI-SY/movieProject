#include "movie.h"

Movie::Movie(): Media() { 
  //first: call default constructor of Media
  //second: set movieType to '\0'
  this->movieType = '\0';
}

Movie::Movie(char movieType, int stock, string director, string title, int year): Media('D', stock, director, title, year) {
  //Move('F', 10, "John S", "The Flash", 2023)
  //Media('D', 10, "John S", "The Flash", 2023)
  //first: call constructor of Media to create DVD item
  this->movieType = movieType;
}

string Movie::getDetails(){
  // D, F, 10, John S, The Flash, 2023
  string details = Media::getDetails();
  //details = "D, 10, John S, The Flash, 2023"
  // insert "movie_type, " after D, 
  string inserted_str = string(1, this->movieType) + ", ";
  details.insert(3, inserted_str);
  return details;
}