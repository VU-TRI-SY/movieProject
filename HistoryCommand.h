#ifndef HISTORYCOMMAND_H
#define HISTORYCOMMAND_H

#include "Command.h"

class HistoryCommand : public Command {
public:
    HistoryCommand(const string& commandType, int customerID, int mediaType, int movieType);
    void execute(Store& store) override;
};

#endif  // HISTORYCOMMAND_H