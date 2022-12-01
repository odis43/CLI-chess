#ifndef _LEVEL1_H_
#define _LEVEL1_H_

#include <vector>
#include <string>
#include "AI.h"

class Level1 : public AI {
public:
    Level1(std::string colour);
    ~Level1();

    std::vector<int> moveCreate() override;

};

#endif

