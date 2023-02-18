#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
    protected:
        std::string name;
    public:
        Player (std::string name);
        std::string getName();
        std::string sayHi();
};

#endif
