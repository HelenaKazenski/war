/*

Author: Helena Kazenski
email: hkazenski@butler.edu
Class: CS341
Section: 02

Honor pledge: 
I pledge that I have neither given nor received any help on this assignment. 
I pledge that all work is my own, and not copied from any other source. 

hkazenski

*/

#include <iostream>
#include <vector>
#include "deck.h"
#include "standardDeck.h"
#include "nonStandardDeck.h"
#include "war.h"

int main()
{
    StandardDeck deck1;
    StandardDeck deck2;
    deck1.printDeck();
    std::cout << "" << std::endl;

    // Required outputs
    std::cout << "Is the deck empty? " << deck1.isEmpty() << std::endl;
    std::cout << "Number of Cards: " << deck1.getNumCards() << std::endl;
    std::cout << "15th Card: ";
    deck1.displayCard(14);

    // Test shuffle
    std::cout << "\nShuffling deck...\n";
    deck1.shuffle();
    deck1.printDeck();

    // For merge: Randomly reduces the number of cards in the deck from 0-51
    int remainingCards = rand() % deck1.getNumCards();
    while (deck1.getNumCards() > remainingCards) 
    {
        deck1.dealCard(); // physically removes cards
    }

    // Test merge
    std::cout << "\nMerging deck with second deck...\n";
    deck1.mergeDecks(deck2, true);
    std::cout << "Number of Cards after merge: " << deck1.getNumCards() << std::endl;
    std::cout << "15th Card: ";
    deck1.displayCard(14);

    std::cout << "\nDeck after merge and shuffle:\n";
    deck1.printDeck();
    
    // **Game of War**

    const int NUM_GAMES = 50;
    int p1Wins = 0;
    int p2Wins = 0;
    int totalP1Score = 0;
    int totalP2Score = 0;

    for (int i = 0; i < NUM_GAMES; i++) 
    {
        GameResult result = playWar();

        if (result.winner == 1)
        {
            p1Wins++;
        }
        else
        {
            p2Wins++;
        }

        totalP1Score += result.p1Score;
        totalP2Score += result.p2Score;
    }

    std::cout << "\n" << "Player 1 wins: " << p1Wins 
              << " Player 2 wins: " << p2Wins << ".\n";

    if(p1Wins > p2Wins)
    {
        std::cout << "\n" << "Player 1 was the winner with " << p1Wins << " wins!" << std::endl;
    }
    else if(p2Wins > p1Wins)
    {
        std::cout << "\n" << "Player 2 was the winner with " << p2Wins << " wins!" << std::endl;
    }
    else
    {
        std::cout << "\n" << "It's a tie!" << std::endl;
    }

    std::cout << "\n" << "Player 1 Average Score: " << (totalP1Score / NUM_GAMES) << "\n";
    std::cout << "Player 2 Average Score: " << (totalP2Score / NUM_GAMES) << "\n";
    

    return 0;
}