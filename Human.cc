#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include "Human.h"
#include "Tile.h"

using namespace std;

Human::Human(string colour) : Player{colour} {}

Human::~Human() {}

vector<int> Human::moveCreate() {
    vector<vector<Tile *>> curBoard = getBoard()->getBoardRef();
}

