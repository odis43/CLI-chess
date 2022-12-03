#include "Bishop.h"
#include "Tile.h"
using namespace std;

Bishop::Bishop(string colour): Piece{colour, 4}{}

Bishop::~Bishop(){}

void Bishop::print(){
    if (getColour() == "white"){
        cout << "B";
    } else {
        cout << "b";
    }
}

void Bishop::genMoves(vector<vector<Tile*>> board, Tile *tile, int row, int col){
    // Moving Diagonally North-East
    int i = row - 1;
    int j = col + 1;
    while (i >= 0 && i < 8 && j >= 0 && j < 8) {
        Piece *tilePiece = board[i][j]->getPiece();
        if (tilePiece) {
            // Path is blocked
            if (tilePiece->getColour() == this->getColour()){
                updateValidMoves(board[i][j], 3);
                break;
            } else { // Can capture
                updateValidMoves(board[i][j], 2);
                break;
            }
        } else {
            updateValidMoves(board[i][j], 1);
            i--;
            j++;
        }      
    }

    // Moving Diagonally North-West
    i = row - 1;
    j = col - 1;
    while (i >= 0 && i < 8 && j >= 0 && j < 8) {
        Piece *tilePiece = board[i][j]->getPiece();
        if (tilePiece) {
            // Path is blocked
            if (tilePiece->getColour() == this->getColour()){
                updateValidMoves(board[i][j], 3);
                break;
            } else { // Can capture
                updateValidMoves(board[i][j], 2);
                break;
            }
        } else {
            updateValidMoves(board[i][j], 1);
            i--;
            j--;
        }      
    }

    // Moving Diagonally South-East
    i = row + 1;
    j = col + 1;
    while (i >= 0 && i < 8 && j >= 0 && j < 8) {
        Piece *tilePiece = board[i][j]->getPiece();
        if (tilePiece) {
            // Path is blocked
            if (tilePiece->getColour() == this->getColour()){
                updateValidMoves(board[i][j], 3);
                break;
            } else { // Can capture
                updateValidMoves(board[i][j], 2);
                break;
            }
        } else {
            updateValidMoves(board[i][j], 1);
            i++;
            j++;
        }      
    }

    // Moving Diagonally South-West
    i = row + 1;
    j = col - 1;
    while (i >= 0 && i < 8 && j >= 0 && j < 8) {
        Piece *tilePiece = board[i][j]->getPiece();
        if (tilePiece) {
            // Path is blocked
            if (tilePiece->getColour() == this->getColour()){
                updateValidMoves(board[i][j], 3);
                break;
            } else { // Can capture
                updateValidMoves(board[i][j], 2);
                break;
            }
        } else {
            updateValidMoves(board[i][j], 1);
            i++;
            j--;
        }     
    } 
}

void Bishop::castlingStatus(){}
bool Bishop::getCastlingStatus() { return false; }