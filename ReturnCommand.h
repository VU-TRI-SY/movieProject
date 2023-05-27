#ifndef RETURNCOMMAND_H
#define RETURNCOMMAND_H

#include "Command.h"

class ReturnCommand : public Command {
public:
    ReturnCommand(const string& commandType, int customerID, int mediaType, int movieType);
    void execute(Store& store) override;
};

#endif  // RETURNCOMMAND_H