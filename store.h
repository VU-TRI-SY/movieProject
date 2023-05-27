#include <string>
#include "media.h"
#include "customer.h"
#include <unordered_map>
#include <vector>


// Store.h
class Store {
public:
    // Reads inventory data from a file
    void readInventory(string fileName);

    // Reads customer data from a file
    void readCustomers(string fileName);

    // Reads command data from a file
    void readCommands(string fileName);

    // Adds a new media to the inventory
    void addMedia(Media* media);

    // Removes a media from the inventory
    void removeMedia(Media* media);

    // Adds a new customer
    void addCustomer(Customer* customer);

    // Returns the inventory
    unordered_map<string, vector<Media*>> getInventory();

    // Returns a customer with the provided id
    Customer* getCustomer(int customerId);

private:
    unordered_map<string, vector<Media*>> inventory;
    unordered_map<int, Customer*> customerList;
};
