#ifndef _SIDEPILE_H_
#define _SIDEPILE_H_

class SidePile {
public:
    int Cards[5]; //Can only have up to 5 cards in the pile
    int numOfCards;
    SidePile();
    ~SidePile();
    void AddCard(int card);
    int RemoveCard();
    int GetNumOfCards();
};

#endif