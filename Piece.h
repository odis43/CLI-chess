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
    string colour;
    int tracker;
    bool notMoved;
    int val;
    map<Tile*, int> validMoves;
    Board* theBoard;

    virtual void genMoves(vector<vector<Tile*>>, Tile* tile, int row, int col) = 0;
    virtual void print() = 0;

    virtual void uniqueStatus() = 0;
    virtual bool getUniqueStatus() = 0;

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
        map<Tile*, int>getValidMoves();
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
