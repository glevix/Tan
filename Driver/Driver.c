//
// Created by Guy Levi on 10/12/2019.
//

#include "Elements.h"

char pieceToChar(Piece piece)
{
    switch (piece)
    {
        case WHITE_PAWN: return 'P';
        case WHITE_ROOK: return 'R';
        case WHITE_KNIGHT: return 'N';
        case WHITE_BISHOP: return 'B';
        case WHITE_QUEEN: return 'Q';
        case WHITE_KING: return 'k';
        case BLACK_PAWN: return 'p';
        case BLACK_ROOK: return 'r';
        case BLACK_KNIGHT: return 'n';
        case BLACK_BISHOP: return 'b';
        case BLACK_QUEEN: return 'q';
        case BLACK_KING: return 'k';
        case EMPTY: return ' ';
        default: return '\0';
    }
}

void printBoard(Board *board)
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf("%c", pieceToChar(board[j][i]))
        }
        printf("\n");
    }
    printf("\n");
}

