#include "Replay.h"

void Replay::addCommandToLog(std::unique_ptr<Command> cmd) {
    commandLog.push_back(std::move(cmd));
}

void Replay::execute() {
    for (auto& cmd : commandLog) {
        cmd->execute();
    }
}
