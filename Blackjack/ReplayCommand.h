#ifndef REPLAYCOMMAND_H
#define REPLAYCOMMAND_H

#include "Command.h"
#include <vector>
#include <memory>

class ReplayCommand : public Command {
public:
    void addCommand(std::unique_ptr<Command> command);
    void execute() override;
    std::string getName() const override;

private:
    std::vector<std::unique_ptr<Command>> replayLog;
};

#endif // REPLAYCOMMAND_H
