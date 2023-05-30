/*
The _Store class_ manages the inventory of media items and the list of
customers. It provides methods to read data from files to populate the inventory
and customer list. It also allows to add or remove media from the inventory, add
customers, and retrieve specific media or customer data.
*/

#include "customer.h"
#include "media.h"
#include <string>
#include <unordered_map>
#include <vector>

// Store.h
class Store {
private:
  unordered_map<string, vector<Media *>> inventory;
  unordered_map<int, Customer *> customerList;
  vector<string> transactionHistory;

public:
  // Reads inventory data from a file
  void readInventory(string fileName);

  // Reads customer data from a file
  void readCustomers(string fileName);

  // Reads command data from a file
  void readCommands(string fileName);

  // Adds a new media to the inventory
  void addMedia(Media *media);

  // Removes a media from the inventory
  void removeMedia(Media *media);

  // Adds a new customer
  void addCustomer(Customer *customer);

  // Returns the list of all media items currently in the store's inventory.
  void getInventory();

  // Returns a customer with the provided id
  Customer *getCustomer(int customerId);

  // Returns a list of history transaction of a particular customer (with
  // customerID)
  vector<string> getHistory(int customerId);

  // Customer borrow a media
  void borrowMedia();

  // Customer return a media
  void returnMedia();
};
