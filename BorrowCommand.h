#ifndef BORROWCOMMAND_H
#define BORROWCOMMAND_H

#include "Command.h"

class BorrowCommand : public Command {
public:
    BorrowCommand(const string& commandType, int customerID, int mediaType, int movieType);
    void execute(Store& store) override;
};

#endif  // BORROWCOMMAND_H