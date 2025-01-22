#ifndef CHECKLOSER_H
#define CHECKLOSER_H

#include "Command.h"
#include "User.h"
#include "UserScoreInfo.h"
#include <vector>
#include <queue>
#include <string>

class CheckLoser : public Command {
public:
    CheckLoser(std::vector<User>& players, std::priority_queue<UserScoreInfo>& rankQueue);
    void execute() override;
    std::string getName() const override;

private:
    std::vector<User>& players;
    std::priority_queue<UserScoreInfo>& rankQueue;
};

#endif // CHECKLOSER_H
