#ifndef KNIGHT
#define KNIGHT

//#include "Piece.h"
#include "Tile.h"

class Knight : public Piece {
    public:
        Knight(std::string colour);
        ~Knight();
        void genMove(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile);
    
};

#endif
