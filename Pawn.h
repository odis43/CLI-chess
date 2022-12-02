#ifndef PAWN
#define PAWN


#include "Piece.h"
#include "Tile.h"

class Pawn : public Piece {
    bool isPromoted;
    bool hasTwoStepped;
    public:
        Pawn(std::string color);
        ~Pawn();
        void genMove(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile);
        void setStatus();
        bool getStatus();
        void print() override;
};

#endif
