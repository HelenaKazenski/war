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

#include "nonStandardDeck.h"
#include <fstream>
#include <stdexcept>
#include <iostream>

NonStandardDeck::NonStandardDeck(const std::string& filename) : filename_(filename) 
{
   initializeDeck();
}

NonStandardDeck::~NonStandardDeck() 
{
   delete[] deck_;
   deck_ = nullptr;
   numCards_ = 0;
}

void NonStandardDeck::initializeDeck() 
{
   std::ifstream file("deck.txt");
   if (!file.is_open()) 
   {
       throw std::runtime_error("Could not open deck file.");
   }

   int deckSize;
   
   if (!(file >> deckSize) || deckSize <= 0)
    {
        throw std::runtime_error("Invalid deck size in file");
    }

   if (deck_ != nullptr) 
    {
        delete[] deck_;
        deck_ = nullptr;
    }

   deck_ = new Card[deckSize];
   numCards_ = deckSize;

   int suit, face;
   for (int i = 0; i < deckSize; i++) 
   {
       if (!(file >> suit >> face)) 
       {
           throw std::runtime_error("Error: Invalid deck file format");
       }

       if (suit < 0 || face < 0) 
        {
            throw std::runtime_error("Error: Negative card values.");
        }

       deck_[i].initialize(suit, face);
   }

   file.close();
}