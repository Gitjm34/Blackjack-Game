#include "CommandFactory.h"
#include "CheckWinner.h"
#include "CheckLoser.h"
#include "InitialCardDistribution.h"
#include "PersonalHitRequest.h"

CommandFactory& CommandFactory::getInstance() {
    static CommandFactory instance;
    return instance;
}

std::unique_ptr<Command> CommandFactory::createCommand(
    const std::string& commandType,
    std::vector<User>& players,
    std::queue<Card>& deck,
    int playerIndex
) {
    if (commandType == "InitialCardDistribution") {
        return std::make_unique<InitialCardDistribution>(players, deck);
    }
    if (commandType == "PersonalHitRequest") {
        return std::make_unique<PersonalHitRequest>(players, deck, playerIndex);
    }
    return nullptr;
}

std::unique_ptr<Command> CommandFactory::createCommand(
    const std::string& commandType,
    std::vector<User>& players,
    std::priority_queue<UserScoreInfo>& rankQueue
) {
    if (commandType == "CheckLoser") {
        return std::make_unique<CheckLoser>(players, rankQueue);
    }
    if (commandType == "CheckWinner") {
        return std::make_unique<CheckWinner>(players, rankQueue);
    }
    return nullptr;
}
