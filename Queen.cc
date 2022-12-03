#include "Queen.h"
#include "Tile.h"
using namespace std;

Queen::Queen(string colour): Piece{colour, 9}{}

Queen::~Queen(){}

void Queen::print(){
    if (getColour() == "white"){
        cout << "Q";
    } else {
        cout << "q";
    }
}

void Queen::genMoves(vector<vector<Tile*>> board, Tile *tile, int row, int col){
    // Moving upward
    for (int i = row + 1; i < 8; i++) {
        Piece *tilePiece = board[i][col]->getPiece();
        if (tilePiece) {
            // Path is blocked
            if (tilePiece->getColour() == this->getColour()){
                updateValidMoves(board[i][col], 3);
                break;
            } else { // Can capture
                updateValidMoves(board[i][col], 2);
                break;
            }
        } else {
            updateValidMoves(board[i][col], 1);
        }
    }

    // Moving downward
    for (int i = row - 1; i >= 0; i--) {
        Piece *tilePiece = board[i][col]->getPiece();
        if (tilePiece) {
            // Path is blocked
            if (tilePiece->getColour() == this->getColour()){
                updateValidMoves(board[i][col], 3);
                break;
            } else { // Can capture
                updateValidMoves(board[i][col], 2);
                break;
            }
        } else {
            updateValidMoves(board[i][col], 1);
        }
    }

    // Moving Right
    for (int i = col + 1; i < 8; i++) {
        Piece *tilePiece = board[row][i]->getPiece();
        if (tilePiece) {
            // Path is blocked
            if (tilePiece->getColour() == this->getColour()){
                updateValidMoves(board[row][i], 3);
                break;
            } else { // Can capture
                updateValidMoves(board[row][i], 2);
                break;
            }
        } else {
            updateValidMoves(board[row][i], 1);
        }
    }

    // Moving Left
    for (int i = col - 1; i >= 0; i++) {
        Piece *tilePiece = board[row][i]->getPiece();
        if (tilePiece) {
            // Path is blocked
            if (tilePiece->getColour() == this->getColour()){
                updateValidMoves(board[row][i], 3);
                break;
            } else { // Can capture
                updateValidMoves(board[row][i], 2);
                break;
            }
        } else {
            updateValidMoves(board[row][i], 1);
        }
    } 

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

void Queen::castlingStatus(){}
bool Queen::getCastlingStatus() { return false; }

