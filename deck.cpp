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

#include "deck.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

Deck::Deck() : deck_(nullptr), numCards_(0) {}

Deck::Deck(const Deck & d) {
   numCards_ = d.numCards_;
   deck_ = new Card[numCards_];
   for (int i = 0; i < numCards_; i++) {
       deck_[i] = d.deck_[i];
   }
}

Deck::~Deck() {
   delete[] deck_;
   deck_ = nullptr;
   numCards_ = 0;
}

bool Deck::isEmpty() {
   return numCards_ == 0;
}

int Deck::getNumCards() {
   return numCards_;
}

void Deck::displayCard(int i) {
   if (i >= 0 && i < numCards_)
       std::cout << deck_[i].print() << std::endl;
   else
       std::cout << "Error: invalid card index." << std::endl;
}

void Deck::printDeck() {
   for (int i = 0; i < numCards_; i++) {
       std::cout << deck_[i].print() << std::endl;
   }
}

bool Deck::addCard(Card c) {
   Card* newDeck = new Card[numCards_ + 1];
   for (int i = 0; i < numCards_; i++) {
       newDeck[i] = deck_[i];
   }
   newDeck[numCards_] = c;


   delete[] deck_;
   deck_ = newDeck;
   numCards_++;
   return true;
}

void Deck::shuffle() {
   srand((unsigned) time(nullptr));
   int swaps = 3 * numCards_;
   for (int i = 0; i < swaps; i++) {
       int i1 = rand() % numCards_;
       int i2 = rand() % numCards_;
       std::swap(deck_[i1], deck_[i2]);
   }
}

void Deck::setNumCards(int n) 
{
    if (n < 0) n = 0;

    if (n < numCards_) 
    {
        numCards_ = n; // just forget extras
    } 
    else if (n > numCards_) 
    {
        // Instead of adding Jokers, just ignore or throw error
        std::cerr << "Cannot increase deck size without adding cards." << std::endl;
    }
}

Card Deck::dealCard() {
   if (numCards_ == 0) {
       std::cerr << "No cards left to deal." << std::endl;
       return Card(); // Default Joker
   }
   numCards_--;
   return deck_[numCards_];
}
