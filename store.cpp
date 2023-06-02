#include <iostream>
#include <algorithm>
#include "store.h"

using namespace std;
Store::Store(){
    //do nothing
    customerList = unordered_map<int, Customer *>();
}
Store::~Store(){
    for(auto it = customerList.begin(); it != customerList.end(); it++){
        delete it->second;
        it->second = nullptr;
    }

    for(auto it = inventory.begin(); it != inventory.end(); it++){
        for(int i = 0; i < it->second.size(); i++){
            delete it->second[i];
            it->second[i] = nullptr;
        }
    }
}
void Store::addMedia(Media *media){
    //casting to the type of Movie to add to the inventory
    Movie *movie = dynamic_cast<Movie *>(media);
    switch (movie->getMovieType())
    {
    case 'F':
        if(inventory.count("Comedy") == 0){
            vector<Media *> comedyList;
            comedyList.push_back(media);
            inventory.insert(make_pair("Comedy", comedyList));
        }else{
            inventory["Comedy"].push_back(media);
            std::sort(inventory["Comedy"].begin(), inventory["Comedy"].end(), [](Media* m1, Media* m2){
                if(m1->getTitle() != m2->getTitle()){
                    return (m1->getTitle().compare(m2->getTitle()) < 0);
                }else{
                    return m1->getYear() < m2->getYear();
                }
            });
        }
        break;
    case 'D':
        if(inventory.count("Drama") == 0){
            vector<Media *> dramaList;
            dramaList.push_back(media);
            inventory.insert(make_pair("Drama", dramaList));
        }else{
            inventory["Drama"].push_back(media);
            std::sort(inventory["Drama"].begin(), inventory["Drama"].end(), [](Media* m1, Media* m2){
                if(m1->getDirector() != m2->getDirector()){
                    return (m1->getDirector().compare(m2->getDirector()) < 0);
                }else{
                    return (m1->getTitle().compare(m2->getTitle()) < 0);
                }
            });
        }
        break;
    
    case 'C':
        if(inventory.count("Classics") == 0){
            vector<Media *> classicList;
            classicList.push_back(media);
            inventory.insert(make_pair("Classics", classicList));
        }else{
            inventory["Classics"].push_back(media);
            std::sort(inventory["Classics"].begin(), inventory["Classics"].end(), [](Media* m1, Media* m2){
                Classics *c1 = dynamic_cast<Classics *>(m1);
                Classics *c2 = dynamic_cast<Classics *>(m2);
                if(m1->getYear() != m2->getYear()){
                    return m1->getYear() < m2->getYear();
                }else{
                    if(c1->getReleaseMonth() != c2->getReleaseMonth()){
                        return c1->getReleaseMonth() < c2->getReleaseMonth();
                    }else{
                        return (c1->getActor().compare(c2->getActor()) < 0);
                    }
                }
            });
        }
        break;
    default:
        break;
    }
}

// Removes a media from the inventory
void Store::removeMedia(Media *media){
    //delete all the media in the inventory
    Movie *movie = dynamic_cast<Movie *>(media);
    switch (movie->getMovieType()){
    case 'F':
        for(int i = 0; i < inventory["Comedy"].size(); i++){
            if(inventory["Comedy"][i] == media){
                inventory["Comedy"].erase(inventory["Comedy"].begin() + i);
            }
        }
        break;
    case 'D':
        for(int i = 0; i < inventory["Drama"].size(); i++){
            if(inventory["Drama"][i] == media){
                inventory["Drama"].erase(inventory["Drama"].begin() + i);
            }
        }
        break;

    case 'C':
        for(int i = 0; i < inventory["Classics"].size(); i++){
            if(inventory["Classics"][i] == media){
                inventory["Classics"].erase(inventory["Classics"].begin() + i);
            }
        }
        break;
    }
}

// Adds a new customer
void Store::addCustomer(Customer *customer){
    customerList[customer->getId()] = customer;
}

// Returns the list of all media items currently in the store's inventory.
unordered_map<string, vector<Media *>>  Store::getInventory(){
    return inventory;
}

// Returns a customer with the provided id
Customer* Store::getCustomer(int customerId){
    if(customerList.count(customerId) == 0){
        return nullptr;
    }else{
        return customerList[customerId];
    }
}

void Store::addTransactionHistory(int customerID, string transaction){
    if(transactionHistory.count(customerID) == 0){
        vector<string> transactionList;
        transactionList.push_back(transaction);
        transactionHistory.insert(make_pair(customerID, transactionList));
    }else{
        transactionHistory[customerID].push_back(transaction);
    }
}

// Returns a list of history transaction of a particular customer (with
// customerID)
vector<string> Store::getHistory(int customerId){
    if(transactionHistory.count(customerId) == 0){
        return vector<string>(); //return empty vector
    }else{
        return transactionHistory[customerId];
    }
}

// Customer borrow a media
void Store::borrowMedia(Customer* customer, Media* media){
    if(customerList.count(customer->getId()) > 0){
        customerList[customer->getId()]->borrowMedia(media);
        media->borrow();
    }
}

// Customer return a media
void Store::returnMedia(Customer* customer, Media* media){
    if(customerList.count(customer->getId()) > 0){
        customerList[customer->getId()]->returnMedia(media);
        media->returnItem();
    }
}

void Store::printInventory(){
    cout << "Comedy:" << endl;
    for(int i = 0; i < inventory["Comedy"].size(); i++){
        cout << inventory["Comedy"][i]->getDetails() << endl;
        cout << "Borrowed: " << inventory["Comedy"][i]->getBorrowedStock() << ", Remaining: " << inventory["Comedy"][i]->getStock() << endl;
    }
    cout << "Drama:" << endl;
    for(int i = 0; i < inventory["Drama"].size(); i++){
        cout << inventory["Drama"][i]->getDetails() << endl;
        cout << "Borrowed: " << inventory["Drama"][i]->getBorrowedStock() << ", Remaining: " << inventory["Drama"][i]->getStock() << endl;
    }
    cout << "Classics:" << endl;
    for(int i = 0; i < inventory["Classics"].size(); i++){
        cout << inventory["Classics"][i]->getDetails() << endl;
        cout << "Borrowed: " << inventory["Classics"][i]->getBorrowedStock() << ", Remaining: " << inventory["Classics"][i]->getStock() << endl;
    }
}

Media* Store::getMedia(char movieType, string title, int year){//search Comedy
    for(int i = 0; i < inventory["Comedy"].size(); i++){
        if(inventory["Comedy"][i]->getTitle() == title && inventory["Comedy"][i]->getYear() == year){
            return inventory["Comedy"][i];
        }
    }
    return nullptr;
}
Media* Store::getMedia(char movieType, string director, string title){//search Drama
    for(int i = 0; i < inventory["Drama"].size(); i++){
        if(inventory["Drama"][i]->getTitle() == title && inventory["Drama"][i]->getDirector() == director){
            return inventory["Drama"][i];
        }
    }
    return nullptr;
}
Media* Store::getMedia(char movieType, int month, int year, string actor){//search Classics
    for(int i = 0; i < inventory["Classics"].size(); i++){
        Classics *c = dynamic_cast<Classics *>(inventory["Classics"][i]);
        if(c->getReleaseMonth() == month && c->getYear() == year && c->getActor() == actor){
            return inventory["Classics"][i];
        }
    }
    return nullptr;
}