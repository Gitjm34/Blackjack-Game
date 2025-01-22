#ifndef CHECKWINNER_H
#define CHECKWINNER_H

#include "Command.h"
#include "User.h"
#include "UserScoreInfo.h"
#include <vector>
#include <queue>
#include <string>

class CheckWinner : public Command {
public:
    CheckWinner(std::vector<User>& players, std::priority_queue<UserScoreInfo>& rankQueue);
    void execute() override;
    std::string getName() const override;

private:
    std::vector<User>& players;
    std::priority_queue<UserScoreInfo>& rankQueue;
};

#endif // CHECKWINNER_H
