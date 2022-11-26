#ifndef KNIGHT
#define KNIGHT

//#include "Piece.h"

class Knight : public Piece {
    bool isPromoted;
    public:
        Knight(int color);
        ~Knight();
        void genMove(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile);
        void uniqStat();
        bool currUniqStat();
};

#endif
