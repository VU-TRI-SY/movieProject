#include "store.h"
#include <iostream>

int main() {
  Store myStore;
  myStore.readInventory("data4movies.txt");
  myStore.readCustomers("data4customers.txt");
  myStore.readCommands("data4commands.txt");
  return 0;
}