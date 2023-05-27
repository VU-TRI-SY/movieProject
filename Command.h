#pragma once
#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

using namespace std;

class Store;

class Command {
private:
    string commandType;
    int customerID;
    int mediaType;
    int movieType;

public:
    Command(const string& commandType, int customerID, int mediaType, int movieType);
    void execute(Store& store);
};

#endif  // COMMAND_H