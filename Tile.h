#ifndef TILE
#define TILE

#include <map>
#include <vector>
#include "Piece.h"


class Piece;

class Tile: public Observer {
    int row, col;
    Piece *piece;
    int status;
    std::map<string, int> numThreats;
    std::vector<Piece*> pieces;
public:
    Tile(int row, int col);
    ~Tile();
    void set(Piece *piece);
    void remove();
    void setAll(std::vector<Piece *> pieces);
    int getStat();
    int getRow();
    int getCol();
    int getThreats(std::string p);
    void notify();
    Piece *getPiece(); //return piece
};

#endif
