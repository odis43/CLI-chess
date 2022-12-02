#include<sstream>
#include<iostream>
#include<string>
#include "Board.h"
#include "Chess.h"
using namespace std;

int main(){
    string s;
    Chess *theChess = new Chess();
    auto chessGame = make_unique<Chess>(theChess);
    while (getline(cin, s)) {
        string command;
        istringstream ss{s};
        ss >> command;
        if (command == "game") {
            vector<string> playerNames;
            string playerName;
            while (ss >> playerName){
                playerNames.emplace_back(playerName);
            }
            chessGame->run(playerNames);
        } else if (command == "setup") {
            chessGame->setup();
        } else if (command == "quit") {
            break;
        }
    }
    chessGame->printScore();
}
