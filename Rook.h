#ifndef ROOK
#define ROOK

//#include "Piece.h"

class Rook : public Piece {
    public:
        Rook(int color);
        ~Rook();
        void genMove(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile);
        
};

#endif
