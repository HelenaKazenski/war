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

#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <iostream>
#include <stdexcept>

/**
* @class Deck (Abstract Base Class)
*
* Defines the interface for both StandardDeck and NonStandardDeck.
*/
class Deck 
{
   public:
       Deck();
       Deck(const Deck & d);
       virtual ~Deck();

       bool isEmpty();
       int getNumCards();
       void displayCard(int i);
       void printDeck();
       bool addCard(Card c);
       void shuffle();
       virtual void initializeDeck() = 0;  // pure virtual
       void setNumCards(int n);
       Card dealCard();

   protected:
       Card* deck_;    // Heap-allocated array of Cards
       int numCards_;  // Current number of cards
};

#endif
