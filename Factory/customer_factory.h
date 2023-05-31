#ifndef CUSTOMER_FACTORY_H
#define CUSTOMER_FACTORY_H
#include <fstream>
#include <iostream>
#include <string>

#include "../customer.h"

class CustomerFactory {
    public:
        Customer* createCustomer(const std::string &str);
};

#endif 
