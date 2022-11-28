#ifndef KING_H
#define KING_H

#include "Piece.h"
using namespace std;

class King: public Piece {
    public:
        King(string colour);
        ~King();

        void print();
        void genMoves(vector<vector<Tile*>> board, Tile *tile, int row, int col);
};

#endif
