#include <vector>
#include <iterator>
#include <map>
#include "Piece.h"
#include "Board.h"
#include "Tile.h"
using namespace std;

Piece::Piece(string colour, int val): tile{nullptr}, colour{colour}, val{val}, validMoves{map<Tile*, int>()}, board{nullptr}{}

Piece::~Piece(){

}

void Piece::setTile(Tile *t){
    this->tile = t;
}

Tile* Piece::getTile(){
    return this->tile;
}

string Piece::getColour(){
    return this->colour;
}

int Piece::getVal(){
    return this->val;
}

int Piece::isValidMove(Tile *tile){
    if (validMoves.count(tile)) {
        return validMoves.at(tile);
    } else {
        return 0;
    }
}

map<Tile*, int> Piece::getValidMoves(){
    return this->validMoves;
}
