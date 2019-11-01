//
// Created by Guy Levi on 11/1/2019.
//
#include <stdio.h>

#include "Human.h"
#include "Elements.h"
#include "Game.h"
#include "Driver.h"
#include "StringConstants.h"

void testGame()
{
    Game *game;
    Player p1;
    Player p2;
    TimeFormat tf = {300, 2, 20, 300, 2};

    humanPlayerInit(&p1, "Bob");
    humanPlayerInit(&p2, "Joe");

    game = newStandardGame(p1, p2, tf);
    game->state = AWAIT_MOVE;
    runGame(game);

}


int main(int argc, char** argv)
{
    printf(MSG_WELCOME);
    testGame();
}