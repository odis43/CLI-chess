#ifndef _AI_H_
#define _AI_H_

#include <vector>
#include <string>
#include "Player.h"

class AI : public Player {
private:
    virtual std::vector<int> moveCreate() = 0; // creates move info
public:
    AI(std::string colour); // constructor
    ~AI(); // destructor
};

#endif

