#include "Node.cpp"

#ifndef _DECK_H_
#define _DECK_H_

class Deck {
    private:
        int numOfCards;
    public:
        Node* head;
        Deck(int startingCards);
        ~Deck();
        void AddCard(int card);
        int RemoveCard();
        int GetNumOfCards();
    };

#endif