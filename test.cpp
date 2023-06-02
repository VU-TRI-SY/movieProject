#include <bits/stdc++.h>
#include "Media/media.h"
#include "Media/Movie/movie.h"
#include "Media/Movie/comedy.h"
#include "Media/Movie/drama.h"
#include "Media/Movie/classics.h"
#include "Factory/comedy_factory.h" //ctrl+click left mouse to see the file
#include "Factory/drama_factory.h"
#include "Factory/classics_factory.h"
#include "Factory/movie_factory.h"
#include "customer.h"
#include "Factory/customer_factory.h"
#include "driver.h"
using namespace std;

int main(){
    Store store;
    readInventory("data4movies.txt", store);
    cout << "--------------------------------------------------------\n";
    readCustomers("data4customers.txt", store);
    cout << "--------------------------------------------------------\n";
    // readCommands("data4commands.txt", store);
    // cout << "--------------------------------------------------------\n";
    return 0;
}

