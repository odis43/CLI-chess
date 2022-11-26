#ifndef CELL
#define CELL

#include <map>
#include <vector>


class Piece;

class Tile: public Observer {
    Piece *piece;
    int row, col, status;
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
    void notify();
};

#endif