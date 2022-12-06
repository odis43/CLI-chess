#ifndef PIECE_H
#define PIECE_H

#include<iostream>
#include<map>
#include<vector>
#include "Subject.h"
using namespace std;

class Tile;
class Board;

class Piece: public Subject {
    Tile* tile;
    //colour can be "white" or "black"
    string colour;
    int tracker;
    bool notMoved;
    int val;
    map<Tile*, int> validMoves;
    Board* theBoard;

    //Generates the valid moves for a piece
    virtual void genMoves(vector<vector<Tile*>> board, Tile* tile, int row, int col) = 0;
    //Prints out the specific piece
    virtual void print() = 0;
    
    virtual void castlingStatus() = 0;
    virtual bool getCastlingStatus() = 0;
    virtual bool getStatus();

    public:
        //Ctor and dtor for Piece
        Piece(string colour, int val);
        virtual ~Piece();

        //Gets and sets tile
        Tile* getTile();
        void setTile(Tile* tile);
        //Gets colour
        string getColour();
        //Gets and sets tracker
        int getTracker();
        void setTracker(int num);
        //Gets and sets if the piece has moved
        bool getNotMoved();
        void setNotMoved(bool b);
        //Gets value of piece
        int getVal();
        //Checks if move is valid
        int isValidMove(Tile* tile);
        //Gets valid moves
        map<Tile*, int> getValidMoves();
        //Creates and updates valid moves
        void createValidMoves();
        void updateValidMoves(Tile* tile, int num);
        //Gets if the piece can capture
        Tile* getCapture();
        //Gets if the piece can check
        Tile* getCheck();
        //Prints the piece
        void printThePiece();
        //Gets and sets the board that the piece is on
        Board* getBoard();
        void setBoard(Board* board);
        //Gets a random move for AI
        Tile* getRandomMove();
        //Notify observers
        void notifyObservers();
        //Creates and receive unique status
        void createUniqueStatus();
        bool receiveUniqueStatus();
};

#endif
