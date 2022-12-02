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
        void genMoves(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile);
        void setStatus();
        bool getStatus();
        void print() override;

        void castlingStatus() override;
        bool getCastlingStatus() override;
};

#endif
