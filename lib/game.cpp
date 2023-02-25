#include "game.h"
#include <iostream>

Game::Game() {}

int Game::init()
{
    player = new Player(getResponse("Welcome to Sudoku, please enter your name"));
    greetPlayer();

    Board::Difficulty d;

    switch(stoi(getResponse("\nWould you like an Easy(0), Medium(1), or Hard(2) board?"))) {
        case 0:
            d = Board::easy;
            break;
        case 1:
            d = Board::medium;
            break;
        case 2:
            d = Board::hard;
            break;
    }

    board = new Board(&d);
    
    board->print();

    int resp;
    resp = stoi(getResponse("Would you like to play(0), or would you rather the computer complete the game?(1)"));
    

    if (resp) {
        // call sudokuSolver method in game
        board->solveSudoku(0,0);
    } else {
        // begin turn based game 
        std::cout << "Not implemented yet" << std::endl;
    }

    board->print();
    return 0;
}

std::string Game::getResponse(std::string query)
{
    std::cout << query << std::endl;
    std::cout << ": ";

    std::string response;
    std::cin >> response;
    return response;
}

void Game::greetPlayer()
{
    std::cout << "\nHello, " << this->player->getName() << "!" << std::endl;
}











