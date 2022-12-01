#ifndef _AI_H_
#define _AI_H_

#include <vector>
#include <string>
#include "Player.h"

class AI : public Player {
public:
    AI(std::string colour); // constructor
    ~AI(); // destructor

    virtual std::vector<int> moveCreate() = 0; // creates move
};

#endif

