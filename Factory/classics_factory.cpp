#include <sstream>

#include "classics_factory.h"
using namespace std;

Media* ClassicsFactory::createMedia(const string &str) {
    // when createMedia is called, str is in the following format: "10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942"
    stringstream ss(str);
    int stock;
    string director, title, first_name, last_name;
    int month,year;
    ss >> stock;
    //", Michael Curtiz, Casablanca, Ingrid Bergman 8 1942"
    ss.ignore(2); // ignore the comma and the space characters
    // "Michael Curtiz, Casablanca, Ingrid Bergman 8 1942"
    getline(ss, director, ','); // read until the comma and discard the comma
    // " Casablanca, Ingrid Bergman 8 1942"
    ss.ignore(1); // ignore the space character
    // "Casablanca, Ingrid Bergman 8 1942"
    getline(ss, title, ','); // read until the comma
    // " Ingrid Bergman 8 1942"
    ss.ignore(1); // ignore the space character
    // "Ingrid Bergman 8 1942"
    ss >> first_name >> last_name >> month >> year;
    
    std::stringstream ss1;
    ss << first_name << last_name; // Concatenate str1 and str2 using std::stringstream to avoid the disavantage of + operator
    std::string actor = ss1.str();

    return new Classics('C', stock, director, title, actor, month, year);
}