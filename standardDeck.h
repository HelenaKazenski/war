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

#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H

#include "deck.h"

#define DECK_SIZE 52

/**
 * @class StandardDeck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 * 
 */
class StandardDeck : public Deck
{
	public:
		/// Default constructor.
		StandardDeck();
		
		StandardDeck(const StandardDeck & sd);
		
		/// Default destructor.
		~StandardDeck();

		void initializeDeck();
       	bool mergeDecks(StandardDeck & other, bool doShuffle = false);
};

#endif