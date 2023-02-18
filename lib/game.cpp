#include "game.h"
#include <iostream>

Game::Game()
{
    for (int i = 0; i < MAX_N; ++i)
        for (int j = 0; j < MAX_N; ++j)
            board[i][j] = 0; 
}

int Game::init()
{
    std::string name;
    std::cout << "Welcome to Sudoku, please enter your name" << std::endl;
    std::cin >> name; 

    player = new Player(std::string(name));

    printBoard();

    return 0;
}

void Game::printBoard()
{
    std::cout << "-------------------------" << std::endl;
    for (int i = 0; i < MAX_N; ++i) {
        std::cout << "|";
        for (int j = 0; j < MAX_N; ++j) {
            std::cout << " " << board[i][j];
            if ((j + 1) % 3 == 0)
                std::cout << " |";
        }
        if ((i + 1) % 3 == 0)
            std::cout << "\n-------------------------" << std::endl;
        else
            std::cout << std::endl;
    }
}

