#include "CheckWinner.h"
#include <iostream>

CheckWinner::CheckWinner(std::vector<User>& players, std::priority_queue<UserScoreInfo>& rankQueue)
    : players(players), rankQueue(rankQueue) {}

void CheckWinner::execute() {
    for (auto& player : players) {
        int score = 0;
        for (const auto& card : player.getCardsInHand()) {
            score += card.getNumber();
        }
        rankQueue.push(UserScoreInfo(&player, score));
    }
    if (!rankQueue.empty()) {
        auto winner = rankQueue.top();
        std::cout << "Rank 1: " << winner.getUser()->getName() << ", Score: " << winner.getScore() << "\n";
    }
}

std::string CheckWinner::getName() const {
    return "CheckWinner";
}
