//
// Created by Guy Levi on 10/12/2019.
//

#ifndef TAN_GAME_H
#define TAN_GAME_H

#include "Elements.h"

#define RANDOM          (0)
#define PLAYER1         (1)
#define PLAYER2         (2)

/**
 * Initiates a new game structure to a standard game
 * @param p1
 * @param p2
 * @param tf The time format to use
 * @return
 */
Game *newStandardGame(Player p1, Player p2, TimeFormat tf);

/**
 * Initiates a new game structure
 *
 * @param p1 Player 1
 * @param p2 Player 2
 * @param board Optional initial position. Pass null to start with a standard initial board
 * @param white Defines which player is white. PLAYER1, PLAYER2 or RANDOM.
 * @param toPlay Defines who plays the upcoming turn, WHITE or BLACK.
 * @param tf The time format to use
 * @return
 */
Game *newGame(Player p1, Player p2, Board *board, int white, int toPlay, TimeFormat tf);

/**
 * Initializes a standard opening board
 *
 * @param board Pointer to board to be initialized
 */
void initBoard(Board *board);


/**
 * Starts gameplay
 *
 * @param game Initiated game structure
 * @return
 */
void startGame(Game* game);

#endif //TAN_GAME_H
