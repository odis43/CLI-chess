#ifndef _HUMAN_H_
#define _HUMAN_H_

#include <vector>
#include <string>
#include "Player.h"

class Human : public Player {
public:
    Human(std::string colour);
    ~Human();

    std::vector<int> moveCreate() override;

};

#endif

