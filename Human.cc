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
    string input;

    while (getline(cin, input)) {
        istringstream iss(input);
        string cmd;
        iss >> cmd;
        
        if (cmd == "resign") {
            setResign(true);
            return vector<int>{-1};
        } else if (cmd == "move") {
            string intialPos;
            string destinationPos;

            iss >> intialPos;
            iss >> destinationPos;


        } else {
            cerr << "Invalid Move. Please use one of the following formats: 'resign', 'move [row][col] [row][col]'" << endl;
        }
    }
    return vector<int>();
}

