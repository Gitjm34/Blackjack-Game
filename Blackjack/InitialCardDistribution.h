#ifndef INITIALCARDDISTRIBUTION_H
#define INITIALCARDDISTRIBUTION_H

#include "Command.h"
#include "User.h"
#include "Card.h"
#include <vector>
#include <queue>
#include <string>

class InitialCardDistribution : public Command {
public:
    InitialCardDistribution(std::vector<User>& players, std::queue<Card>& deck);
    void execute() override;
    std::string getName() const override;

private:
    std::vector<User>& players;
    std::queue<Card>& deck;
};

#endif // INITIALCARDDISTRIBUTION_H
