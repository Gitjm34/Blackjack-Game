#include "InitialCardDistribution.h"
#include <iostream>

InitialCardDistribution::InitialCardDistribution(std::vector<User>& players, std::queue<Card>& deck)
    : players(players), deck(deck) {}

void InitialCardDistribution::execute() {
    std::cout << "Distributing initial cards...\n";
    for (auto& player : players) {
        if (deck.size() >= 2) {
            player.addCard(deck.front());
            deck.pop();
            player.addCard(deck.front());
            deck.pop();
        }
    }
}

std::string InitialCardDistribution::getName() const {
    return "InitialCardDistribution";
}
