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

#ifndef GAME_H
#define GAME_H

#include "standardDeck.h"

struct GameResult 
{
    int winner; // 1 for Player 1, 2 for Player 2
    int p1Score;
    int p2Score;
};

GameResult playWar();

#endif