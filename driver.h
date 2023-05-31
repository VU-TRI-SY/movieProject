#include <iostream>
#include <fstream>
#include <string>

#include "Factory/customer_factory.h"
#include "Factory/media_factory.h"
#include "Factory/movie_factory.h"
#include "Factory/comedy_factory.h"
#include "Factory/drama_factory.h"
#include "Factory/classics_factory.h"
#include "store.h"

// Reads inventory data from a file
void readInventory(string file_name, Store& store);

// Reads customer data from a file
void readCustomers(string file_name, Store& store);

// Reads command data from a file
void readCommands(string file_name, Store& store);