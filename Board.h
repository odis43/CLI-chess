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
    vector<unique_ptr<Player>> players;
    //Previous moves
    vector<unique_ptr<Move>> prevMoves;
    //Tracks number of rounds
    int round;
    //Tracks who's turn 
    int playerTurn;
    //Tracks if the game is in play
    bool inPlay;
    //Maps the player to their score
    map<string, int> score;
    //Resets the board
    void resetGame();
    //Starts game by initializing board
    virtual void startGame() = 0;
    //Check if game is done
    virtual bool gameOver() = 0;
    //Check if game is in a valid state
    virtual bool gameState() = 0;
    //Generates players
    virtual void genPlayers(vector<string>playerNames) = 0;

    protected:
        void setBoard(int row, int col);
        void setPiece(int row, int col, Piece *piece);
        Piece *getPiece(string colour, string name);
        void removePiece(int row, int col);
        vector<Piece*> getRefPieces();
        void addPlayer(Player *player);
        Player *getPlayer(int num);
        void updateScore(string name);
        int getScore(string name);
        void setPlayerTurn(string colour);
        void addMove(Move *move);
        Move *getMove(int num);
        int getRound();

    public:
        Board();
        virtual ~Board() = 0;
        vector<vector<Tile*>> getBoardRef();
        bool resign();
        virtual void setup() = 0;
        void run(vector<string> playerNames, bool canUndo);
        void undo();
        TextDisplay *getTextDisplay();
        virtual void notify() = 0;
};

#endif
