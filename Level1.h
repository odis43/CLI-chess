#ifndef _LEVEL1_H_
#define _LEVEL1_H_

#include <vector>
#include <string>
#include "AI.h"

class Level1 : public AI {
private:
    std::vector<int> moveCreate() override; // creates move info
public:
    Level1(std::string colour); // constructor
    ~Level1(); // destructor
};

#endif

