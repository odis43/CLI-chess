#include "Tile.h"

#ifndef CELL
#define CELL

#include <map>
#include <vector>


class Piece;

//status 0: null, 1: white, 2: black;
class Tile: public Observer {
    int row, col, status;
    Piece *piece;
    std::vector<Piece*> all;
    int status;
    std::map<int,int> numThreats;
public:
    Tile(int row, int col);
    ~Tile();
    void set(Piece *piece);
    void setAll(std::vector<Piece *> pieces);
    void remove();
    int getStat();
    int getRow();
    int getCol();
    int getThreats(int p);
    void notify();
};

#endif

//threats not yet added in interface or implemented elsewhere 

using namespace std;
Tile::Tile(int row, int col):row{row},col{col},piece{nullptr},status{-1},numThreats{map<int, int>()}{}

Tile::Tile(){}

void Tile::set(Piece *piece) {
    this->piece = piece;
}

void Tile::setAll(vector<Piece *> pieces) {
    this->all = pieces;
}

void Tile::remove() {
    this->piece = nullptr;
}

int Tile::getStat() {
    return this->status; //will be added later 
}

int Tile::getRow() {
    return this->row;
}

int Tile::getCol() {
    return this->col;
}

int Tile::getThreats(int p) {
    if(numthreats.count(p)) {
        return numThreats.at(p); //if there is a key for a threat (a color, white or black)
    } else {
        return 0; //no threats for this piece 
    } 
}
void Tile::notify() {
    //implementation to notify all pieces of cell changes
}

