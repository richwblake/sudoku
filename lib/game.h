#ifndef GAME_H
#define GAME_H

// length of rows, columns, and sub-boxes
#define MAX_N 9

#include "player.h"

class Game
{
    private:
        Player * player;
        int board[9][9];
    public:
        Game ();
        int init();
        void printBoard();
};

#endif
