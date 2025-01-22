#ifndef PERSONALHITREQUEST_H
#define PERSONALHITREQUEST_H

#include "Command.h"
#include "User.h"
#include "Card.h"
#include <vector>
#include <queue>
#include <string>

class PersonalHitRequest : public Command {
public:
    PersonalHitRequest(std::vector<User>& players, std::queue<Card>& deck, int playerIndex);
    void execute() override;
    std::string getName() const override;

private:
    std::vector<User>& players;
    std::queue<Card>& deck;
    int playerIndex;
};

#endif // PERSONALHITREQUEST_H
