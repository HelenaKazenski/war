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

#ifndef NONSTANDARD_DECK_H
#define NONSTANDARD_DECK_H

#include "deck.h"
#include <string>

/**
* @class NonStandardDeck
*
* Inherits from Deck, loads a custom deck from file.
*/

class NonStandardDeck : public Deck 
{
   public:
       NonStandardDeck(const std::string& filename);
       ~NonStandardDeck();


       void initializeDeck();


   private:
       std::string filename_;
};

#endif