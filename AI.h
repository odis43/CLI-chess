#ifndef _AI_H_
#define _AI_H_

#include <vector>
#include <string>
#include "Player.h"

class AI : public Player {
public:
    AI(std::string colour);
    ~AI();

    virtual std::vector<int> moveCreate() = 0;

};

#endif

