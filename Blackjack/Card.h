#ifndef CARD_H
#define CARD_H

class Card {
public:
    Card(int suit, int number);
    Card(); // Default constructor

    int getSuit() const;
    int getNumber() const;

private:
    int suit;
    int number;
};

#endif // CARD_H
