#include <vector>
#include <iterator>
#include <map>
#include "Piece.h"
#include "Board.h"
#include "Tile.h"
using namespace std;

Piece::Piece(string colour, int val): tile{nullptr}, colour{colour}, tracker{-1}, notMoved{true}, val{val}, validMoves{map<Tile*, int>()}, theBoard{nullptr}{}

Piece::~Piece(){
    if (theBoard) {
        vector<vector<Tile*>> theTiles = theBoard->getBoardRef();
        for (auto theRow:theTiles) {
            for (auto theCell:theRow) {
                this->detach(theCell);
            }
        }
    }
    this->detach(theBoard);
}

void Piece::setTile(Tile *t){
    tile = t;
}

Tile* Piece::getTile(){
    return tile;
}

void Piece::setBoard(Board* board){
    theBoard = board;
    vector<vector<Tile*>> theTiles = theBoard->getBoardRef();
    for (auto theRow:theTiles) {
        for (auto theTile:theRow) {
            this->attach(theTile);
        }
    }
    this->attach(theBoard);
}

void Piece::printThePiece(){
    print();
}

Board* Piece::getBoard() {
    return theBoard;
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
    this->notMoved = b;
}

bool Piece::getNotMoved(){
    return this->notMoved;
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

Tile* Piece::getRandomMove(){
    auto it = validMoves.begin();
    do {
        auto it = validMoves.begin();
        advance(it, rand() % validMoves.size());
    } while (it->second == 3); //if the move is 3, path is blocked

    Tile* randomMove = it->first;
    return randomMove;
}

Tile* Piece::getCapture(){
    for (auto theMove:validMoves) {
        if (theMove.second == 2) {
            return theMove.first;
        }
    }
    return nullptr;
}

Tile* Piece::getCheck(){
    for(auto theMove:validMoves){
        if (theMove.second == -1) {
            return theMove.first;
        }
    }
    return nullptr;
}

bool Piece::getStatus() {
    return false;
}

void Piece::createUniqueStatus() {
    castlingStatus();
}
bool Piece::receiveUniqueStatus() {
    return getCastlingStatus();
}

void Piece::notifyObservers(){
    vector<vector<Tile*>> tiles = theBoard->getBoardRef();
    for (auto theRow:tiles) {
        for (auto theTile:theRow) {
            theTile->notify();
        }
    }
    theBoard->notify();
}
