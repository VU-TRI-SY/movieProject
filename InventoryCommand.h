#ifndef INVENTORYCOMMAND_H
#define INVENTORYCOMMAND_H

#include "Command.h"

class InventoryCommand : public Command {
public:
    InventoryCommand(const string& commandType, int customerID, int mediaType, int movieType);
    void execute(Store& store) override;
};

#endif  // INVENTORYCOMMAND_H