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

#define AWAIT_MOVE                  (0)
#define WIN_WHITE                   (1)
#define WIN_BLACK                   (2)
#define DRAW_STALEMATE              (3)
#define DRAW_INSUFFICIENT_MATERIAL  (4)
#define DRAW_REPETITION             (5)
#define DRAW_FIFTY                  (6)

#define WHITE_TO_BLACK(x)       (x | 0b10000000)
#define BLACK_TO_WHITE(x)       (x & 0b01111111)


#define MAX_PLAYER_NAME (30)

typedef unsigned char uint8_t;

typedef uint8_t Piece;

typedef struct Board
{
    Piece pieces[8][8];
    char toPlay;
} Board;

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
    Move (*generate)(Board* board); //callback for producing a move
    char (*decideDraw)(Board* board); //callback for deciding on whether a draw offer should be accepted
} Player;

typedef struct TimeFormat
{
    unsigned int startingTimeSeconds;
    unsigned int standardIncrement;
    unsigned int timeControl;
    unsigned int timeControlSeconds;
    unsigned int timeControlIncrement;
} TimeFormat;

typedef struct Game
{
    Board board;
    Player white;
    Player black;
    TimeFormat tf;
    char state;
} Game;



#endif //TAN_ELEMENTS_H
