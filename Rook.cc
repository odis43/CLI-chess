#include "Rook.h"
#include "Tile.h"

using namespace std;

Rook::Rook(string colour):Piece{colour, 5}, {}

Rook::~Rook(){}

void Rook::print() {
    if(getColour() == "white") cout << "R";
    if(getColour() == "black") cout << "r";
}

 void moveUp(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile) {
    int newRow = row + 1;
    while(newRow < 8) {
        Piece *tilePiece = board[newRow][col]->getPiece();
        if(tilePiece) {
            if(tilePiece ->getColour() == getColour()) {
                updateValidMove(board[newRow][col],3);
                break;
            } else {
                updateValidMove(board[newRow][col],2);
                break;
            }
        } else {
            updateValidMove(board[newRow][col], 1)
            newRow++;
        }
    }
 }

 void moveDown(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile) {
    int newRow = row - 1;
    while(newRow >= 0) {
        Piece *tilePiece = board[newRow][col]->getPiece();
        if(tilePiece) {
            if(tilePiece ->getColour() == getColour()) {
                updateValidMove(board[newRow][col],3);
                break;
            } else {
                updateValidMove(board[newRow][col],2);
                break;
            }
        } else {
            updateValidMove(board[newRow][col], 1)
            newRow--;
        }
    }
 }

 void moveRight(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile) {
    int newCol = col + 1;
    while(newCol < 8) {
        Piece *tilePiece = board[row][newCol]->getPiece();
        if(tilePiece) {
            if(tilePiece ->getColour() == getColour()) {
                updateValidMove(board[row][newCol],3);
                break;
            } else {
                updateValidMove(board[row][newCol],2);
                break;
            }
        } else {
            updateValidMove(board[row][newCol], 1)
            newCol++;
        }
    }
 }

 void moveRight(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile) {
    int newCol = col - 1;
    while(newCol >= 0) {
        Piece *tilePiece = board[row][newCol]->getPiece();
        if(tilePiece) {
            if(tilePiece ->getColour() == getColour()) {
                updateValidMove(board[row][newCol],3);
                break;
            } else {
                updateValidMove(board[row][newCol],2);
                break;
            }
        } else {
            updateValidMove(board[row][newCol], 1)
            newCol--;
        }
    }
 }

void genMove(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile) {
    moveUp(row, col, board, tile);
    moveDown(row, col, board, tile);
    moveLeft(row, col, board, tile);
    moveRight(row, col, board, tile);
}
