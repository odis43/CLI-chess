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

int Piece::getTracker(){
    return this->tracker;
}

void Piece::setTracker(int num){
    tracker = num;
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

void Piece::setNotMoved(bool b){
    notMoved = b;
}

bool Piece::getNotMoved(){
    return notMoved;
}

map<Tile*, int> Piece::getValidMoves(){
    return this->validMoves;
}

void Piece::createValidMoves(){
    validMoves.clear();
    vector<vector<Tile*>> curBoard = getBoard()->getBoardRef();
    Tile *curTile = getTile();
    int curRow = curTile->getRow();
    int curCol = curTile->getCol();
    genMoves(curBoard, curTile, curRow, curCol);
}

void Piece::updateValidMoves(Tile *tile, int num){
    validMoves[tile] = num;
}

void Piece::createUniqueStatus() {
    uniqueStatus();
}
bool Piece::receiveUniqueStatus() {
    return getUniqueStatus();
}

