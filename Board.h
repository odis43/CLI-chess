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
    vector<float> theScore;
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
        //Sets board based on row and col
        void setBoard(int row, int col);
        //Sets piece to a tile
        void setPiece(int row, int col, Piece *piece);
        //Gets a piece based on its tracker
        Piece *getPiece(int tracker) const;
        //Gets a reference to the pieces
        vector<Piece*> getPiecesRef();
        //Adds and gets a player
        void addPlayer(Player *thePlayer);
        Player *getPlayer(int num) const;
        int getNumPlayers() const;
        //Gets and updates the score
        int getScore(string colour) const;
        void updateScore(string colour, float point);
        //Sets the turn
        void setPlayerTurn(string colour);
        //Gets the move and adds move to the previous moves
        Move *getMove(int num);
        void addMove(Move *theMove);
        //Gets the round
        int getRound() const;

    public:
        //Ctor and dtor for board
        Board();
        virtual ~Board() = 0;
        //Gets a reference for the board
        vector<vector<Tile*>> getBoardRef();
        //Check if the player resigned
        bool resign();
        //Setup board for setup mode
        virtual void setup() = 0;
        //Runs game
        void run(vector<string> playerNames);
        //Gets text display
        TextDisplay *getTextDisplay();
        //Notify pieces for check and checkmate
        virtual void notify() = 0;
};

#endif
