//
// Created by Guy Levi on 10/11/2019.
//

#ifndef TAN_ELEMENTS_H
#define TAN_ELEMENTS_H

#define EMPTY           (0b00000000)

#define WHITE_PAWN      (0b00000001)
#define WHITE_ROOK      (0b00000010)
#define WHITE_KNIGHT    (0b00000100)
#define WHITE_BISHOP    (0b00001000)
#define WHITE_QUEEN     (0b00010000)
#define WHITE_KING      (0b00100000)

#define BLACK_PAWN      (0b10000001)
#define BLACK_ROOK      (0b10000010)
#define BLACK_KNIGHT    (0b10000100)
#define BLACK_BISHOP    (0b10001000)
#define BLACK_QUEEN     (0b10010000)
#define BLACK_KING      (0b10100000)

#define WHITE           (0)
#define BLACK           (1)

#define WHITE_TO_BLACK(x)       (x | 0b10000000)
#define BLACK_TO_WHITE(x)       (x & 0b01111111)

typedef uint8_t Piece;

typedef struct Location
{
    uint8_t x;
    uint8_t y;
} Location;

typedef struct Move
{
    Location from;
    Location to;
} Move;

typedef struct Player
{
    char name[MAX_PLAYER_NAME + 1]; //name of player
    Move (*generate)(Board); //callback for producing a move
    char (*decideDraw)(Board); //callback for deciding on whether a draw offer should be accepted
} Player;

typedef struct Board
{
    Piece board[8][8];
} Board;

typedef struct Game
{
    Board board;
    Player white;
    Player black;
    char toPlay;
    TimeFormat tf;
} Game;



#endif //TAN_ELEMENTS_H
