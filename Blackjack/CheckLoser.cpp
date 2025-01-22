#include "CheckLoser.h"
#include <iostream>

CheckLoser::CheckLoser(std::vector<User>& players, std::priority_queue<UserScoreInfo>& rankQueue)
    : players(players), rankQueue(rankQueue) {}

void CheckLoser::execute() {
    for (auto& player : players) {
        int score = 0;
        for (const auto& card : player.getCardsInHand()) {
            score += card.getNumber();
        }
        if (score > 21) {
            player.setRemainingScore(0); 
            std::cout << player.getName() << " has lost.\n";
        }
    }
}

std::string CheckLoser::getName() const {
    return "CheckLoser";
}
    