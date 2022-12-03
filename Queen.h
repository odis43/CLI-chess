#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
using namespace std;

class Queen: public Piece {
    public:
        Queen(string colour);
        ~Queen();

        void print();
        void genMoves(vector<vector<Tile*>> board, Tile *tile, int row, int col);
        bool getStatus() override;
        void castlingStatus() override;
        bool getCastlingStatus() override;
};

#endif
