#ifndef PIECE_H
#define PIECE_H

#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include "Subject.h"
using namespace std;

class Tile;
class Board;

class Piece: public Subject {
    Tile* tile;
    string colour;
    int tracker;
    bool notMoved;
    int val;
    unordered_map<Tile*, int> validMoves;
    Board* theBoard;

    virtual void genMoves(vector<vector<Tile*>> board, Tile* tile, int row, int col) = 0;
    virtual void print() = 0;

    virtual void castlingStatus() = 0;
    virtual bool getCastlingStatus() = 0;

    virtual bool getStatus();

    public:
        Piece(string colour, int val);
        virtual ~Piece();

        Tile* getTile();
        void setTile(Tile* tile);
        string getColour();
        int getTracker();
        void setTracker(int num);
        int getVal();
        int isValidMove(Tile* tile);
        void printThePiece();
        unordered_map<Tile*, int>getValidMoves();
        void createValidMoves();
        void updateValidMoves(Tile* tile, int num);
        void setNotMoved(bool b);
        bool getNotMoved();
        Board* getBoard();
        void setBoard(Board* board);
        Tile* getRandomMove();
        void notifyObservers();
        void createUniqueStatus();
        bool receiveUniqueStatus();
};

#endif
