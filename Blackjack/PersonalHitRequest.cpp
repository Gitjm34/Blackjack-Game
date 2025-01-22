#include "PersonalHitRequest.h"
#include "AIUser.h"
#include <iostream>

PersonalHitRequest::PersonalHitRequest(std::vector<User>& players, std::queue<Card>& deck, int playerIndex)
    : players(players), deck(deck), playerIndex(playerIndex) {}

void PersonalHitRequest::execute() {
    if (playerIndex < 0 || playerIndex >= players.size()) return;

    User& player = players[playerIndex];
    char choice;

    do {
        int score = 0;
        for (const auto& card : player.getCardsInHand()) {
            score += card.getNumber();
        }

        if (dynamic_cast<AIUser*>(&player)) {
            choice = dynamic_cast<AIUser*>(&player)->shouldHit(score) ? 'y' : 'n';
        }
        else {
            std::cout << player.getName() << ", 히트 하시겠습니까? (yes/no): ";
            std::cin >> choice;
        }

        if (choice == 'y' && !deck.empty()) {
            player.addCard(deck.front());
            deck.pop();
            score += player.getCardsInHand().back().getNumber();
            std::cout << player.getName() << "의 현재 점수: " << score << "\n";
            if (score > 21) {
                std::cout << player.getName() << " has lost.\n";
                player.setRemainingScore(0);
                break;
            }
        }
        else {
            break;
        }
    } while (choice == 'y');
}

std::string PersonalHitRequest::getName() const {
    return "PersonalHitRequest";
}
