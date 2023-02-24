#ifndef BOARD_H
#define BOARD_H

#define MAX_N 9
#define MAX_SUB_N 3

class Board {
    private:
        char board[MAX_N][MAX_N];
    public:
        Board ();
        void print();
        bool isValid();
};

#endif
