#ifndef KING_H
#define KING_H


#include "Piece.h"

using namespace std;

class King: public Piece {
    public:
        bool castle = 0;
        King(string colour);
        ~King();
       

        void print();
        void genMoves(vector<vector<Tile*>> board, Tile *tile, int row, int col);
        void castlingStatus() override;
        bool getCastlingStatus() override;

};

#endif
