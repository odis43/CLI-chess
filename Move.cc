#include <iostream>
#include "Move.h"
#include "Piece.h"
#include "Tile.h"

using namespace std;

// Constructor
Move::Move(Piece *lastPiece, Piece *currentPiece, Tile *initialTile, Tile *destinationTile, int turn) : lastPiece{lastPiece}, currentPiece{currentPiece}, initialTile{initialTile}, destinationTile{destinationTile}, turn{turn} {}

// Destructor
Move::~Move() {}

// Get lastPiece
Piece *Move::getLastPiece() { return lastPiece; }

// Get currentPiece
Piece *Move::getCurrentPiece() { return currentPiece; }

// Get initialTile
Tile *Move::getInitialTile() { return initialTile; }

// Get destinationTile
Tile *Move::getDestinationTile() { return destinationTile; }

// Get turn
int Move::getTurn() { return turn; }

// Prints move object info
void Move::print() {
    cout << endl;
    cout << "Turn: " << turn << endl; // print current turn
    cout << endl;
    cout << "Current Piece: "; // print current piece
    currentPiece->print();
    cout << " " << currentPiece->getVal() << endl; // print relevant value to current piece
    cout << "Old Piece: "; // print current piece
    lastPiece->print();
    cout << " " << lastPiece->getVal() << endl; // print relevant value to current piece
    cout << "Initial Tile: " << initialTile->getRow() << " " << initialTile->getCol() << endl; // print out initialTile info
    cout << "Destination Tile: " << destinationTile->getRow() << " " << destinationTile->getCol() << endl; // print out destinationTile info
    cout << endl;
}

