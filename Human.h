#ifndef _HUMAN_H_
#define _HUMAN_H_

#include <vector>
#include "Player.h"

class Human : public Player {
public:
    Human(int side);
    ~Human();

    std::vector<int> moveCreate() override;

};

#endif

