#include "Knight.h"


using namespace std;

Knight::Knight(string colour):Piece{colour,3}{}

Knight::~Knight(){}

void Knight::genMoves(std::vector<std::vector<Tile*>> board, Tile *tile, int row, int col) {
    vector <Tile*> possibleMove;
    if(row - 1 >= 0) {
        if(col - 2 >= 0) {
            possibleMove.push_back(board[row - 1][col - 2]);
        }

        if(col + 2 < 8) {
             possibleMove.push_back(board[row - 1][col + 2]);
        }

        if(row - 2 >= 0) {
            if(col - 1 >= 0) {
                possibleMove.push_back(board[row - 2][col - 1]);
            }

            if(col + 1 < 8) {
                possibleMove.push_back(board[row - 2][col + 1]);
            }
        }
    }

    if(row + 1 < 8) {
        if(row + 2 < 8) {
            if(col + 1 < 8) {
                possibleMove.push_back(board[row + 2][col + 1]);
            }

            if(col - 1 >= 0) {
                possibleMove.push_back(board[row + 2][col - 1]);
            }
        }

        if(col + 2 < 8) {
            possibleMove.push_back(board[row + 1][col + 2]);
        }

        if(col - 2 >= 0) {
            possibleMove.push_back(board[row + 1][col - 2]);
        }
    }

    for(auto move : possibleMove) {
        Piece *tilePiece = move->getPiece();
        if(tilePiece) {
            if(tilePiece->getColour() != getColour()) {
                updateValidMoves(move,2);
            } else {
                updateValidMoves(move, 3);
            }
        } else {
            updateValidMoves(move, 1);
        }
    }
}

void Knight::print() {
    if(getColour() == "white") cout << "N";
    if(getColour() == "black") cout << "n";
}


void Knight::castlingStatus(){}
bool Knight::getCastlingStatus() { return false; }



void Knight::promoteStatus(){}
bool Knight::getPromoteStatus() { return false; }


