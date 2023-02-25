#ifndef BOARD_H
#define BOARD_H

#define MAX_N 9
#define MAX_SUB_N 3

class Board {
    public:
        enum Difficulty { easy, medium, hard };
        Board (Difficulty* d);
        void print();
        bool isValid();
        bool solveSudoku(int row, int col);
        bool moveIsValid(int move, int row, int col);
        Difficulty getDifficulty();
    private:
        char board[MAX_N][MAX_N];
        Difficulty difficulty;
};

#endif
