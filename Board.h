#ifndef BOARD_H
#define BOARD_H

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<memory>
#include "Observer.h"
using namespace std;

class Piece;
class Tile;
class Player;
class TextDisplay;
class Move;

class Board: public Observer {
    //Board
    vector<vector<unique_ptr<Tile>>> theBoard;
    //Pieces in game
    vector<unique_ptr<Piece>> thePieces;
    //Players
    vector<unique_ptr<Player>> thePlayers;
    //Previous moves
    vector<unique_ptr<Move>> prevMoves;
    //Tracks number of rounds
    int round;
    //Tracks who's turn 
    string playerTurn;
    //Tracks if the game is in play
    bool inPlay;
    //Text Display
    unique_ptr<TextDisplay> theTextDisplay;
    //Maps the player to their score
    map<string, int> theScore;
    //Resets the board
    void resetGame();
    //Starts game by initializing board
    virtual void initGame() = 0;
    //Check if game is done
    virtual bool gameOver() = 0;
    //Check if game is in a valid state
    virtual int checkState() = 0;
    //Generates players
    virtual void createPlayers(vector<string> playerNames) = 0;

    protected:
        void setBoard(int row, int col);
        void setPiece(int row, int col, Piece *piece);
        Piece *getPiece(int tracker) const;
        vector<Piece*> getPiecesRef() const;
        void addPlayer(Player *thePlayer);
        Player *getPlayer(int num) const;
        int getNumPlayers() const;
        void updateScore(string colour, int point);
        int getScore(string colour) const;
        void setPlayerTurn(string colour);
        void addMove(Move *theMove);
        Move *getMove(int num);
        int getRound() const;

    public:
        Board();
        virtual ~Board() = 0;
        vector<vector<Tile*>> getBoardRef() const;
        bool resign();
        virtual void setup() = 0;
        void run(vector<string> playerNames);
        TextDisplay* getTextDisplay();
        virtual void notify() = 0;
};

#endif
