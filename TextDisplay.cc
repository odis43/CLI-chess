#include <iostream>
#include "TextDisplay.h"
#include "Piece.h"
#include "Tile.h"

using namespace std;

// Constructor
TextDisplay::TextDisplay(Board *board) : board{board} {}

// Print board
void TextDisplay::printBoard() {
    vector<vector<Tile *>> chessBoard = board->getBoardRef();
}

