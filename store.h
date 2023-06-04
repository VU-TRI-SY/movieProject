/*
The _Store class_ manages the inventory of media items and the list of
customers. It provides methods to read data from files to populate the inventory
and customer list. It also allows to add or remove media from the inventory, add
customers, and retrieve specific media or customer data.
*/

#include "customer.h"
#include "Media/media.h"
#include "Media/Movie/movie.h"
#include "Media/Movie/classics.h"
#include <string>
#include <unordered_map>
#include <vector>

// Store.h
class Store {
private:
  unordered_map<string, vector<Media *>> inventory;
  unordered_map<int, Customer *> customerList;
  // vector<string> transactionHistory;
  unordered_map<int, vector<string>> transactionHistory;
  // customerList is a map that stores the list of current customers. The key is the customer ID and the value is a pointer to the Customer object.
  // transactionHistory is map that stores the list of transactions. The key is the customer ID and the value is a vector of strings. Each string represents a transaction.

public:
  Store();
  ~Store();
  // Adds a new media to the inventory
  void addMedia(Media *media);

  // Removes a media from the inventory
  void removeMedia(Media *media);

  // Adds a new customer
  void addCustomer(Customer *customer);

  // Returns the list of all media items currently in the store's inventory.
  unordered_map<string, vector<Media *>>  getInventory();

  // Returns a customer with the provided id
  Customer *getCustomer(int customerId);

  // Returns a list of history transaction of a particular customer (with
  // customerID)
  vector<string> getHistory(int customerId);

  void addTransactionHistory(int customerID, string transaction);
  
  // Customer borrow a media
  void borrowMedia(Customer* customer, Media* media);

  // Customer return a media
  void returnMedia(Customer* customer, Media* media);

  void printInventory();

  Media* getMedia(char movieType, string title, int year); //search Comedy
  Media* getMedia(char movieType, string director, string title); //search Drama
  Media* getMedia(char movieType, int month, int year, string actor); //search Classic

  void sortComedyMovie();

  void sortClassicsMovie();

  void sortDramaMovie();

  void displayHistory(int customerID);
};
