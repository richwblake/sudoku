#include "game.h"
#include <iostream>

Game::Game() {}

int Game::init()
{
    std::string name;
    // std::string response;
    // std::cout << "Welcome to Sudoku, please enter your name" << std::endl;
    // std::cin >> name; 

    name = getResponse(std::string("Welcome to Sudoku, please enter your name"));

    player = new Player(std::string(name));

    this->greetPlayer();

    // std::cout << ": ";
    // std::cin >> response;

    // std::cout <<  << std::endl;

    getResponse("\nWould you like an Easy(E), Medium(M), or Hard(H) board?");


    board = new Board();

    board->print();

    std::cout << board->isValid() << std::endl;
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











