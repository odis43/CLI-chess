#ifndef PAWN
#define PAWN

//#include "Piece.h"

class Pawn : public Piece {
    bool isPromoted;
    public:
        Pawn(int color);
        ~Pawn();
        void genMove(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile);
        void Promoted();
};

#endif
