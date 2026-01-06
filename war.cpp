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

#include "war.h"
#include <vector>

GameResult playWar()
{
    Deck* warDeck = new StandardDeck();
    warDeck->shuffle();

    Deck* p1Deck = new StandardDeck();
    Deck* p2Deck = new StandardDeck();
    p1Deck->setNumCards(0);
    p2Deck->setNumCards(0);

    for (int i = 0; i < 52; i++) 
    {
        if (warDeck->isEmpty()) break;  // Safety check
        if (i % 2 == 0)
            p1Deck->addCard(warDeck->dealCard());
        else
            p2Deck->addCard(warDeck->dealCard());
    }

    Card battlegroundTop;
    bool hasTop = false;
    bool p1Turn = true;

    std::vector<Card> battleground;

    for (int turn = 0; turn < 1000 && !p1Deck->isEmpty() && !p2Deck->isEmpty(); turn++)
    {
        Card played = p1Turn ? p1Deck->dealCard() : p2Deck->dealCard();
        battleground.push_back(played);

        if (hasTop && played.getFace() == battlegroundTop.getFace()) 
        {
            if (p1Turn) 
            {
                for (size_t i = 0; i < battleground.size(); i++)
                {
                    p1Deck->addCard(battleground[i]);
                }
            } 
            else 
            {
                for (size_t i = 0; i < battleground.size(); i++)
                {
                    p2Deck->addCard(battleground[i]);
                }
            }
            battleground.clear();
            hasTop = false;
        } 
        else 
        {
            battlegroundTop = played;
            hasTop = true;
            p1Turn = !p1Turn;
        }
    }

    GameResult result;
    result.p1Score = p1Deck->getNumCards();
    result.p2Score = p2Deck->getNumCards();
    result.winner = (result.p1Score > result.p2Score) ? 1 : 2;

    delete warDeck;
    delete p1Deck;
    delete p2Deck;

    return result;
}