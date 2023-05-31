/*
Media class is a parent class of the movie class and a grandparent class of
drama, comedy and classics. This class initilizes many main charactertics of a
media item, such as MediaType, amount of item in stock, director, title and
released year...
*/

#ifndef MEDIA_H
#define MEDIA_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Media {
private:
  char mediaType;
  int stock;
  int borrowedStock;
  string director;
  string title;
  int yearReleased;

public:
  // default constructor
  Media();
  // constructor which passes agruments like type, stock, director, title and
  // year
  Media(char type, int stock, string director, string title, int year);

  virtual string getDetails();

  // reduce the stock by 1
  void borrow();

  // increase stock by 1
  void returnItem();

  string getTitle();
  string getDirector();
  int getYear();
  int getStock();
  int getBorrowedStock();
};

#endif