#ifndef BOARD_H
#define BOARD_H

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include "Observer.h"
using namespace std;

class Board: public Observer {
    public:
        Board();
        virtual ~Board() = 0;
        vector<vector<Tile*>> getBoardRef();
}

#endif