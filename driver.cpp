#include "store.h"
#include <iostream>

int main() {
  Store myStore;
  
  // Reads inventory data from a file
  myStore.readInventory("data4movies.txt");
  
  // Reads customer data from a file
  myStore.readCustomers("data4customers.txt");
  
    // Reads command data from a file
  myStore.readCommands("data4commands.txt");
  return 0;
}
