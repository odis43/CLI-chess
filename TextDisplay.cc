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
    cout << " ";
    cout << endl;
    for (int i = 0; i < 8; i++) {
        cout << "  "; // place some padding
        for (int j = 0; j < 8; j++) {
            cout << "-----";
        }
        cout << endl;
        cout << 8 - i << " "; // print row number
        for (int j = 0; j < 8; j++) {
            auto boardTile = chessBoard[i][j];
            cout << "| ";
            if (boardTile->getPiece()) {
                boardTile->getPiece()->printThePiece();
            } else {
                cout << " ";
            }
            cout << " |";
        }
        cout << endl;
    }
    cout << "  "; // add some more padding
    for (int i = 0; i < 8; i++) {
        cout << "-----";
    }
    cout << endl;
    for (int i = 0; i < 8; i++) { // print out column headers
        char character = i + 97;
        cout << "    " << character;
    }
    cout << endl;
}

