#ifndef KNIGHT
#define KNIGHT

//#include "Piece.h"

class Knight : public Piece {
    public:
        Knight(int color);
        ~Knight();
        void genMove(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile);
    
};

#endif
