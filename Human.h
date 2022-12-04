#ifndef _HUMAN_H_
#define _HUMAN_H_

#include <vector>
#include <string>
#include "Player.h"

class Human : public Player {
private:
    std::vector<int> moveCreate() override; // creates move info
public:
    Human(std::string colour); // constructor
    ~Human(); // destructor
};

#endif

