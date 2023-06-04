#include "Media/Movie/comedy.h"

using namespace std;

Comedy::Comedy(): Movie() {

}

Comedy::Comedy(char movieType, int stock, string director, string title, int year): Movie(movieType, stock, director, title, year) {
  // call the parent constructor
}
