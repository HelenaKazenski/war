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

#include "card.h"
#include <iostream>

std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};
std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                            "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card() 
{
    suitVal_ = 0;  // No Suit
    faceVal_ = 0;  // Joker
}

Card::Card(int suit, int face) 
{
    suitVal_ = suit;
    faceVal_ = face;
}

Card::~Card() 
{}

void Card::initialize(int suit, int face) 
{
    suitVal_ = suit;
    faceVal_ = face;
}

std::string Card::getSuit() 
{
    return SUIT[suitVal_];
}

std::string Card::getFace() 
{
    return FACE[faceVal_];
}


// Prints the card's full name (ex. "Ace of Spades")
std::string Card::print() 
{
    return FACE[faceVal_] + " of " + SUIT[suitVal_];
}