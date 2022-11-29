#ifndef PAWN
#define PAWN

#include "Tile.h"
class Pawn : public Piece {
    bool isPromoted;
    bool hasTwoStepped;
    public:
        Pawn(string std::color);
        ~Pawn();
        void genMove(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile);
        void setStatus();
        bool getStatus();
};

#endif
