#include "Node.cpp"

#ifndef _DECK_H_
#define _DECK_H_

class Deck {
public:
    Node* head;
    int numOfCards;
    Deck();
    ~Deck();
    void AddCard(int card);
    int RemoveCard();
    int GetNumOfCards();
};

#endif