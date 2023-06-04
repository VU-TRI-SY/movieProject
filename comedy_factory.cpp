#include <sstream>

#include "Factory/comedy_factory.h"
using namespace std;

Media* ComedyFactory::createMedia(const string &str) {
    // when createMedia is called, str is in the following format: "10, Rob Reiner, When Harry Met Sally, 1989"
    stringstream ss(str);
    int stock;
    string director, title;
    int year;
    ss >> stock;
    //", Rob Reiner, When Harry Met Sally, 1989"
    ss.ignore(2); // ignore the comma and the space characters
    // "Rob Reiner, When Harry Met Sally, 1989"
    getline(ss, director, ','); // read until the comma and discard the comma
    // " When Harry Met Sally, 1989"
    ss.ignore(1); // ignore the space character
    // "When Harry Met Sally, 1989"
    getline(ss, title, ','); // read until the comma
    // " 1989"
    ss.ignore(1); // ignore the comma
    // "1989"
    ss >> year;
    return new Comedy('F', stock, director, title, year);
}