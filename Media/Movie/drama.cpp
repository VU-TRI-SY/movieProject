#include "drama.h"

using namespace std;

Drama::Drama() : Movie() {
}

Drama::Drama(char movieType, int stock, string director, string title, int year) : Movie(movieType, stock, director, title, year) {

}