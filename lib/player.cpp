#include "player.h"

Player::Player(std::string name)
{
    this->name = name;
}

std::string Player::getName()
{
    return this->name;
}

std::string Player::sayHi()
{
    return std::string("Hi there");
}
