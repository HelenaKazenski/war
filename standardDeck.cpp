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

#include "standardDeck.h"

StandardDeck::StandardDeck() 
{
   deck_ = new Card[DECK_SIZE];
   initializeDeck();
}

StandardDeck::StandardDeck(const StandardDeck & sd) : Deck(sd) {}

StandardDeck::~StandardDeck() 
{
   delete[] deck_;
   deck_ = nullptr;
   numCards_ = 0;
}

void StandardDeck::initializeDeck() 
{
   delete[] deck_;
   deck_ = new Card[DECK_SIZE];
   numCards_ = DECK_SIZE;


   int cardIndex = 0;
   for (int suit = 1; suit <= 4; suit++) 
   {
       for (int face = 1; face <= 13; face++) 
       {
           deck_[cardIndex].initialize(suit, face);
           cardIndex++;
       }
   }
}

bool StandardDeck::mergeDecks(StandardDeck & other, bool doShuffle) 
{
   int totalCards = numCards_ + other.numCards_;
   if (totalCards > DECK_SIZE) 
   {
       totalCards = DECK_SIZE; // Caps at 52
   }

   Card* newDeck = new Card[totalCards];
   for (int i = 0; i < numCards_; i++) 
   {
       newDeck[i] = deck_[i];
   }
   for (int j = 0; j < other.numCards_ && (numCards_ + j) < DECK_SIZE; j++) 
   {
       newDeck[numCards_ + j] = other.deck_[j];
   }

   delete[] deck_;
   deck_ = newDeck;
   numCards_ = totalCards;

   if (doShuffle) shuffle();
   return true;
}