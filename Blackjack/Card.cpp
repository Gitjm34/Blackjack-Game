#include "Card.h"

Card::Card(int suit, int number) : suit(suit), number(number) {}
Card::Card() : suit(0), number(0) {} // Default constructor

int Card::getSuit() const {
    return suit;
}

int Card::getNumber() const {
    return number;
}
