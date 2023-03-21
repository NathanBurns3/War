#include "Deck.h"
#include <iostream>

Deck::Deck(int startingCards) {
    head = nullptr;
    numOfCards = 0;
    // Add 20 cards to deck
    for (int i = 0; i < startingCards; i++) {
        // Create a card with a random value between 1-12
        int card = rand() % 11 + 1;
        // Add the card to the deck
        AddCard(card);
    }
}

Deck::~Deck() {
    Node* temp;
    // Loop through the list deleting each node
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void Deck::AddCard(int card) {
    // If the deck is empty make the card the head of the list
    if (numOfCards == 0) {
        head = new Node(card);
    }
    // Create a temp node
    Node *temp = head;
    // Loop through the list checking each time if the node is at the end of the list
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    // Once you find the end of the list add the new card
    temp->next = new Node(card);
    // increment the counter for cards in the deck
    numOfCards++;
}

int Deck::RemoveCard() {
    // Check if the list is empty and throw an empty list exception
    if (numOfCards == 0) {
        //throw EmptyListException("This list is empty");
        std::cout << "This list is empty";
        return 0;
    }
    // Create a temp Node that copies the head of the list
    Node *temp = head;
    // Set head to the next node in the list
    head = head->next;
    // Create a return variable that holds the data in the temp Node
    int returnVal = temp->data;
    // Delete the temp Node
    delete temp;
    // Decrement the counter for cards in the deck
    numOfCards--;
    // Return the return data variable
    return returnVal;
}

int Deck::GetNumOfCards() {
    return numOfCards;
}