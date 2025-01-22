#include "User.h"
#include <iostream>

User::User(int id, std::string pw, std::string name, int remainScore)
    : id(id), pw(std::move(pw)), name(std::move(name)), remainScore(remainScore) {}

User::~User() {}  // Define the virtual destructor

int User::getId() const {
    return id;
}

const std::string& User::getPassword() const {
    return pw;
}

const std::string& User::getName() const {
    return name;
}

int User::getRemainingScore() const {
    return remainScore;
}

void User::setRemainingScore(int score) {
    remainScore = score;
}

const std::vector<Card>& User::getCardsInHand() const {
    return cardsInHand;
}

void User::addCard(const Card& card) {
    cardsInHand.push_back(card);
}

void User::clearCards() {
    cardsInHand.clear();
}

void User::printMyInformation() const {
    std::cout << "ID: " << id << ", Name: " << name << ", Remaining Score: " << remainScore << "\n";
}
