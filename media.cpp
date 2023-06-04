#include "Media/media.h"
using namespace std;

Media::Media() {
  mediaType = '\0';
  stock = 0;
  director = "";
  title = "";
  yearReleased = 0;
  this->borrowedStock = 0;
}

Media::Media(char type, int stock, string director, string title, int year) {
  this->mediaType = type;
  this->stock = stock;
  this->director = director;
  this->title = title;
  this->yearReleased = year;
  this->borrowedStock = 0;
}

string Media::getDetails(){
  // D, F, 10, John S, The Flash, 2023
  return string(1, mediaType) + ", " + to_string(stock) + ", " + director + ", " + title + ", " + to_string(yearReleased);
}

// reduce the stock by 1
void Media::borrow(){
  this->stock--;
  this->borrowedStock++;
}

// increase stock by 1
void Media::returnItem(){
  this->stock++;
  this->borrowedStock--;
}

string Media::getTitle(){
  return this->title;
}

string Media::getDirector(){
  return this->director;
}

int Media::getYear(){
  return this->yearReleased;
}

int Media::getStock(){
  return this->stock;
}

int Media::getBorrowedStock(){
  return this->borrowedStock;
}