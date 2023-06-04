#include <iostream>
#include <fstream>
#include <string>

#include "store.h"

// Reads inventory data from a file
void readInventory(string file_name, Store& store);

// Reads customer data from a file
void readCustomers(string file_name, Store& store);

// Reads command data from a file
void readCommands(string file_name, Store& store);