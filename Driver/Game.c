//
// Created by Guy Levi on 10/12/2019.
//

#include <stdlib.h>
#include<time.h>

#include "Elements.h"

Game *newGame(Player p1, Player p2, Board *board, int white, int toPlay, TimeFormat tf)
{
    Game *game = malloc(sizeof(Game));
    if (white == RANDOM)
    {
        srand(time(0));
        white = rand() % 2 ? PLAYER1 : PLAYER2;
    }
    switch (white)
    {
        case PLAYER1:
            game->white = p1;
            game->black = p2;
            break;
        case PLAYER2:
            game->white = p2;
            game->black = p1;
            break;
        default:
            return 0;
    }
    switch (toPlay)
    {
        case WHITE:
            game->toPlay = WHITE;
            break;
        case BLACK:
            game->toPlay = BLACK;
            break;
        default:
            return 0;
    }
    if (board)
        memcpy(board, &(game->board), sizeof(Board));
    else
        initBoard(&(game->board));
    game->tf = tf;
    return game;
}

Game *newStandardGame(Player p1, Player p2, TimeFormat tf)
{
    return newGame(p1, p2, 0, RANDOM, WHITE, tf);
}

void initBoard(Board *board)
{
    for (int i = 0; i < 8; i++)
    {
        board[i][1] = WHITE_PAWN;
        board[i][6] = BLACK_PAWN;
    }
    for (int i = 0; i < 3; i++)
    {
        Piece white = WHITE_ROOK << i;
        Piece black = WHITE_TO_BLACK(white);
        board[i][0] = white;
        board[7 - i][0] = white;
        board[i][7] = black;
        board[7 - i][7] = black;
    }
    board[3][0] = WHITE_QUEEN;
    board[4][0] = WHITE_KING;
    board[3][7] = BLACK_QUEEN;
    board[4][7] = BLACK_KING;
}