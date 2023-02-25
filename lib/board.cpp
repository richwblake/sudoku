#include "board.h"
#include <iostream>

Board::Board(Difficulty* d)
{
    char easy[MAX_N][MAX_N] = {
        {'6', '2', '4', '8', '3', '_', '1', '_', '7'},
        {'_', '1', '8', '9', '2', '_', '3', '6', '5'},
        {'_', '_', '_', '7', '6', '_', '_', '4', '_'},
        {'_', '_', '_', '_', '8', '_', '9', '_', '1'},
        {'_', '_', '9', '_', '_', '6', '_', '_', '_'},
        {'1', '4', '_', '_', '_', '_', '5', '8', '_'},
        {'9', '6', '_', '_', '_', '8', '_', '_', '3'},
        {'_', '_', '_', '_', '1', '_', '_', '5', '_'},
        {'_', '7', '1', '_', '4', '3', '_', '_', '_'}
    };

    for (int i = 0; i < MAX_N; ++i)
        for (int j = 0; j < MAX_N; ++j)
            board[i][j] = easy[i][j];

    this->difficulty = *d;
}

void Board::print()
{
    std::cout << "    1 2 3   4 5 6   7 8 9\n";
    std::cout << "  -------------------------" << std::endl;
    for (int i = 0; i < MAX_N; ++i) {
        std::cout << char('A' + i) <<" |";
        for (int j = 0; j < MAX_N; ++j) {
            char dig = board[i][j] == '_' ? '_' : board[i][j];
            std::cout << " " << dig;
            if ((j + 1) % 3 == 0)
                std::cout << " |";
        }
        if ((i + 1) % 3 == 0)
            std::cout << "\n  -------------------------" << std::endl;
        else
            std::cout << std::endl;
    }
}

bool Board::isValid()
{
    // store frequency of digit appearance in each row and column
    // indicies of arrays represent a given digit (1-9), converted to an index. Value of each index represents
    // the frequency of that digit in a row or column
    int rowFreq[MAX_N];
    int colFreq[MAX_N];

    // stores length/height of grid
    int n = MAX_N;
    int sbLength = n / MAX_SUB_N;

    // store each sub-box in an array of arrays
    int subs[9][9];

    for (int i = 0; i < n; ++i) {
        // set all values in row and col to 0
        rowFreq[i] = colFreq[i] = 0;
        for (int j = 0; j < n; ++j) {
            // initialize each sub-box array in subs to 0
            subs[i][j] = 0;
        }
    }

    // check rows, colums, and sub-boxes for repeat digits
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] != '_') {
                // store current digit converted to index in row
                int currentRowDigitIndex = (board[i][j] - '0') - 1;
                // See proof at top of class definition
                int currentSubBoxIndex = ((i / sbLength) * sbLength) + j / sbLength;

                // if the current row contains more than one instance of any digit 
                // after incrementation, board is invalid
                if (++rowFreq[currentRowDigitIndex] > 1 || ++subs[currentSubBoxIndex][currentRowDigitIndex] > 1) {
                    return false;
                }
            } 

            if (board[j][i] != '_') {
                // store current digit converted to index in column
                int currentColDigitIndex = (board[j][i] - '0') - 1;

                // if the current col contains more than one instance of any digit 
                // after incrementation, board is invalid
                if (++colFreq[currentColDigitIndex] > 1) {
                    return false;
                }
            }
        }
        // clear row and col frequency arrays to prepare for the next row and col
        for (int z = 0; z < n; ++z) {
            rowFreq[z] = colFreq[z] = 0;
        }
    }
    return true;
}

bool Board::moveIsValid(int move, int row, int col)
{
    // check row to see if move is already there
    for (int i = 0; i < MAX_N; ++i)
        if (board[row][i] != '_') {
            if (board[row][i] - '0' == move)
                return false;
        }
    
    // check column to see if move is already there
    for (int i = 0; i < MAX_N; ++i)
        if (board[i][col] != '_')
            if (board[i][col] - '0' == move)
                return false;


    // Define bounds of sub-box where move resides
    int rowEnd = 3 * (row / 3) + 2;
    int colEnd = 3 * (col / 3) + 2;

    // iterate through sub-box indicies to see if move is already there
    for (int rowBegin = 3 * (row / 3); rowBegin <= rowEnd; ++rowBegin)
        for (int colBegin = 3 * (col / 3); colBegin <= colEnd; ++colBegin)
            if (board[rowBegin][colBegin] != '_')
                if (board[rowBegin][colBegin] - '0' == move)
                    return false;

    // move is valid
    return true;
}

bool Board::solveSudoku(int row, int col)
{
    // BASE CASES
    // If reached the end of the grid and grid is valid, return true
    // If reached the end and grid is invalid, no solution exists return false
    if (row == MAX_N - 1 && col == MAX_N) {
        if (isValid()) {
            std::cout << "Solution found" << std::endl;
            print();    
            return true;
        } else {
            return false;
        }
    }

    // if col is greater than 8, move pointers to next row
    if (col > 8) {
        col = 0;
        ++row;
    }

    // if grid contains number in current position, recur to next position
    if (board[row][col] != '_') {
        return solveSudoku(row, col + 1);
    }
   
    // loop through values 1-9, and try each value in the current spot on grid
    // only try to make move on empty position
    // if the move is valid, play move and recur to next position
    // if move is invalid, continue loop and try next position
    for (int i = 1; i < MAX_N + 1; ++i) {
        if (moveIsValid(i, row, col)) {
            board[row][col] = char(i + 48);

            if (solveSudoku(row, col + 1))
                return true;

            board[row][col] = '_';
        }
    }
    return false;
}

Board::Difficulty Board::getDifficulty()
{
    return this->difficulty;
}
