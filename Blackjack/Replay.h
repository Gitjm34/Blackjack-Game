#ifndef REPLAY_H
#define REPLAY_H

#include "Command.h"
#include <vector>
#include <memory>

class Replay {
public:
    void addCommandToLog(std::unique_ptr<Command> cmd);
    void execute();

private:
    std::vector<std::unique_ptr<Command>> commandLog;
};

#endif // REPLAY_H
