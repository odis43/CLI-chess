#ifndef KNIGHT
#define KNIGHT

//#include "Piece.h"
#include "Tile.h"
#include "Piece.h"
class Knight : public Piece {
    public:
        Knight(std::string colour);
        ~Knight();
        void genMoves(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile);
        void print() override;

        void castlingStatus() override;
        bool getCastlingStatus() override;
};

#endif
