#include "SidePile.h"
#include <iostream>

SidePile::SidePile() {
    numOfCards = 0;
}

SidePile::~SidePile() {
    for (int i = 0; i < 5; i++) {
        Cards[i] = 0;
    }
    numOfCards = 0;
}

void SidePile::AddCard(int card) {
    if (numOfCards < 5) {
        Cards[numOfCards] = card;
        numOfCards++;
    }
    else {
        //throw StackOverflowException("The pile is maxed out");
        std::cout << "The pile is maxed out";
        return;
    }
}

int SidePile::RemoveCard() {
    if (numOfCards > 0) {
        return Cards[numOfCards - 1];
        numOfCards--;
    }
    else {
        //throw StackOverflowException("There aren't any cards in the pile");
        std::cout << "There aren't any cards in the pile";
        return 0;
    }
}

int SidePile::GetNumOfCards() {
    return numOfCards;
}