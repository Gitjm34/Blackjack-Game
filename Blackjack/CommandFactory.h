#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Command.h"
#include "User.h"
#include "UserScoreInfo.h"
#include <vector>
#include <queue>
#include <memory>
#include <string>

class CommandFactory {
public:
    static CommandFactory& getInstance();

    std::unique_ptr<Command> createCommand(
        const std::string& commandType,
        std::vector<User>& players,
        std::queue<Card>& deck,
        int playerIndex = -1
    );

    std::unique_ptr<Command> createCommand(
        const std::string& commandType,
        std::vector<User>& players,
        std::priority_queue<UserScoreInfo>& rankQueue
    );

private:
    CommandFactory() {} // Make constructor private to enforce singleton
};

#endif // COMMANDFACTORY_H
