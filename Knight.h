#ifndef KNIGHT
#define KNIGHT

//#include "Piece.h"
#include "Tile.h"
#include "Piece.h"
class Knight : public Piece {
    public:
        Knight(std::string colour);
        ~Knight();
        void genMoves(std::vector<std::vector<Tile*>> board, Tile *tile, int row, int col);
        void print() override;

        void castlingStatus();
        bool getCastlingStatus();
};

#endif
