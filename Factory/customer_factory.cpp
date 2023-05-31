#include <sstream>
#include "customer_factory.h"
using namespace std;

Customer* CustomerFactory::createCustomer(const string &str) {
    //string str = "3333 Witch Wicked"
    stringstream ss(str);
    int id;
    string first_name, last_name;
    ss >> id >> first_name >> last_name;
    return new Customer(id, first_name, last_name);
}