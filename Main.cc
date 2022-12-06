#include<sstream>
#include<iostream>
#include<string>
#include "Board.h"
#include <memory>
#include "Chess.h"
using namespace std;

int main(){
    bool setupDone = false;
    string s;
    Chess *game = new Chess();
    auto theGame = unique_ptr<Chess>{game};
    cout << "Welcome to Chess!" << endl;
    cout << "Please enter 'game human human', 'setup', or 'quit'" << endl;
    while (getline(cin, s)) {
        string command;
        istringstream iss{s};
        iss >> command;
        if (command == "game") {
            vector<string> playerNames;
            string playerName;
            while (iss >> playerName){
                playerNames.emplace_back(playerName);
            }

            if(playerNames.size() != 2 && setupDone == false) {
                cerr << "ERROR: please enter two players!" << endl;
            } else {
                theGame->run(playerNames);
            }
        } else if (command == "setup") {
            setupDone = true;
            bool done = theGame->setup();
            if(done) {
            vector<string> playerNames;
            string playerName;
            while (iss >> playerName){
                playerNames.emplace_back(playerName);
            }

            if(playerNames.size() != 2 && setupDone == false) {
                cerr << "ERROR: please enter two players!" << endl;
            } else {
                theGame->run(playerNames);
            }   
            }
        } else if (command == "quit") {
            break;
        }
    }

    if(theGame) {
        theGame->printScore();
    }

}
