#ifndef PIECE_H
#define PIECE_H

#include<iostream>
#include<map>
#include<vector>
#include "subject.h"
using namespace std;

class Tile;
class Board;

class Piece: public Subject {
    Tile *tile;
    string colour;
    int val;
    map<Tile*, int> validMoves;
    Board *board;

    virtual void genMoves(vector<vector<Tile*>>, Tile *tile, int row, int col) = 0;
    virtual void print() = 0;

    public:
        Piece(string colour, int val);
        virtual ~Piece();

        Tile *getTile();
        void setTile(Tile *tile);
        string getColour();
        int getVal();
        int isValidMove(Tile* tile);
        map<Tile*, int>getValidMoves();
        Board *getBoard();
        void setBoard(Board *b);
        void notifyObservers();
};

#endif
