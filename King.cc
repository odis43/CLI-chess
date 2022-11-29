#include "King.h"
#include "Tile.h"
#include "Board.h"
using namespace std;

King::King(string colour): Piece{colour, 10}{}

King::~King(){}

void King::print(){
    if (getColour() == "white"){
        cout << "K";
    } else {
        cout << "k";
    }
}

void King::genMoves(vector<vector<Tile*>> board, Tile *tile, int row, int col){
    vector<Tile*> possibleMoves;
    if (row < 7) { // Check top row
        possibleMoves.emplace_back(board[row + 1][col]);
        if (col < 7) {
            possibleMoves.emplace_back(board[row + 1][col + 1]);
        }
        if (col <= 1) {
            possibleMoves.emplace_back(board[row + 1][col - 1]);
        }
    }

    if (row >= 1) { // Check bottom row
        possibleMoves.emplace_back(board[row - 1][col]);
        if (col < 7) {
            possibleMoves.emplace_back(board[row - 1][col + 1]);
        }
        if (col <= 1) {
            possibleMoves.emplace_back(board[row - 1][col - 1]);
        }
    }

    if (col < 7) { // Check right side
        possibleMoves.emplace_back(board[row][col + 1]);
    }

    if (col <= 1) { // Check left side
        possibleMoves.emplace_back(board[row][col - 1]);
    }

    for (auto move:possibleMoves) {
        Piece *tilePiece = move->getPiece();
        string theColour = getColour();
        if (tilePiece) {
            if (tilePiece->getColour() != theColour) {
                if (theColour == "white") {
                    if (move->getThreats("black") == 0) {
                        updateValidMoves(move, 2);
                    }
                } else {
                    if (move->getThreats("white") == 0) {
                        updateValidMoves(move, 2);
                    }                   
                }
            } else {
                if (theColour == "white") {
                    if (move->getThreats("black") == 0) {
                        updateValidMoves(move, 3);
                    }                   
                } else {
                    if (move->getThreats("white") == 0) {
                        updateValidMoves(move, 3);
                    }                   
                }
            }
        } else {
            if (theColour == "white") {
                if (move->getThreats("black") == 0) {
                    updateValidMoves(move, 1);
                }
            } else {
                if (move->getThreats("white") == 0) {
                     updateValidMoves(move, 1);
                }                   
            }
        }
    }
    // Castling
    vector<vector<Tile*>> board = getBoard()->getBoardRef();
    if (getNotMoved()) {
        if (getColour() == "white") {
            
        } else {
            
        }
    }
}
