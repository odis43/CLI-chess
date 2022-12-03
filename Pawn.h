#ifndef PAWN
#define PAWN


#include "Piece.h"
#include "Tile.h"

class Pawn : public Piece {
    bool isPromoted;
    bool hasTwoStepped;
    public:
        Pawn(std::string colour);
        ~Pawn();
        void genMoves(std::vector<std::vector<Tile*>> board, Tile *tile, int row, int col);
        void setStatus();
        bool getStatus() override;
        void print() override;
        void castlingStatus() override;
        bool getCastlingStatus() override;
};

#endif
