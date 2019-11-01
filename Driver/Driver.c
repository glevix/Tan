//
// Created by Guy Levi on 10/12/2019.
//
#include <stdio.h>

#include "Driver.h"
#include "Game.h"

char pieceToChar(Piece piece)
{
    switch (piece)
    {
        case WHITE_PAWN:    return 'P';
        case WHITE_ROOK:    return 'R';
        case WHITE_KNIGHT:  return 'N';
        case WHITE_BISHOP:  return 'B';
        case WHITE_QUEEN:   return 'Q';
        case WHITE_KING:    return 'K';
        case BLACK_PAWN:    return 'p';
        case BLACK_ROOK:    return 'r';
        case BLACK_KNIGHT:  return 'n';
        case BLACK_BISHOP:  return 'b';
        case BLACK_QUEEN:   return 'q';
        case BLACK_KING:    return 'k';
        case EMPTY:         return ' ';
        default:            return '\0';
    }
}

void printBoard(Board *board)
{
    for (int i = 0; i <= 7; i++)
    {
        printf("%c\t|", '8' - i);
        for (int j = 0; j <= 7; j++)
        {
            printf("%c|", pieceToChar(board->pieces[j][i]));
        }
        printf("\n");
    }
    printf(" \t ");
    for (int i = 0; i <= 7; i++)
    {
        printf("%c ", 'a' + i);
    }
    printf("\n");
}

void registerMove(Game *game, Move move)
{
//todo
}

void runGame(Game* game)
{
    while (game->state == AWAIT_MOVE)
    {
        Move move = (game->board.toPlay == WHITE) ?
                game->white.generate(&game->board) : game->black.generate(&game->board);
        registerMove(game, move);
    }
}
