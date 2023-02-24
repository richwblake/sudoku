#include "board.h"
#include <iostream>

Board::Board()
{
    char easy[MAX_N][MAX_N] = {
        {'5', '3', '_', '_', '7', '_', '_', '_', '_'},
        {'6', '_', '_', '1', '9', '5', '_', '_', '_'},
        {'_', '9', '8', '_', '_', '_', '_', '6', '_'},
        {'8', '_', '_', '_', '6', '_', '_', '_', '3'},
        {'4', '_', '_', '8', '_', '3', '_', '_', '1'},
        {'7', '_', '_', '_', '2', '_', '_', '_', '6'},
        {'_', '6', '_', '_', '_', '_', '2', '8', '_'},
        {'_', '_', '_', '4', '1', '9', '_', '_', '5'},
        {'_', '_', '_', '_', '8', '_', '_', '7', '9'}
    };

    for (int i = 0; i < MAX_N; ++i)
        for (int j = 0; j < MAX_N; ++j)
            board[i][j] = easy[i][j];
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
