#include "Tile.h"

#ifndef CELL
#define CELL

#include <map>
#include <vector>

//threats not yet added in interface or implemented elsewhere 

using namespace std;
Tile::Tile(int row, int col):row{row},col{col},piece{nullptr},status{-1},numThreats{map<string, int>()}{}

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

int Tile::getThreats(string p) {
    if(numThreats.count(p)) {
        return numThreats.at(p); //if there is a key for a threat (a color, white or black)
    } else {
        return 0; //no threats for this piece 
    } 
}
void Tile::notify() {
    //implementation to notify all pieces of cell changes
    if(!piece) {
        status = 0;
    }

    if(piece->getColour() == "black") {
        status = 1;
    }

    if(piece->getColour() == "white"){
        status = 2;
    }

    numThreats.clear();
    for(auto piece: pieces) {
        if(piece->getVal() == 1 && piece->getColour == "black"){
            if (piece->getTile()->getRow() == this->row - 1 && piece->getTile()->getCol() == this->col - 1 || piece->getTile()->getCol() == col + 1) {
                if(numThreats.count(1)) numThreats[1]++;
                else numThreats[1] = 1;
            }
        }

        if(piece->getVal() == 1 && piece->getColour == "white"){
            if (piece->getTile()->getRow() == this->row + 1 && piece->getTile()->getCol() == this->col - 1 || piece->getTile()->getCol() == col + 1) {
                if(numThreats.count(0)) numThreats[0]++;
                else numThreats[0] = 0;
            }
        }

        if(piece->isValidMove(this)) {
            int curr = piece->getColour();

            if(numThreats.count(curr)) numThreats[curr]++;
            else numThreats[curr] = 1;
        }
        
    }
}

Piece* Tile::getPiece() {
    return this->piece;
}

