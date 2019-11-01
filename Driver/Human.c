//
// Created by Guy Levi on 11/1/2019.
//

#include <string.h>
#include <stdio.h>

#include "Driver.h"
#include "Human.h"
#include "StringConstants.h"

#define MAX_MOVE_USER_INPUT 6

int parseMoveInput(Move *move)
{
    char input[MAX_MOVE_USER_INPUT];
    char *c;
    fgets(input, MAX_MOVE_USER_INPUT, stdin);
    if (strlen(input) != 5)
        return 0;
    c = input;
    if (*c < 'a' || *c > 'h')
        return 0;
    move->from.x = 1u << (unsigned char)('h' - *c);
    c++;
    if (*c < '1' || *c > '8')
        return 0;
    move->from.y = 1u << (unsigned char)(*c - '1');
    c++;
    if (*c != ',')
        return 0;
    c++;
    if (*c < 'a' || *c > 'h')
        return 0;
    move->to.x = 1u << (unsigned char)('h' - *c);
    c++;
    if (*c < '1' || *c > '8')
        return 0;
    move->to.y = 1u << (unsigned char)(*c - '1');
    return 1;
}

Move generate(Board *board)
{
    Move move;
    memset(&move, 0, sizeof(move));
    int gotMove = 0;
    printBoard(board);
    while (!gotMove)
    {
        fflush(stdin);
        printf(PROMPT_ENTER_MOVE);
        gotMove = parseMoveInput(&move);
    }
    return move;
}

void humanPlayerInit(Player* player, char* name)
{
    strcpy(player->name, name); //todo unsafe
    player->generate = &generate;

}