#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Card.h"

class User {
public:
    User(int id, std::string pw, std::string name, int remainScore);
    virtual ~User();  // Add a virtual destructor

    int getId() const;
    const std::string& getPassword() const;
    const std::string& getName() const;
    int getRemainingScore() const;
    void setRemainingScore(int score);
    const std::vector<Card>& getCardsInHand() const;
    void addCard(const Card& card);
    void clearCards();
    void printMyInformation() const;

private:
    int id;
    std::string pw;
    std::string name;
    int remainScore;
    std::vector<Card> cardsInHand;
};

#endif // USER_H
