#ifndef GAME_H
#define GAME_H

// length of rows, columns, and sub-boxes
#define MAX_N 9

#include "player.h"
#include "board.h"

class Game
{
    private:
        Player * player;
        Board * board;
    public:
        Game ();
        int init();
        void greetPlayer();
        std::string getResponse(std::string query);
};

#endif
