#include <iostream>

#include "customer.h"
#include "Media/media.h"

using namespace std;
Customer::Customer(){
    customerId = 0;
    firstName = "";
    lastName = "";
}

Customer::Customer(int customerId, string firstName, string lastName) {
    this->customerId = customerId;
    this->firstName = firstName;
    this->lastName = lastName;
}

void Customer::borrowMedia(Media *media){
    borrowedMedia.push_back(media);
}

void Customer::returnMedia(Media* media){
    for (int i = 0; i < borrowedMedia.size(); i++){
        if (borrowedMedia[i] == media){
            borrowedMedia.erase(borrowedMedia.begin() + i);
            return;
        }
    }
}

string Customer::getDetails(){
    string details = to_string(customerId) + " " + firstName + " " + lastName;
    return details;
}

int Customer::getId(){
    return customerId;
}

