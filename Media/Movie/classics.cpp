#include "classics.h"
#include <iostream>

using namespace std;

// Default constructor
Classics::Classics(): Movie() {
  //first: call default constructor of Movie
  //second: set monthReleased to 0  and actor to ""
  monthReleased = 0;
  actor = "";
}

Classics::Classics(char movieType, int stock, string director, string title, string actor, int month, int year) : Movie(movieType, stock, director, title, year) {
  //first: call constructor of Movie
  //second: set monthReleased to month and actor to actor
  this->actor = actor;
  this->monthReleased = month;
}

// setter, getter
void Classics::setActor(string actor) { this->actor = actor; }
string Classics::getActor() { return actor; }
void Classics::setReleaseMonth(int month) { this->monthReleased = month; }
int Classics::getReleaseMonth() { return monthReleased; }

string Classics::getDetails(){
  string details = Movie::getDetails();
  //details = "D, F, 10, John S, The Flash, Jack, 10, 2023"
  char delim = ',';
  int index = 0;
  int count = 0;
  while(count < 5){
    if(details[index] == delim){
      count++;
    }
    index++;
  }
  // count = 5
  // index: after the fifth comma
  // insert "actor, monthr" after the fifth comma
  string inserted_str = actor + ", " + to_string(monthReleased) + ", ";
  details.insert(index+1, inserted_str);
  return details;
}
