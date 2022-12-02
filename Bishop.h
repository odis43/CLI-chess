#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
using namespace std;

class Bishop: public Piece {
    public:
        Bishop(string colour);
        ~Bishop();

        void print();
        void genMoves(vector<vector<Tile*>> board, Tile *tile, int row, int col);

        void castlingStatus() override;
        bool getCastlingStatus() override;
};

#endif
