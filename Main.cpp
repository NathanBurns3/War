#include "Deck.h"
#include "Node.cpp"
#include "SidePile.h"
#include <iostream>

int main() {
    // Variable to determine if the game should still be played
    bool keepPlaying = true;
    // Variable to determine if the user wants to see how many cards are in the computers deck
    std::string checkComputersDeck;
    //Variable to hold the users decision on push/pull a card
    int PushOrPull;

    // Create decks for the player and computer that has 20 cards
    Deck userDeck = Deck(20);
    Deck computerDeck = Deck(20);

    // Create a side pile for the player
    SidePile userPile = SidePile();

    // Create a card variable for the player and computer
    int userCard;
    int computerCard;
    int userPulledCard;
    int userCardScore;

    // Create bool variables to determine who won
    bool userWon = false;
    bool computerWon = false;

    /*
    std::cout << "Here is the users top card: " << userDeck.RemoveCard() << "\n";
    std::cout << "Here is the computers top card: " << computerDeck.RemoveCard() << "\n";
    std::cout << "Here is the users 2nd card: " << userDeck.RemoveCard() << "\n";
    std::cout << "Here is the computers 2nd card: " << computerDeck.RemoveCard() << "\n";
    std::cout << "Here is the users 3rd card: " << userDeck.RemoveCard() << "\n";
    std::cout << "Here is the computers 3rd card: " << computerDeck.RemoveCard() << "\n";
    std::cout << "Here is the users 4th card: " << userDeck.RemoveCard() << "\n";
    std::cout << "Here is the computers 4th card: " << computerDeck.RemoveCard() << "\n";
    std::cout << "Here is the users 5th card: " << userDeck.RemoveCard() << "\n";
    std::cout << "Here is the computers 5th card: " << computerDeck.RemoveCard() << "\n";
    */

    // State the style of play
    std::cout << "The game will be played until a player is out of cards\n";

    // While both players still have cards keep playing
    while(keepPlaying) {

        // Draw a card for the user and computer
        // If their deck is empty, pull from their side pile
        if (userDeck.GetNumOfCards() <= 0) {
            std::cout << "Drew from your side pile\n";
            userCard = userPile.RemoveCard();
        }
        // If their deck is not empty, pull from their deck
        else {
            userCard = userDeck.RemoveCard();
        }
        computerCard = computerDeck.RemoveCard();

        // User peeks at their card
        std::cout << "The card you drew is a " << userCard << "\n";

        // If the user doesn't have any cards in their side deck
        if (userPile.GetNumOfCards() <= 0) {
            std::cout << "Your side pile is empty so you need to push your card or keep your current card\n";
            std::cout << "Press 2: Push your card\n";
            std::cout << "Press 3: Play your current card\n";
            std::cout << "Your choice: ";

            // Store the users response
            std::cin >> PushOrPull;

            // If the user didn't give a valid response, ask again
            while (PushOrPull != 2 && PushOrPull != 3) {
                std::cout << "\nNot a valid answer. Select 2 or 3: ";
                std::cin >> PushOrPull;
            }
        }
        // If the user's pile has the maxed amount of cards (5)
        else if (userPile.GetNumOfCards() >= 5) {
            std::cout << "Your side pile is full so you need to pull a card or keep your current card\n";
            std::cout << "Press 1: Pull out a card\n";
            std::cout << "Press 3: Play your current card\n";
            std::cout << "Your choice: ";

            // Store the users response
            std::cin >> PushOrPull;

            // If the user didn't give a valid response, ask again
            while (PushOrPull != 1 && PushOrPull != 3) {
                std::cout << "\nNot a valid answer. Select 1 or 3: ";
                std::cin >> PushOrPull;
            }
        }
        // If the user's pile has between 1-4 cards
        else {
            // Ask the user if they way to pull a card or push their original card
            std::cout << "Do you want to pull out a card from a pile or push your original card into the pile?\n";
            std::cout << "Press 1: Pull out a card\n";
            std::cout << "Press 2: Push your card\n";
            std::cout << "Press 3: Play your current card\n";
            std::cout << "Your choice: ";

            // Store the users response
            std::cin >> PushOrPull;

            // If the user didn't give a valid response, ask again
            while (PushOrPull != 1 && PushOrPull != 2 && PushOrPull != 3) {
                std::cout << "\nNot a valid answer. Select 1, 2, or 3: ";
                std::cin >> PushOrPull;
            }
        }

        // If the user selected 1 (Pull a card)
        if (PushOrPull == 1){
            // Pull a card from the side pile
            userPulledCard = userPile.RemoveCard();
            std::cout << "\nThe card you drew is a " << userPulledCard << "\n";
        }
        // If the user selected 2 (Push their card)
        else if (PushOrPull == 2) {
            // Add the card to the side pile
            userPile.AddCard(userCard);
            // Draw a new card from the deck (or pile if the deck is empty)
            // If their deck is empty, pull from their side pile
            if (userDeck.GetNumOfCards() <= 0) {
                std::cout << "Drew from your side pile\n";
                userCard = userPile.RemoveCard();
            }
            // If their deck is not empty, pull from their deck
            else {
                userCard = userDeck.RemoveCard();
            }
            userPulledCard = 0;
            std::cout << "The card you drew is a " << userCard << "\n";
        }
        // The user didn't select to push or pull a card
        // Add the card(s) value(s) to the card score variable
        userCardScore = userCard + userPulledCard;

        // State the card scores
        std::cout << "Your card score: " << userCardScore << " | Computers card score: " << computerCard << "\n";

        // Compare the Users and Computers cards
        // If the user wins
        if (userCardScore > computerCard) {
            std::cout << "You win this round\n";
            // Add the users card and the computers card to the users deck
            userDeck.AddCard(userCard);
            userDeck.AddCard(computerCard);
            // If the user selected to pull a card add their pulled card to their deck
            if (PushOrPull == 1) {
                userDeck.AddCard(userPulledCard);
            }
        }
        // If the computer wins
        else {
            std::cout << "The computer won this round\n";
            // Add the users card and the computers card to the users deck
            computerDeck.AddCard(userCard);
            computerDeck.AddCard(computerCard);
            // If the user selected to pull a card add their pulled card to their deck
            if (PushOrPull == 1) {
                computerDeck.AddCard(userPulledCard);
            }
        }

        // Tell the user how many cards they have left in their deck and pile
        std::cout << "You have " << userDeck.GetNumOfCards() << " left in your deck and " << userPile.GetNumOfCards() << " left in your side pile\n";
        // Ask if they want to know how many cards are in the computers deck
        std::cout << "Do you want to see how many cards are in the computers deck (Y/N)? ";
        std::cin >> checkComputersDeck;
        // If the user doesn't enter a valid response ask again
        while (checkComputersDeck != "Y" && checkComputersDeck != "y" && checkComputersDeck != "N" && checkComputersDeck != "n") {
            std::cout << "\nNot a valid answer. (Y/N): ";
            std::cin >> checkComputersDeck;
        }
        // If the user wants to see how many cards are in the computers deck
        if (checkComputersDeck == "Y" || checkComputersDeck == "y") {
            std::cout << "\nThe computer has " << computerDeck.GetNumOfCards() << " cards left in their deck\n";
        }

        // Check to see if the game should end
        // If the user doesn't have any cards left in their deck or pile
        if (userDeck.GetNumOfCards() == 0 && userPile.GetNumOfCards() == 0) {
            computerWon = true;
            keepPlaying = false;
        }
        // If the computer doesn't have any cards left in their deck
        else if (computerDeck.GetNumOfCards() == 0) {
            userWon = true;
            keepPlaying = false;
        }
    }

    // If the user won
    if (userWon) {
        std::cout << "The computer ran out of cards. You win!\n";
    }
    // If the computer won
    else if (computerWon) {
        std::cout << "You ran out of cards. The computer wins\n";
    }

    // Quit the program
    return 0;
}