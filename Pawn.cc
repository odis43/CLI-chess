#include "Piece.h"
#include "Pawn.h"

using namespace std;

Pawn::Pawn(string colour):Piece{colour, 1},isPromoted{false},hasTwoStepped{false} {}
Pawn::~Pawn(){}

void Pawn::genMoves(vector<vector<Tile*>> board, Tile *tile, int row, int col) {
    //for two step
    if(getNotMoved() == true) {
        int newRow = row + 2;
        if(getColour() == "white") {
            newRow = row - 2;
        }

        if(newRow < 8 && newRow >= 0) {
            Piece *tilePiece = board[newRow][col]->getPiece();
            if(tilePiece == nullptr) {
                updateValidMoves(board[newRow][col],4);
            }
        }
    } 

    int newRow = row + 1;
    if(getColour() == "white") {
        newRow = row - 1;
    }

    if(row - 1 >= 0 && row + 1 < 8){
        Piece *tilePiece = board[newRow][col]->getPiece();
        if(tilePiece == nullptr) {
            updateValidMoves(board[newRow][col], 1);
        }
        int newColLeft = col - 1;
        int newColRight = col + 1;

        if(newColLeft >= 0) {
            Piece *tilePieceTwo = board[newRow][newColLeft]->getPiece();
            if(tilePieceTwo != nullptr && tilePieceTwo->getColour() != this->getColour()){
                updateValidMoves(board[newRow][newColLeft],2);
            }
        }

        if(newColRight < 8) {
            Piece *tilePieceThree = board[newRow][newColRight]->getPiece();
            if(tilePieceThree != nullptr && tilePieceThree->getColour() != this->getColour()){
                updateValidMoves(board[newRow][newColRight], 2);
            }
        }
    }
}

bool Pawn::getStatus() {
    return hasTwoStepped;
}

void Pawn::setStatus() {
    hasTwoStepped = !hasTwoStepped;
}

void Pawn::castlingStatus(){}

bool Pawn::getCastlingStatus(){return false;}



void Pawn::print() {
    if(this->getColour() == "black"){
        cout << "p";
    } else {
        cout << "P";
    }
}


void Pawn::promoteStatus(){
    isPromoted = !isPromoted;
}
bool Pawn::getPromoteStatus(){
    return isPromoted;
}


